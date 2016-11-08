#ifndef HLIB_GLOBAL_H
#define HLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(HLIB_LIBRARY)
#  define HLIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define HLIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // HLIB_GLOBAL_H
