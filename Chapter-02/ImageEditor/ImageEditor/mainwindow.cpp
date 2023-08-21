#include <QApplication>
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QKeyEvent>
#include <QDebug>
#include <QPluginLoader>

#include "opencv2/opencv.hpp"

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), fileMenu(nullptr), viewMenu(nullptr)
{

    initUI();
    loadPlugins();

}

MainWindow::~MainWindow()
{
}

void MainWindow::initUI()
{
    this->resize(800, 600);
   // accelerator key. The accelerator key allows the user to perform menu item actions using the keyboard instead of the mouse.
    fileMenu = menuBar()->addMenu("File");
    viewMenu = menuBar()->addMenu("View");

    fileToolBar = addToolBar("File");
    viewToolBar = addToolBar("View");

    // setup Edit Menu
    editMenu = menuBar()->addMenu("Edit");
    editToolBar = addToolBar("Edit");

    imageScene = new QGraphicsScene(this);
    imageView = new QGraphicsView(imageScene);
    setCentralWidget(imageView);


    mainStatusBar = new QStatusBar(this);
    setStatusBar(mainStatusBar);

    mainStatusLabel = new QLabel(this);
    mainStatusBar->addPermanentWidget(mainStatusLabel);
    mainStatusLabel->setText("Image Infomation will be here!");

    createActions();
}

void MainWindow::createActions()
{

    openAction = new QAction("Open", this);
    fileMenu->addAction(openAction);

    saveAsAction = new QAction("Save as", this);
    fileMenu->addAction(saveAsAction);

    exitAction = new QAction("!Exit", this); //  Why do “quit” and “exit” have a bug that prevents them from displaying correctly?
    fileMenu->addAction(exitAction);         // I am crazy.

    zoomInAction = new QAction("Zoom in", this);
    viewMenu->addAction(zoomInAction);

    zoomOutAction = new QAction("Zoom Out", this);
    viewMenu->addAction(zoomOutAction);

    prevAction = new QAction("Previous Image", this);
    viewMenu->addAction(prevAction);

    nextAction = new QAction("Next Image", this);
    viewMenu->addAction(nextAction);

    blurAction = new QAction("Blur", this);
    editMenu->addAction(blurAction);
    editToolBar->addAction(blurAction);

    // add actions to toolbars

    fileToolBar->addAction(openAction);
    fileToolBar->addAction(saveAsAction);

    viewToolBar->addAction(zoomInAction);
    viewToolBar->addAction(zoomOutAction);
    viewToolBar->addAction(prevAction);
    viewToolBar->addAction(nextAction);




    // connect the signals and slots
    connect(exitAction, SIGNAL(triggered(bool)), QApplication::instance(), SLOT(quit()));
    connect(openAction, SIGNAL(triggered(bool)), this, SLOT(openImage()));

    connect(zoomInAction, SIGNAL(triggered(bool)), this, SLOT(zoomIn()));
    connect(zoomOutAction, SIGNAL(triggered(bool)), this, SLOT(zoomOut()));

    connect(saveAsAction, SIGNAL(triggered(bool)), this, SLOT(saveAs()));

    connect(prevAction, SIGNAL(triggered(bool)), this, SLOT(prevImage()));

    connect(nextAction, SIGNAL(triggered(bool)), this, SLOT(nextImage()));

    connect(blurAction, SIGNAL(triggered(bool)), this, SLOT(blurImage()));

    // Set shortcuts.
    setupShortcuts();
}

void MainWindow::openImage()
{
    qDebug() << "slots openImage is called";
    QFileDialog dialog(this);
    dialog.setWindowTitle("Open Image");
    dialog.setFileMode(QFileDialog::ExistingFile); // 0.QFileDialog::AnyFile
                                                   // 1.QFileDialog::ExistingFile
                                                   // 2.QFileDialog::Directory
                                                   // 3.QFileDialog::ExistingFiles
    dialog.setNameFilter(tr("Images (*.png *.bmp *.jpg)"));
    QStringList filePaths;
    if (dialog.exec())
    {
        filePaths = dialog.selectedFiles();
        showImage(filePaths.at(0));
    }
}

