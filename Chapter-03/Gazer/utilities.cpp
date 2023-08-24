#include "utilities.h"
#include <QStandardPaths>
#include <QDir>
#include <QDateTime>
#include <QNetworkRequest>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QHostInfo>
#include <QApplication>
#include <QJsonDocument>

QString Utilities::getDataPath()
{
    QString user_movie_path =
        QStandardPaths::standardLocations(QStandardPaths::MoviesLocation)[0];

    QDir movie_dir(user_movie_path);
    movie_dir.mkpath("Gazer");
    return movie_dir.absoluteFilePath("Gazer");
}

QString Utilities::newSaveVideoName()
{
    QDateTime time = QDateTime::currentDateTime();
    return time.toString("yyyy-MM-dd+HH:mm:ss");
}

QString Utilities::getSavedVideoPath(QString name, QString postfix)
{
    return QString("%1/%2.%3").arg(Utilities::getDataPath(), name, postfix);
}

void Utilities::notifyMobile(int cameraID)
{
    QString endpoint = "https://maker.ifttt.com/trigger/Test/with/key/bzKwpobgf_4hht7NPQ3ugx";
    QNetworkRequest request = QNetworkRequest(QUrl(endpoint));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject json;
    json.insert("value1", QString("%1").arg(cameraID));
    json.insert("value2", QHostInfo::localHostName());
    QNetworkAccessManager nam;
    QNetworkReply *rep = nam.post(request, QJsonDocument(json).toJson());
    while(!rep->isFinished())
    {
        QApplication::processEvents();
    }
    rep->deleteLater();

}

