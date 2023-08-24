#include "mainwindow.h"

#include <QApplication>


#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
//    qputenv("OPENCV_AVFOUNDATION_SKIP_AUTH", "0");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

