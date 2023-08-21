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
#include <QMap>
#include "editor_plugin_interface.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:


    void initUI();
    void createActions(); // Uniform configuration Actions.
    void showImage(QString);
    void setupShortcuts();

    void loadPlugins();

private:
    QMenu *fileMenu;
    QMenu *viewMenu;
    QMenu *editMenu;

    QToolBar *fileToolBar;
    QToolBar *viewToolBar;
    QToolBar *editToolBar;

    QGraphicsScene *imageScene;
    QGraphicsView *imageView;


    QStatusBar *mainStatusBar;
    QLabel *mainStatusLabel;

    QAction *openAction;
    QAction *saveAsAction;
    QAction *exitAction;
    QAction *zoomInAction;
    QAction *zoomOutAction;
    QAction *prevAction;
    QAction *nextAction;
    QAction *blurAction;

    QGraphicsPixmapItem *currentImage;


    QString currentImagePath;


    QMap<QString, EditorPluginInterface*> editPlugins;

private slots:
    void openImage();
    void zoomIn();
    void zoomOut();
    void saveAs();

    void prevImage();
    void nextImage();

    void blurImage();
    void pluginPerform();



public:
    explicit MainWindow(QWidget *parent=nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
