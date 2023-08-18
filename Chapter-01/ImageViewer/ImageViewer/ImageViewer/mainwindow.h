#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QAction>
#include <QApplication>
#include <QDebug>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    void initUI();
    void createrActions();  // Uniform configuration Actions.

private:
    QMenuBar *menuBar;

    QMenu *fileMenu;
    QMenu *viewMenu;

    QToolBar *fileToolBar;
    QToolBar *viewToolBar;

    QGraphicsScene *imageScene;
    QGraphicsView *imageView;

    QStatusBar *mainStatusBar;
    QLabel *mainStatusLabel;

private slots:
    void openImage();
//    void zoomIn();
//    void zoomOut();
//    void prevImage();
//    void nextImage();
//    void saveAs();

private:
    QAction *openAction;
    QAction *saveAsAction;
    QAction *exitAction;

    QAction *zoomInAction;
    QAction *zoomOutAction;
    QAction *prevAction;
    QAction *nextAction;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
