#ifndef AFFINEPLUGIN_GLOBAL_H
#define AFFINEPLUGIN_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(AFFINEPLUGIN_LIBRARY)
#  define AFFINEPLUGIN_EXPORT Q_DECL_EXPORT
#else
#  define AFFINEPLUGIN_EXPORT Q_DECL_IMPORT
#endif

#endif // AFFINEPLUGIN_GLOBAL_H