void MainWindow::showImage(QString path)
{
    imageScene->clear();
    //    imageView->resetMatrix(); Warning: This function has been removed in Qt 6.
    imageView->resetTransform();
    QPixmap image(path);
    //    imageScene->addPixmap(image);
    currentImage = imageScene->addPixmap(image);

    imageScene->update(); // Sometimes, in certain specific situations,
                          // there might be a delay in image rendering or a forced refresh is required after specific operations.
    imageView->setSceneRect(image.rect());
    QString status = QString("%1, %2x%3, %4 Bytes")
                         .arg(path)
                         .arg(image.width())
                         .arg(image.height())
                         .arg(QFile(path).size());
    mainStatusLabel->setText(status);

    currentImagePath = path;
}

void MainWindow::zoomIn()
{
    qDebug("zoomIn clicked");
    imageView->scale(1.2, 1.2);
}

void MainWindow::zoomOut()
{
    qDebug("zoomOut clicked");
    imageView->scale(1 / 1.2, 1 / 1.2);
}

void MainWindow::saveAs()
{
    if (currentImage == nullptr)
    {
        QMessageBox::information(this, "Information", "Nothing to save");
        return;
    }
    QFileDialog dialog(this);
    dialog.setWindowTitle("Save Image As...");
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    dialog.setNameFilter(tr("Images (*.png *.bmp *.jpg)"));
    QStringList fileNames;
    if (dialog.exec())
    {
        fileNames = dialog.selectedFiles();
        QRegularExpression regex(".+\\.(png|bmp|jpg)");
        if (regex.match(fileNames.at(0)).hasMatch())
        {
            currentImage->pixmap().save(fileNames.at(0));
        }
        else
        {
            QMessageBox::information(this, "Information", "Save error: bad format or filename.");
        }
    }
}

void MainWindow::prevImage()
{
    QFileInfo current(currentImagePath);
    QDir dir = current.absoluteDir();
    QStringList nameFilters;
    nameFilters << "*.png"
                << "*.bmp"
                << "*.jpg";
    QStringList fileNames = dir.entryList(nameFilters, QDir::Files, QDir::Name);

    int idx =
        fileNames.indexOf(QRegularExpression(QRegularExpression::escape(current.fileName())));
    if (idx > 0)
    {
        showImage(dir.absoluteFilePath(fileNames.at(idx - 1)));
    }
    else
    {
        QMessageBox::information(this, "Information", "Current image is the first one.");
    }
}

void MainWindow::nextImage()
{
    QFileInfo current(currentImagePath);
    QDir dir = current.absoluteDir();
    QStringList nameFilters;
    nameFilters << "*.png"
                << "*.bmp"
                << "*.jpg";
    QStringList fileNames = dir.entryList(nameFilters, QDir::Files, QDir::Name);

    int idx =
        fileNames.indexOf(QRegularExpression(QRegularExpression::escape(current.fileName())));
    if (idx < fileNames.size() - 1)
    {
        showImage(dir.absoluteFilePath(fileNames.at(idx + 1)));
    }
    else
    {
        QMessageBox::information(this, "Information", "Current image is the first one.");
    }
}

void MainWindow::setupShortcuts()
{
    QList<QKeySequence> shortcuts;
    shortcuts << Qt::Key_Plus << Qt::Key_Equal;
    zoomInAction->setShortcuts(shortcuts);

    shortcuts.clear();
    shortcuts << Qt::Key_Minus << Qt::Key_Underscore;
    zoomOutAction->setShortcuts(shortcuts);

    shortcuts.clear();
    shortcuts << Qt::Key_Up << Qt::Key_Left;
    prevAction->setShortcuts(shortcuts);

    shortcuts.clear();
    shortcuts << Qt::Key_Down << Qt::Key_Right;
    nextAction->setShortcuts(shortcuts);
}

