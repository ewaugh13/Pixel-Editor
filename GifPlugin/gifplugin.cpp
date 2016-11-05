#include "gifplugin.h"


GifPlugin::GifPlugin(QObject *parent) :
    QImageIOPlugin(parent)
{
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(GifPlugin, GifPlugin)
#endif // QT_VERSION < 0x050000
