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

    imageScene = new QGraphicsScene(this);
    imageView = new QGraphicsView(imageScene);
    main_layout->addWidget(imageView, 0, 0, 12, 1);

    QGridLayout *tools_layout = new QGridLayout();
    main_layout->addLayout(tools_layout, 12, 0, 1, 1);
    tools_layout->addWidget(new QLabel(this), 0, 2);
    saved_list = new QListView(this);
    main_layout->addWidget(saved_list, 13, 0, 4, 1);

    QWidget *widget = new QWidget();
    widget->setLayout(main_layout);
    setCentralWidget(widget);

    shutterButton = new QPushButton(this);
    shutterButton->setText("Take a photo");
    tools_layout->addWidget(shutterButton, 0, 0, Qt::AlignHCenter);

    //setup status bar
    mainStatusBar = statusBar();

    mainStatusLabel = new QLabel(mainStatusBar);
    mainStatusBar->addPermanentWidget(mainStatusLabel);
    mainStatusLabel->setText("ready");

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



    connect(exitAction, SIGNAL(triggered(bool)), QApplication::instance(), SLOT(quit()));
    connect(cameraInfoAction, SIGNAL(triggered(bool)), this, SLOT(showCameraInfo()));
    connect(openCameraAction, SIGNAL(triggered(bool)), this, SLOT(openCamera()));
    connect(shutterButton, SIGNAL(clicked(bool)), this, SLOT(takePhoto()));


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

void MainWindow::openCamera()
{
    if (capturer != nullptr)
    {
        qDebug() << "155这里\n";
        capturer->setRunning(false);
        disconnect(capturer, &CaptureThread::frameCaptured, this, &MainWindow::updateFrame);
        disconnect(capturer, &CaptureThread::photoTaken, this, &MainWindow::appendSavedPhoto);
        connect(capturer, &CaptureThread::finished, capturer, &CaptureThread::deleteLater);
    }

    int camID = 1;
    capturer =new CaptureThread(camID, data_lock);
    connect(capturer, &CaptureThread::frameCaptured, this, &MainWindow::updateFrame);
    connect(capturer, &CaptureThread::photoTaken, this, &MainWindow::appendSavedPhoto);
    capturer->start();
    mainStatusLabel->setText(QString("Capturing Camera %1").arg(camID));

}

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

void MainWindow::populateSavedList()
{
    // TODO
}

void MainWindow::appendSavedPhoto(QString name)
{
    QString photo_path = Utilities::getPhotoPath(name, "jpg");
    QStandardItem *item = new QStandardItem();
    list_model->appendRow(item);
    QModelIndex index = list_model->indexFromItem(item);
    list_model->setData(index, QPixmap(photo_path).scaledToHeight(145), Qt::DecorationRole);
    list_model->setData(index, name, Qt::DisplayRole);
    saved_list->scrollTo(index);
}

void MainWindow::takePhoto()
{
    if(capturer != nullptr)
    {
        capturer->takePhoto();
    }
}
