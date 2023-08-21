#ifndef AFFINEPLUGIN_H
#define AFFINEPLUGIN_H

#include "AffinePlugin_global.h"
#include "editor_plugin_interface.h"

class AFFINEPLUGIN_EXPORT AffinePlugin : public QObject, public EditorPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID EDIT_PLUGIN_INTERFACE_IID);
    Q_INTERFACES(EditorPluginInterface);
public:
    QString name() override;
    void edit(const cv::Mat &input, cv::Mat &output) override;
};

#endif // AFFINEPLUGIN_H
