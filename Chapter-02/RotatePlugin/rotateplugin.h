#ifndef ROTATEPLUGIN_H
#define ROTATEPLUGIN_H

#include "RotatePlugin_global.h"
#include "editor_plugin_interface.h"
#include <QObject>
#include <QtPlugin>

class ROTATEPLUGIN_EXPORT RotatePlugin : public QObject, public EditorPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID EDIT_PLUGIN_INTERFACE_IID)
    Q_INTERFACES(EditorPluginInterface);

public:
    QString name() override;
    void edit(const cv::Mat &input, cv::Mat &output) override;

};

#endif // ROTATEPLUGIN_H
