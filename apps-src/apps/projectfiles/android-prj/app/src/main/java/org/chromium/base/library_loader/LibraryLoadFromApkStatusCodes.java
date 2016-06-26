package org.chromium.base.library_loader;

import android.support.annotation.IntDef;

import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;

@IntDef({
        LibraryLoadFromApkStatusCodes.UNKNOWN, LibraryLoadFromApkStatusCodes.NOT_SUPPORTED_OBSOLETE,
        LibraryLoadFromApkStatusCodes.SUPPORTED_OBSOLETE, LibraryLoadFromApkStatusCodes.SUCCESSFUL,
        LibraryLoadFromApkStatusCodes.USED_UNPACK_LIBRARY_FALLBACK,
        LibraryLoadFromApkStatusCodes.USED_NO_MAP_EXEC_SUPPORT_FALLBACK_OBSOLETE,
        LibraryLoadFromApkStatusCodes.MAX
})
@Retention(RetentionPolicy.SOURCE)
public @interface LibraryLoadFromApkStatusCodes {
    /**
     * The loader was unable to determine whether the functionality is supported.
     */
    int UNKNOWN = 0;
    /**
     * The device does not support loading a library directly from the APK file (obsolete).
     */
    int NOT_SUPPORTED_OBSOLETE = 1;
    /**
     * The device supports loading a library directly from the APK file. (obsolete).
     */
    int SUPPORTED_OBSOLETE = 2;
    /**
     * The Chromium library was successfully loaded directly from the APK file.
     */
    int SUCCESSFUL = 3;
    /**
     * The Chromium library was successfully loaded using the unpack library fallback because it was
     * compressed or not page aligned in the APK file.
     */
    int USED_UNPACK_LIBRARY_FALLBACK = 4;
    /**
     * The Chromium library was successfully loaded using the no map executable support fallback
     * (obsolete).
     */
    int USED_NO_MAP_EXEC_SUPPORT_FALLBACK_OBSOLETE = 5;
    /**
     * End sentinel.
     */
    int MAX = 6;
}
