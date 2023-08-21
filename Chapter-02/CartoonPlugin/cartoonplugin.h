#ifndef CARTOONPLUGIN_H
#define CARTOONPLUGIN_H

#include "CartoonPlugin_global.h"
#include <QObject>
#include <QtPlugin>

#include "editor_plugin_interface.h"

class CARTOONPLUGIN_EXPORT CartoonPlugin : public QObject, public EditorPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID EDIT_PLUGIN_INTERFACE_IID);
    Q_INTERFACES(EditorPluginInterface);

public:
    QString name() override;
    void edit(const cv::Mat &input, cv::Mat &output) override;
};

#endif // CARTOONPLUGIN_H
