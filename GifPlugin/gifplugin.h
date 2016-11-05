#ifndef GIFPLUGIN_H
#define GIFPLUGIN_H

#include <QImageIOPlugin>


class GifPlugin : public QImageIOPlugin
{
    Q_OBJECT
#if QT_VERSION >= 0x050000
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QImageIOHandlerFactoryInterface" FILE "GifPlugin.json")
#endif // QT_VERSION >= 0x050000

public:
    GifPlugin(QObject *parent = 0);
};

#endif // GIFPLUGIN_H
