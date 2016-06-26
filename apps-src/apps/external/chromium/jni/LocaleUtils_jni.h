// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is autogenerated by
//     base/android/jni_generator/jni_generator.py
// For
//     org/chromium/base/LocaleUtils

#ifndef org_chromium_base_LocaleUtils_JNI
#define org_chromium_base_LocaleUtils_JNI

#include <jni.h>

#include "base/android/jni_generator/jni_generator_helper.h"

// Step 1: forward declarations.
JNI_REGISTRATION_EXPORT extern const char
    kClassPath_org_chromium_base_LocaleUtils[];
const char kClassPath_org_chromium_base_LocaleUtils[] =
    "org/chromium/base/LocaleUtils";

// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_REGISTRATION_EXPORT base::subtle::AtomicWord
    g_org_chromium_base_LocaleUtils_clazz = 0;
#ifndef org_chromium_base_LocaleUtils_clazz_defined
#define org_chromium_base_LocaleUtils_clazz_defined
inline jclass org_chromium_base_LocaleUtils_clazz(JNIEnv* env) {
  return base::android::LazyGetClass(env,
      kClassPath_org_chromium_base_LocaleUtils,
      &g_org_chromium_base_LocaleUtils_clazz);
}
#endif

// Step 2: method stubs.

static base::subtle::AtomicWord
    g_org_chromium_base_LocaleUtils_getDefaultLocaleString = 0;
static base::android::ScopedJavaLocalRef<jstring>
    Java_LocaleUtils_getDefaultLocaleString(JNIEnv* env) {
  CHECK_CLAZZ(env, org_chromium_base_LocaleUtils_clazz(env),
      org_chromium_base_LocaleUtils_clazz(env), NULL);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, org_chromium_base_LocaleUtils_clazz(env),
      "getDefaultLocaleString",
"("
")"
"Ljava/lang/String;",
      &g_org_chromium_base_LocaleUtils_getDefaultLocaleString);

  jstring ret =
static_cast<jstring>(env->CallStaticObjectMethod(org_chromium_base_LocaleUtils_clazz(env),
          method_id));
  jni_generator::CheckException(env);
  return base::android::ScopedJavaLocalRef<jstring>(env, ret);
}

static base::subtle::AtomicWord
    g_org_chromium_base_LocaleUtils_getDefaultCountryCode = 0;
static base::android::ScopedJavaLocalRef<jstring>
    Java_LocaleUtils_getDefaultCountryCode(JNIEnv* env) {
  CHECK_CLAZZ(env, org_chromium_base_LocaleUtils_clazz(env),
      org_chromium_base_LocaleUtils_clazz(env), NULL);
  jmethodID method_id =
      base::android::MethodID::LazyGet<
      base::android::MethodID::TYPE_STATIC>(
      env, org_chromium_base_LocaleUtils_clazz(env),
      "getDefaultCountryCode",
"("
")"
"Ljava/lang/String;",
      &g_org_chromium_base_LocaleUtils_getDefaultCountryCode);

  jstring ret =
static_cast<jstring>(env->CallStaticObjectMethod(org_chromium_base_LocaleUtils_clazz(env),
          method_id));
  jni_generator::CheckException(env);
  return base::android::ScopedJavaLocalRef<jstring>(env, ret);
}

#endif  // org_chromium_base_LocaleUtils_JNI
