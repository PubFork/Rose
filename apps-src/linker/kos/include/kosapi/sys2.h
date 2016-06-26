#ifndef _KOSAPI_SYS2_H
#define _KOSAPI_SYS2_H

#ifndef _WIN32
#include <sys/cdefs.h>
#include <stdbool.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

bool sys2_run_app(const char* package);

typedef struct {
	char res_path[64];
	char userdata_path[128];
} kOS_osinfo;
void sys2_get_osinfo(kOS_osinfo* info);

typedef void (*fdid_sys2_touched)(int touch_device_id, int pointer_finter_id, int action, float x, float y, float p);
typedef void (*fdid_sys2_hover_moved)(int state, int action, float x, float y);

void sys2_set_did(fdid_sys2_touched did_touched, fdid_sys2_hover_moved did_hover_moved);

void sys2_pump();

#ifdef __cplusplus
}
#endif

#endif /* _KOSAPI_SYS2_H */
