// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/base/EarlyTraceEvent

#ifndef org_chromium_base_EarlyTraceEvent_JNI
#define org_chromium_base_EarlyTraceEvent_JNI

#include <jni.h>

#include "base/android/jni_generator/jni_generator_helper.h"

// Step 1: forward declarations.
JNI_REGISTRATION_EXPORT extern const char
    kClassPath_org_chromium_base_EarlyTraceEvent[];
const char kClassPath_org_chromium_base_EarlyTraceEvent[] =
    "org/chromium/base/EarlyTraceEvent";

// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_REGISTRATION_EXPORT base::subtle::AtomicWord
    g_org_chromium_base_EarlyTraceEvent_clazz = 0;
#ifndef org_chromium_base_EarlyTraceEvent_clazz_defined
#define org_chromium_base_EarlyTraceEvent_clazz_defined
inline jclass org_chromium_base_EarlyTraceEvent_clazz(JNIEnv* env) {
  return base::android::LazyGetClass(env,
      kClassPath_org_chromium_base_EarlyTraceEvent,
      &g_org_chromium_base_EarlyTraceEvent_clazz);
}
#endif

namespace base {
namespace android {

// Step 2: method stubs.

static void JNI_EarlyTraceEvent_RecordEarlyEvent(JNIEnv* env, const
    base::android::JavaParamRef<jclass>& jcaller,
    const base::android::JavaParamRef<jstring>& name,
    jlong beginTimNanos,
    jlong endTimeNanos,
    jint threadId,
    jlong threadDurationMillis);

JNI_GENERATOR_EXPORT void
    Java_org_chromium_base_EarlyTraceEvent_nativeRecordEarlyEvent(JNIEnv* env,
    jclass jcaller,
    jstring name,
    jlong beginTimNanos,
    jlong endTimeNanos,
    jint threadId,
    jlong threadDurationMillis) {
  TRACE_NATIVE_EXECUTION_SCOPED("RecordEarlyEvent");
  return JNI_EarlyTraceEvent_RecordEarlyEvent(env,
      base::android::JavaParamRef<jclass>(env, jcaller),
      base::android::JavaParamRef<jstring>(env, name), beginTimNanos,
      endTimeNanos, threadId, threadDurationMillis);
}

}  // namespace android
}  // namespace base

#endif  // org_chromium_base_EarlyTraceEvent_JNI
