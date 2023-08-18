#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , fileMenu(nullptr)
    , viewMenu(nullptr)
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
    //accelerator key.
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

    exitAction = new QAction("!Exit", this);  //  Why do “quit” and “exit” have a bug that prevents them from displaying correctly?
    fileMenu->addAction(exitAction);        // I am crazy.


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
//    connect(saveAsAction, SIGNAL(triggered(bool)), this, SLOT(saveAs()));
//    connect(zoomInAction, SIGNAL(triggered(bool)), this, SLOT(zoomIn()));
//    connect(zoomOutAction, SIGNAL(triggered(bool)), this, SLOT(zoomOut()));
//    connect(prevAction, SIGNAL(triggered(bool)), this, SLOT(prevImage()));
//    connect(nextAction, SIGNAL(triggered(bool)), this, SLOT(nextImage()));

    // Set shortcuts.
//    setupShortcuts();
}

void MainWindow::openImage()
{
    qDebug() << "slots openImage is called";
}










