package org.libsdl.app;


import android.app.IntentService;
import android.content.Intent;
import android.media.AudioFormat;
import android.media.AudioManager;
import android.media.AudioRecord;
import android.media.AudioTrack;
import android.media.MediaRecorder;
import android.net.Uri;
import android.os.Binder;
import android.os.Environment;
import android.os.IBinder;
import android.os.Process;
import android.provider.Settings;
import android.util.Log;

import org.webrtc.ThreadUtils;

import java.io.File;

import static junit.framework.Assert.assertTrue;
import static org.libsdl.app.SDL.mContext;

public class UpdateService extends IntentService {
    private static final String TAG = "SDL";
    public static boolean mDestroyed;

    private final IBinder mBinder = new LocalBinder();
    /**
     * A constructor is required, and must call the super IntentService(String)
     * constructor with a name for the worker thread.
     */
    public UpdateService() {
        super("UpdateService");
        Log.i("SDL", "UpdateService, UpdateService(), " + System.currentTimeMillis());
    }

    /**
     * The IntentService calls this method from the default worker thread with
     * the intent that started the service. When this method returns, IntentService
     * stops the service, as appropriate.
     */
    @Override
    protected void onHandleIntent(Intent intent) {
        Log.i("SDL", "UpdateService, 1, onHandleIntent(), " + System.currentTimeMillis());
/*
        final long token = Binder.clearCallingIdentity();
        try {
            // Settings.Global.putInt(mContext.getContentResolver(), Settings.Global.MOBILE_DATA, enabled ? 1 : 0);
        } finally {
            Binder.restoreCallingIdentity(token);
        }
        Binder.restoreCallingIdentity(token);
*/
        String filePath2 = intent.getExtras().getString("apkname");
        // String filePath2 = "iaccess-debug.apk";
        // filePath2 = "baiduinput_AndroidPhone_1021500d.apk";
        // filePath2 = "stid.apk";
        String filePath = Environment.getExternalStorageDirectory().getAbsolutePath() + "/" + filePath2;
        filePath = SDL.getContext().getExternalFilesDir(null).getAbsolutePath() + "/" + filePath2;

        Log.i(TAG, "start install: " + filePath);
        File apkFile = new File(filePath);
        Uri uri = Uri.fromFile(apkFile);
        Intent installIntent = new Intent(Intent.ACTION_VIEW);
        installIntent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        installIntent.setDataAndType(uri, "application/vnd.android.package-archive");
/*
        updatePendingIntent = PendingIntent.getActivity( UpdateService.this, 0, installIntent, 0);
        updateNotification.contentIntent = updatePendingIntent;
        updateNotification.contentView.setTextViewText( R.id.download_notice_speed_tv, getString(R.string.update_notice_finish));
        updateNotification.tickerText = appName + "下载完成"; updateNotification.when = System.currentTimeMillis();
        updateNotification.defaults = Notification.DEFAULT_SOUND; updateNotification.flags |= Notification.FLAG_AUTO_CANCEL;
        updateNotificationManager.notify(0, updateNotification);
*/
        //启动安装程序
        UpdateService.this.startActivity(installIntent);
        stopSelf();

        Log.i("SDL", "UpdateService, 3, onHandleIntent(), " + System.currentTimeMillis());
    }

    @Override
    public IBinder onBind(Intent intent) {
        // mBound = true;
        Log.i("SDL", "UpdateService, onBind(), " + System.currentTimeMillis());
        return mBinder;
    }

    @Override
    public boolean onUnbind(Intent intent) {
        // mBound = false;
        // close();
        Log.i("SDL", "UpdateService, onUnbind(), " + System.currentTimeMillis());
        return super.onUnbind(intent);
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        mDestroyed = true;
        Log.i("SDL", "UpdateService, onDestroy(), " + System.currentTimeMillis());
    }

    /**
     * Local binder class
     */
    public class LocalBinder extends Binder {
        public UpdateService getService() {
            return UpdateService.this;
        }
    }
}