void MainWindow::blurImage()
{
    if (currentImage == nullptr) {
        QMessageBox::information(this, "Information", "No image to edit.");
        return;
    }
    QPixmap pixmap = currentImage->pixmap();
    QImage image = pixmap.toImage();
    image = image.convertToFormat(QImage::Format_RGB888);
    cv::Mat mat = cv::Mat(
        image.height(),
        image.width(),
        CV_8UC3,
        image.bits(),
        image.bytesPerLine());

    cv::Mat tmp;
    cv::blur(mat, tmp, cv::Size(8, 8));
    mat = tmp;

    QImage image_blurred(
        mat.data,
        mat.cols,
        mat.rows,
        mat.step,
        QImage::Format_RGB888);
    pixmap = QPixmap::fromImage(image_blurred);
    imageScene->clear();
    imageView->resetTransform();
    currentImage = imageScene->addPixmap(pixmap);
    imageScene->update();
    imageView->setSceneRect(pixmap.rect());
    QString status = QString("(editted image), %1x%2")
                         .arg(pixmap.width()).arg(pixmap.height());
    mainStatusLabel->setText(status);
}


void MainWindow::loadPlugins()
{
    QDir pluginsDir(QApplication::instance()->applicationDirPath() + "/plugins");
    QStringList nameFilters;
    nameFilters << "*.so" << "*.dylib" << "*.dll";
    QFileInfoList plugins = pluginsDir.entryInfoList(
        nameFilters, QDir::NoDotAndDotDot | QDir::Files, QDir::Name);

    foreach(QFileInfo pluginInfo, plugins) {
        qDebug() << "Loading plugin: " << pluginInfo.fileName(); // 显示正在加载的插件文件名
        QPluginLoader pluginLoader(pluginInfo.absoluteFilePath());

        if (QObject *pluginInstance = pluginLoader.instance()) {
            EditorPluginInterface *pluginPtr = qobject_cast<EditorPluginInterface*>(pluginInstance);
            if (pluginPtr) {
                QAction *action = new QAction(pluginPtr->name(), this);
                editMenu->addAction(action);
                editToolBar->addAction(action);
                editPlugins[pluginPtr->name()] = pluginPtr;
                connect(action, &QAction::triggered, this, &MainWindow::pluginPerform);
                // pluginLoader.unload(); // 加载完成后不需要手动卸载
            } else {
                qDebug() << "Bad plugin interface: " << pluginInfo.fileName();
                pluginLoader.unload(); // 插件接口无效时卸载插件
            }
        } else {
            qDebug() << "Failed to load plugin: " << pluginInfo.fileName() << " Error: " << pluginLoader.errorString();
        }
    }
}



void MainWindow::pluginPerform()
{
    qDebug() << "插件执行";
    if (currentImage == nullptr)
    {
        QMessageBox::information(this, "Information", "No image to edit.");
        return;
    }
    QAction *active_action = qobject_cast<QAction*>(sender());
    EditorPluginInterface *plugin_ptr = editPlugins[active_action->text()];
    if(!plugin_ptr)
    {
        QMessageBox::information(this, "Information", "No plugin is found");
        return;
    }

    QPixmap pixmap = currentImage->pixmap();
    QImage image = pixmap.toImage();
    image = image.convertToFormat(QImage::Format_RGB888);
    cv::Mat mat = cv::Mat(
        image.height(),
        image.width(),
        CV_8UC3,
        image.bits(),
        image.bytesPerLine());

    plugin_ptr->edit(mat, mat);

    QImage image_edited(
        mat.data,
        mat.cols,
        mat.rows,
        mat.step,
        QImage::Format_RGB888);
    pixmap = QPixmap::fromImage(image_edited);
    imageScene->clear();
    imageView->resetTransform();
    currentImage = imageScene->addPixmap(pixmap);
    imageScene->update();
    imageView->setSceneRect(pixmap.rect());
    QString status = QString("(editted image), %1x%2").arg(pixmap.width()).arg(pixmap.height());
    mainStatusLabel->setText(status);
}

























