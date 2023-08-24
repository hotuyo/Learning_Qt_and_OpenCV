

#include <QString>

class Utilities
{
public:
    static QString getDataPath();
    static QString newSaveVideoName();
    static QString getSavedVideoPath(QString name, QString postfix);
    static void notifyMobile(int cameraID);
};
