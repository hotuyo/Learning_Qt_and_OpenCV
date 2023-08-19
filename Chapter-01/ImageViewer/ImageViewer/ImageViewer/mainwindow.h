#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QLabel>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QAction>
#include <QApplication>
#include <QDebug>
#include <QFileDialog>
#include <QStringList>
#include <QPixmap>
#include <QMessageBox>
#include <QRegularExpression>
#include <QDir>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    void initUI();
    void createrActions(); // Uniform configuration Actions.
    void showImage(QString path);
    void setupShortcuts();

private:
    QMenuBar *menuBar;

    QMenu *fileMenu;
    QMenu *viewMenu;

    QToolBar *fileToolBar;
    QToolBar *viewToolBar;

    QGraphicsScene *imageScene;
    QGraphicsView *imageView;
    QGraphicsPixmapItem *currentImage;

    QStatusBar *mainStatusBar;
    QLabel *mainStatusLabel;

    QString currentImagePath;

private slots:
    void openImage();
    void zoomIn();
    void zoomOut();
    void saveAs();

    void prevImage();
    void nextImage();

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
