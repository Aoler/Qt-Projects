#ifndef LOGVIEW_GLOBAL_H
#define LOGVIEW_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LOGVIEW_LIBRARY)
#  define LOGVIEWSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LOGVIEWSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LOGVIEW_GLOBAL_H
