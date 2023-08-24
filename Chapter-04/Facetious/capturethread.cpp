#include "capturethread.h"
#include <QElapsedTimer>
#include "opencv2/opencv.hpp"
#include <vector>
#include <QApplication>
using namespace std;

CaptureThread::CaptureThread(int camera, QMutex *lock):
    running(false), cameraID(camera), videoPath(""), data_lock(lock)
{


    frame_width = frame_height = 0;
    taking_photo = false;

}

CaptureThread::CaptureThread(QString videoPath, QMutex *lock)
    :running(false), cameraID(-1), videoPath(videoPath), data_lock(lock)
{

    frame_width = frame_height = 0;
    taking_photo = false;

}

CaptureThread::~CaptureThread()
{

}

void CaptureThread::run()
{

    running = true;
    cv::VideoCapture cap(cameraID);
    cv::Mat tmp_frame;

    frame_height = cap.get(cv::CAP_PROP_FRAME_HEIGHT);
    frame_width = cap.get(cv::CAP_PROP_FRAME_WIDTH);

    classifier = new cv::CascadeClassifier(OPENCV_DATA_DIR "haarcascades/haarcascade_frontalface_default.xml");
    mark_detector = cv::face::createFacemarkLBF();
    QString model_data = QApplication::instance()->applicationDirPath() + "/data/lbfmodel.yaml";
    mark_detector->loadModel(model_data.toStdString());

    while(running)
    {
        cap >> tmp_frame;
        if (tmp_frame.empty())
        {
            break;
        }
        detectFaces(tmp_frame);

        if(taking_photo)
        {
            takePhoto(tmp_frame);
        }
        cvtColor(tmp_frame, tmp_frame, cv::COLOR_BGR2RGB);
        data_lock->lock();
        frame = tmp_frame;
        data_lock->unlock();
        emit frameCaptured(&frame);
    }
    cap.release();
    delete classifier;
    classifier = nullptr;
    running =false;
}

void CaptureThread::takePhoto(cv::Mat &frame)
{
    QString photo_name = Utilities::newPhotoName();
    QString photo_path = Utilities::getPhotoPath(photo_name, "jpg");
    cv::imwrite(photo_path.toStdString(), frame);
    emit photoTaken(photo_name);
    taking_photo = false;
}

void CaptureThread::detectFaces(cv::Mat &frame)
{
    vector<cv::Rect> faces;
    cv::Mat gray_frame;
    cv::cvtColor(frame, gray_frame, cv::COLOR_BGR2GRAY);
    classifier->detectMultiScale(gray_frame, faces, 1.3, 5);

    cv::Scalar color = cv::Scalar(0, 255, 0);
    for(size_t i = 0; i < faces.size(); ++i)
    {
        cv::rectangle(frame, faces[i], color, 5);
    }

    vector<vector<cv::Point2f>> shapes;
    if (mark_detector->fit(frame, faces, shapes))
    {
        for (unsigned long i = 0; i < faces.size(); ++i)
        {
            for (unsigned long j = 0; j <shapes[i].size(); ++j)
            {
//                cv::circle(frame, shapes[i][j], 2, color, cv::FILLED);
                QString index = QString("%1").arg(j);
                cv::putText(frame, index.toStdString(), shapes[i][j], cv::FONT_HERSHEY_SIMPLEX, 0.4, color, 2);
            }
        }
    }
}

void CaptureThread::loadOrnaments()
{
    QImage image;
    image.load("/images/glasses.jpg");
    image = image.convertToFormat(QImage::Format_RGB888);
    glasses = cv::Mat(image.height(), image.width(), CV_8UC3, image.bits(), image.bytesPerLine()).clone();
    image.load("/images/mustache.jpg");
    image = image.convertToFormat(QImage::Format_RGB888);
    mustache = cv::Mat(image.height(), image.width(), CV_8UC3, image.bits(), image.bytesPerLine()).clone();
    image.load("/images/mouse-nose.jpg");
    image = image.convertToFormat(QImage::Format_RGB888);
    mouse_nose = cv::Mat(image.height(), image.width(), CV_8UC3, image.bits(), image.bytesPerLine()).clone();

}
