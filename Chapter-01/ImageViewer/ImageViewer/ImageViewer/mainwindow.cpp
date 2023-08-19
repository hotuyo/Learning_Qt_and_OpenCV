#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), fileMenu(nullptr), viewMenu(nullptr)
{
    initUI();
}

MainWindow::~MainWindow()
{
}

void MainWindow::initUI()
{
    this->resize(800, 600);
    // setup menubar
    // menuBar() Get the menu bar object of the current main window. This function returns a pointer to type QMenuBar.
    // The menu bar will only be displayed when adding an action on Mac.
    menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    // In Qt, the “&” symbol before the text of a menu item is used to specify the character used for the accelerator key.
    // This is a keyboard shortcut that triggers the menu item when the user presses the key corresponding to the
    // accelerator key.
    // The accelerator key allows the user to perform menu item actions using the keyboard instead of the mouse.
    fileMenu = menuBar->addMenu("File");
    viewMenu = menuBar->addMenu("View");

    // setup toolbar
    // The toolbar will also be displayed only when adding buttons, and an empty toolbar will not be shown.

    fileToolBar = addToolBar("File");
    viewToolBar = addToolBar("View");

    // main area for image display, Create a scene on the current object.
    // Set imageScene as the scene of imageView.

    imageScene = new QGraphicsScene(this);
    imageView = new QGraphicsView(imageScene);
    setCentralWidget(imageView);

    // setup status bar. This code is different from Qt5.
    // The original code is:
    // mainStatusBar = statusBar();
    // mainStatusLabel = new QLabel(mainStatusBar);

    mainStatusBar = new QStatusBar(this);
    setStatusBar(mainStatusBar);

    mainStatusLabel = new QLabel(this);
    mainStatusBar->addPermanentWidget(mainStatusLabel);
    mainStatusLabel->setText("Image Infomation will be here!");

    createrActions();
}

void MainWindow::createrActions()
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
