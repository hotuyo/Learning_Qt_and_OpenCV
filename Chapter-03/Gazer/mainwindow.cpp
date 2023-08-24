#include "mainwindow.h"
#include <QGridLayout>
#include <QGraphicsView>
#include <QMenu>
#include <QMenuBar>
#include <QLabel>
#include <QStatusBar>
#include <QApplication>
#include <QList>
#include <QCameraDevice>
#include <QMediaDevices>
#include <QMessageBox>
#include <QPixmap>
#include <QSettings>
#include <QSize>
#include <QMediaCaptureSession>
#include <QMetaObject>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), fileMenu(nullptr)
{
    initUI();
    data_lock = new QMutex();
}

MainWindow::~MainWindow()
{
}

void MainWindow::initUI()
{
    this->resize(1000, 800);

    fileMenu = menuBar()->addMenu("&File");

    QGridLayout *main_layout = new QGridLayout();

    saved_list = new QListView(this);
    saved_list->setViewMode(QListView::IconMode);
    saved_list->setResizeMode(QListView::Adjust);
    saved_list->setSpacing(5);
    saved_list->setWrapping(false);
    list_model = new QStandardItemModel(this);
    main_layout->addWidget(saved_list, 13, 0, 4, 1);

#ifdef GAZER_USE_QT_CAMERA
    camera = nullptr;
    viewfinder = nullptr;
    if (QSysInfo::productType() == "macos")
    {
        qDebug() << "运行到系统这里";
        QString plistPath = QLatin1String(qApp->applicationDirPath().toUtf8().constData()) + "/../Info.plist";
        QSettings plist(plistPath, QSettings::NativeFormat);
        plist.setValue("NSCameraUsageDescription", "需要访问摄像头以实现 xxx 功能");
        plist.sync();

    }

    const QList<QCameraDevice> cameras = QMediaDevices::videoInputs();
        // I have two cameras and use the second one here
    camera = new QCamera(cameras[1]);
    viewfinder = new QVideoWidget(this);
    main_layout->addWidget(viewfinder, 0, 0, 12, 1);

#else
    imageScene = new QGraphicsScene(this);
    imageView = new QGraphicsView(imageScene);
    main_layout->addWidget(imageView, 0, 0, 12, 1);
#endif


    QGridLayout *tools_layout = new QGridLayout();
    main_layout->addLayout(tools_layout, 12, 0, 1, 1);
    monitorCheckBox = new QCheckBox(this);
    monitorCheckBox->setText("Monitor On/Off");
    tools_layout->addWidget(monitorCheckBox, 0, 0);
    qDebug() << "在这里6" ;
    recordButton = new QPushButton(this);
    recordButton->setText("Record");
    tools_layout->addWidget(recordButton, 0, 1, Qt::AlignHCenter);
    tools_layout->addWidget(new QLabel(this), 0, 2);
    qDebug() << "在这里7";
    saved_list = new QListView(this);
    main_layout->addWidget(saved_list, 13, 0, 4, 1);

    QWidget *widget = new QWidget();
    widget->setLayout(main_layout);
    setCentralWidget(widget);
    qDebug() << "在这里8";
    //setup status bar
    mainStatusBar = statusBar();
    qDebug() << "在这里9";
    mainStatusLabel = new QLabel(mainStatusBar);
    mainStatusBar->addPermanentWidget(mainStatusLabel);
    mainStatusLabel->setText("Gazer is ready");
    qDebug() << "在这里9";

    // test

    if (QSysInfo::productType() == "macos")
    {
        qDebug() << "运行到系统这里";
        QString plistPath = QLatin1String(qApp->applicationDirPath().toUtf8().constData()) + "/../Info.plist";
        QSettings plist(plistPath, QSettings::NativeFormat);
        plist.setValue("NSCameraUsageDescription", "需要访问摄像头以实现 xxx 功能");
        plist.sync();

    }


    //
     qDebug() << "在这里3" ;
    createActions();
    qDebug() << "在这里4";
}

void MainWindow::createActions()
{
    cameraInfoAction = new QAction("Camera Information", this);
    fileMenu->addAction(cameraInfoAction);
    openCameraAction = new QAction("Open camera", this);
    fileMenu->addAction(openCameraAction);
    exitAction = new QAction(this);
    exitAction->setText("AppQuit");
    fileMenu->addAction(exitAction);
    calcFPSAction = new QAction("Calculate FPS", this);
    fileMenu->addAction(calcFPSAction);


    connect(exitAction, SIGNAL(triggered(bool)), QApplication::instance(), SLOT(quit()));
    connect(cameraInfoAction, SIGNAL(triggered(bool)), this, SLOT(showCameraInfo()));
    connect(openCameraAction, SIGNAL(triggered(bool)), this, SLOT(openCamera()));
    connect(monitorCheckBox, SIGNAL(stateChanged(int)), this, SLOT(updateMonitorStatus(int)));
    QMetaObject::Connection connection = connect(calcFPSAction, SIGNAL(triggered(bool)), this, SLOT(calculateFPS()));
    if (connection) {
        // 连接成功
        qDebug() << "连接成功";
    } else {
        // 连接失败
        qDebug() << "连接失败";
    }

}

