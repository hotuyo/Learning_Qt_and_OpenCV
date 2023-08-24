#ifndef CAPTURETHREAD_H
#define CAPTURETHREAD_H

#include <QString>
#include <QThread>
#include <QMutex>
#include <QDebug>
#include "opencv2/opencv.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/face/facemark.hpp"
#include "utilities.h"



class CaptureThread : public QThread
{
    Q_OBJECT
public:


    CaptureThread(int camera, QMutex *lock);
    CaptureThread(QString videoPath, QMutex *lock);
    ~CaptureThread();

    void takePhoto() {taking_photo = true; };


    void setRunning(bool running) {
        qDebug() << "setRun";
        running = running;
    };



protected:
    void run() override;

signals:
    void frameCaptured(cv::Mat *data);
    void photoTaken(QString name);

private:
    bool running;           // running for the Thread state
    bool taking_photo;
    int cameraID;           //camera index
    QString videoPath;
    QMutex *data_lock;
    cv::Mat frame;

    cv::CascadeClassifier* classifier;
    cv::Ptr<cv::face::Facemark> mark_detector;

    int frame_width, frame_height;

    cv::Mat glasses;
    cv::Mat mustache;
    cv::Mat mouse_nose;

private:
    void takePhoto(cv::Mat &frame);
    void detectFaces(cv::Mat &frame);
    void loadOrnaments();

};

#endif // CAPTURETHREAD_H
