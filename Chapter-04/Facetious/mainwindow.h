#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QGraphicsScene>
#include <QCheckBox>
#include <QPushButton>
#include <QListView>
#include <QLabel.h>
#include <QCamera>
#include <QVideoWidget>
#include <QStandardItemModel>
#include "capturethread.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT


private:

    QMenu *fileMenu;

    QAction *cameraInfoAction;
    QAction *openCameraAction;
    QAction *exitAction;

    QGraphicsScene *imageScene;
    QGraphicsView  *imageView;



    QListView *saved_list;

    QStatusBar *mainStatusBar = nullptr;
    QLabel *mainStatusLabel = nullptr;
    QPushButton *shutterButton;

    cv::Mat currentFrame;

    QMutex *data_lock;
    CaptureThread *capturer = nullptr;

private:

    void initUI();
    void createActions();

    QStandardItemModel *list_model;


private slots:
    void showCameraInfo();
    void openCamera();
    void updateFrame(cv::Mat*);
    void appendSavedPhoto(QString name);
    void populateSavedList();
    void takePhoto();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