void MainWindow::showCameraInfo()
{
    QList<QCameraDevice> cameras = QMediaDevices::videoInputs();    // 这里和教材不同
    QString info = QString("Available Cameras: \n");

    foreach(const QCameraDevice &cameraInfo, cameras){
        info += "-" + cameraInfo.id() + ":";
        info += cameraInfo.description();
        info += "\n";
    }
    QMessageBox::information(this, "Cameras", info);
}
#ifdef GAZER_USE_QT_CAMERA
void MainWindow::openCamera()
{
//    camera->setCaptureMode(QCamera::CaptureVideo);
    session = nullptr;
    session = new QMediaCaptureSession(this);
    session->setCamera(camera);
    session->setVideoOutput(viewfinder);
    camera->start();
}
#else
void MainWindow::openCamera()
{
    if (capturer != nullptr)
    {
        qDebug() << "155这里\n";
        capturer->setRunning(false);
        disconnect(capturer, &CaptureThread::frameCaptured, this, &MainWindow::updateFrame);
        disconnect(capturer, &CaptureThread::fpsChanged, this, &MainWindow::updateFPS);
        disconnect(capturer, &CaptureThread::videoSaved, this, &MainWindow::appendSavedVideo);
        connect(capturer, &CaptureThread::finished, capturer, &CaptureThread::deleteLater);

    }

    int camID = 1;
    capturer =new CaptureThread(camID, data_lock);
    connect(capturer, &CaptureThread::frameCaptured, this, &MainWindow::updateFrame);
    qDebug() << "164这里\n";
    connect(capturer, &CaptureThread::fpsChanged, this, &MainWindow::updateFPS);
    qDebug() << "166这里\n";
    capturer->start();
    mainStatusLabel->setText(QString("Capturing Camera %1").arg(camID));
    connect(recordButton, SIGNAL(clicked(bool)), this, SLOT(recordingStartStop()));
    connect(capturer, &CaptureThread::videoSaved, this, &MainWindow::appendSavedVideo);
}
#endif

void MainWindow::updateFrame(cv::Mat *mat)
{
    data_lock->lock();
    currentFrame = *mat;
    data_lock->unlock();

    QImage frame(
        currentFrame.data,
        currentFrame.cols,
        currentFrame.rows,
        currentFrame.step,
        QImage::Format_RGB888);
    QPixmap image = QPixmap::fromImage(frame);

    imageScene->clear();
    imageView->resetTransform();
    imageScene->addPixmap(image);
    imageScene->update();
    imageView->fitInView(imageScene->sceneRect(), Qt::KeepAspectRatio);
//    imageView->setSceneRect(image.rect());
}

void MainWindow::calculateFPS()
{
    qDebug() << "calculateFPS 197";
    if(capturer != nullptr)
    {
        capturer->startCalcFPS();
    }
}

void MainWindow::updateFPS(float fps)
{
    qDebug() << "计算 updateFPS 啦";
    mainStatusLabel->setText(QString("FPS of current camera is %1").arg(fps));
}

void MainWindow::recordingStartStop()
{
    QString text = recordButton->text();
    if(text == "Record" && capturer != nullptr)
    {
        capturer->setVideoSavingStatus(CaptureThread::STARTING);
        recordButton->setText("Stop Recording");
    }
    else if(text == "Stop Recording" && capturer != nullptr)
    {
        capturer->setVideoSavingStatus(CaptureThread::STOPPING);
        recordButton->setText("Record");
    }
}

void MainWindow::appendSavedVideo(QString name)
{
    QString cover = Utilities::getSavedVideoPath(name, "jpg");
    QStandardItem *item = new QStandardItem();
    list_model->appendRow(item);
    QModelIndex index = list_model->indexFromItem(item);
    list_model->setData(index, QPixmap(cover).scaledToHeight(145), Qt::DecorationRole);
    list_model->setData(index, name, Qt::DisplayRole);
    saved_list->scrollTo(index);
}

void MainWindow::updateMonitorStatus(int status)
{
    if(capturer == nullptr)
    {
        return;
    }
    if(status)
    {
        capturer->setMotionDetectingStatus(true);
        recordButton->setEnabled(false);
    }
    else
    {
        capturer->setMotionDetectingStatus(false);
        recordButton->setEnabled(true);
    }
}
