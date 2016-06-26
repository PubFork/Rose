// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base\android\jni_generator\jni_generator.py
// For
//     org/webrtc/VideoDecoder

#ifndef org_webrtc_VideoDecoder_JNI
#define org_webrtc_VideoDecoder_JNI

#include "sdk/android/src/jni/jni_generator_helper.h"

// Step 1: forward declarations.
JNI_REGISTRATION_EXPORT extern const char kClassPath_org_webrtc_VideoDecoder[];
const char kClassPath_org_webrtc_VideoDecoder[] = "org/webrtc/VideoDecoder";

JNI_REGISTRATION_EXPORT extern const char
    kClassPath_org_webrtc_VideoDecoder_00024Settings[];
const char kClassPath_org_webrtc_VideoDecoder_00024Settings[] =
    "org/webrtc/VideoDecoder$Settings";

// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_REGISTRATION_EXPORT base::subtle::AtomicWord g_org_webrtc_VideoDecoder_clazz
    = 0;
#ifndef org_webrtc_VideoDecoder_clazz_defined
#define org_webrtc_VideoDecoder_clazz_defined
inline jclass org_webrtc_VideoDecoder_clazz(JNIEnv* env) {
  return base::android::LazyGetClass(env, kClassPath_org_webrtc_VideoDecoder,
      &g_org_webrtc_VideoDecoder_clazz);
}
#endif

// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_REGISTRATION_EXPORT base::subtle::AtomicWord
    g_org_webrtc_VideoDecoder_00024Settings_clazz = 0;
#ifndef org_webrtc_VideoDecoder_00024Settings_clazz_defined
#define org_webrtc_VideoDecoder_00024Settings_clazz_defined
inline jclass org_webrtc_VideoDecoder_00024Settings_clazz(JNIEnv* env) {
  return base::android::LazyGetClass(env,
      kClassPath_org_webrtc_VideoDecoder_00024Settings,
      &g_org_webrtc_VideoDecoder_00024Settings_clazz);
}
#endif

// Step 2: method stubs.

static base::subtle::AtomicWord
    g_org_webrtc_VideoDecoder_00024Settings_Constructor = 0;
static base::android::ScopedJavaLocalRef<jobject>
    Java_Settings_Constructor(JNIEnv* env, JniIntWrapper numberOfCores,
    JniIntWrapper width,
    JniIntWrapper height) {
  CHECK_CLAZZ(env, org_webrtc_VideoDecoder_00024Settings_clazz(env),
      org_webrtc_VideoDecoder_00024Settings_clazz(env), NULL);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, org_webrtc_VideoDecoder_00024Settings_clazz(env),
      "<init>",
"("
"I"
"I"
"I"
")"
"V",
      &g_org_webrtc_VideoDecoder_00024Settings_Constructor);

  jobject ret =
      env->NewObject(org_webrtc_VideoDecoder_00024Settings_clazz(env),
          method_id, as_jint(numberOfCores), as_jint(width), as_jint(height));
  jni_generator::CheckException(env);
  return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

static base::subtle::AtomicWord g_org_webrtc_VideoDecoder_initDecode = 0;
static base::android::ScopedJavaLocalRef<jobject>
    Java_VideoDecoder_initDecode(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj, const base::android::JavaRef<jobject>&
    settings,
    const base::android::JavaRef<jobject>& decodeCallback) {
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_VideoDecoder_clazz(env), NULL);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, org_webrtc_VideoDecoder_clazz(env),
      "initDecode",
"("
"Lorg/webrtc/VideoDecoder$Settings;"
"Lorg/webrtc/VideoDecoder$Callback;"
")"
"Lorg/webrtc/VideoCodecStatus;",
      &g_org_webrtc_VideoDecoder_initDecode);

  jobject ret =
      env->CallObjectMethod(obj.obj(),
          method_id, settings.obj(), decodeCallback.obj());
  jni_generator::CheckException(env);
  return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

static base::subtle::AtomicWord g_org_webrtc_VideoDecoder_release = 0;
static base::android::ScopedJavaLocalRef<jobject>
    Java_VideoDecoder_release(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj) {
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_VideoDecoder_clazz(env), NULL);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, org_webrtc_VideoDecoder_clazz(env),
      "release",
"("
")"
"Lorg/webrtc/VideoCodecStatus;",
      &g_org_webrtc_VideoDecoder_release);

  jobject ret =
      env->CallObjectMethod(obj.obj(),
          method_id);
  jni_generator::CheckException(env);
  return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

static base::subtle::AtomicWord g_org_webrtc_VideoDecoder_decode = 0;
static base::android::ScopedJavaLocalRef<jobject>
    Java_VideoDecoder_decode(JNIEnv* env, const base::android::JavaRef<jobject>&
    obj, const base::android::JavaRef<jobject>& frame,
    const base::android::JavaRef<jobject>& info) {
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_VideoDecoder_clazz(env), NULL);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, org_webrtc_VideoDecoder_clazz(env),
      "decode",
"("
"Lorg/webrtc/EncodedImage;"
"Lorg/webrtc/VideoDecoder$DecodeInfo;"
")"
"Lorg/webrtc/VideoCodecStatus;",
      &g_org_webrtc_VideoDecoder_decode);

  jobject ret =
      env->CallObjectMethod(obj.obj(),
          method_id, frame.obj(), info.obj());
  jni_generator::CheckException(env);
  return base::android::ScopedJavaLocalRef<jobject>(env, ret);
}

static base::subtle::AtomicWord g_org_webrtc_VideoDecoder_getPrefersLateDecoding
    = 0;
static jboolean Java_VideoDecoder_getPrefersLateDecoding(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj) {
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_VideoDecoder_clazz(env), false);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, org_webrtc_VideoDecoder_clazz(env),
      "getPrefersLateDecoding",
"("
")"
"Z",
      &g_org_webrtc_VideoDecoder_getPrefersLateDecoding);

  jboolean ret =
      env->CallBooleanMethod(obj.obj(),
          method_id);
  jni_generator::CheckException(env);
  return ret;
}

static base::subtle::AtomicWord g_org_webrtc_VideoDecoder_getImplementationName
    = 0;
static base::android::ScopedJavaLocalRef<jstring>
    Java_VideoDecoder_getImplementationName(JNIEnv* env, const
    base::android::JavaRef<jobject>& obj) {
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_VideoDecoder_clazz(env), NULL);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_INSTANCE>(
      env, org_webrtc_VideoDecoder_clazz(env),
      "getImplementationName",
"("
")"
"Ljava/lang/String;",
      &g_org_webrtc_VideoDecoder_getImplementationName);

  jstring ret =
      static_cast<jstring>(env->CallObjectMethod(obj.obj(),
          method_id));
  jni_generator::CheckException(env);
  return base::android::ScopedJavaLocalRef<jstring>(env, ret);
}

#endif  // org_webrtc_VideoDecoder_JNI
