#ifndef CAPTURETHREAD_H
#define CAPTURETHREAD_H

#include <QString>
#include <QThread>
#include <QMutex>
#include <QDebug>
#include "opencv2/opencv.hpp"
#include "utilities.h"



class CaptureThread : public QThread
{
    Q_OBJECT
public:


    CaptureThread(int camera, QMutex *lock);
    CaptureThread(QString videoPath, QMutex *lock);
    ~CaptureThread();

    enum VideoSavingStatus{
        STARTING,
        STARTED,
        STOPPING,
        STOPPED
    };

    void setVideoSavingStatus(VideoSavingStatus status) {video_saving_status = status; };

    void startCalcFPS() {fps_calculating = true; };
    void setRunning(bool running) {
        qDebug() << "setRun";
        running = running;
    };

    void setMotionDetectingStatus(bool status)
    {
        motion_detecting_status = status;
        motion_detected = false;
        if(video_saving_status != STOPPED) video_saving_status = STOPPING;
    };

protected:
    void run() override;

signals:
    void frameCaptured(cv::Mat *data);
    void fpsChanged(float fps);
    void videoSaved(QString name);

private:
    bool running;           // running for the Thread state
    int cameraID;           //camera index
    QString videoPath;
    QMutex *data_lock;
    cv::Mat frame;

    bool fps_calculating;
    float fps;
    void calculateFPS(cv::VideoCapture &cap);

    // video saving
    int frame_width, frame_height;
    VideoSavingStatus video_saving_status;
    QString saved_video_name;
    cv::VideoWriter *video_writer;

    void startSavingVideo(cv::Mat &firstFrame);
    void stopSavingVideo();
    void motionDetect(cv::Mat &frame);

    bool motion_detecting_status;
    bool motion_detected;
    cv::Ptr<cv::BackgroundSubtractorMOG2> segmentor;
};

#endif // CAPTURETHREAD_H
