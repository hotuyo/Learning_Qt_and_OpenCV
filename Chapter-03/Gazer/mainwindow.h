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

#ifdef GAZER_USE_QT_CAMERA
    QCamera *camera;
    QVideoWidget *viewfinder;
    QMediaCaptureSession *session;
#endif

private:

    QMenu *fileMenu;

    QAction *cameraInfoAction;
    QAction *openCameraAction;
    QAction *exitAction;
    QAction *calcFPSAction;

    QGraphicsScene *imageScene;
    QGraphicsView  *imageView;

    QCheckBox *monitorCheckBox;
    QPushButton *recordButton;

    QListView *saved_list;

    QStatusBar *mainStatusBar = nullptr;
    QLabel *mainStatusLabel = nullptr;

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
    void calculateFPS();
    void updateFPS(float);

    void recordingStartStop();
    void appendSavedVideo(QString name);

    void updateMonitorStatus(int status);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
