#ifndef _KOSAPI_CAMERA2_H
#define _KOSAPI_CAMERA2_H

#ifndef _WIN32
#include <sys/cdefs.h>
#include <stdint.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

int camera2_getNumberOfCameras();
int camera2_getCameraInfo(int cameraId, char* info);
int camera2_setup(int cameraId, const char* clientPackageName);
void camera2_release(int cameraId);

typedef void (*fdid_camera2_frame_captured)(const void* data, int length, int width, int height, int rotation, int64_t timestamp_ns, void* user);
int camera2_startPreview(int cameraId, fdid_camera2_frame_captured did, void* user);
void camera2_stopPreview(int cameraId);

#ifdef __cplusplus
}
#endif

#endif /* _KOSAPI_CAMERA2_H */
