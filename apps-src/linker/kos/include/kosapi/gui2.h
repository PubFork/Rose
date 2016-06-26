#ifndef _KOSAPI_GUI2_H
#define _KOSAPI_GUI2_H

#ifndef _WIN32
#include <sys/cdefs.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

struct ANativeWindow;

ANativeWindow* gui2_get_surface();

#ifdef __cplusplus
}
#endif

#endif /* _KOSAPI_GUI2_H */
