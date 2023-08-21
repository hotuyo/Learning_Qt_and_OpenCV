#ifndef CARTOONPLUGIN_GLOBAL_H
#define CARTOONPLUGIN_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CARTOONPLUGIN_LIBRARY)
#  define CARTOONPLUGIN_EXPORT Q_DECL_EXPORT
#else
#  define CARTOONPLUGIN_EXPORT Q_DECL_IMPORT
#endif

#endif // CARTOONPLUGIN_GLOBAL_H
