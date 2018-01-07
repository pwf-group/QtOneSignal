package org.pwf.qtonesignal;

import android.os.Bundle;
import android.app.Activity;

import com.onesignal.OneSignal;

public class QOneSignalBinding {

    // native function for callback
    public static native void notificationReceive(String nmea);
    public static native void notificationOpen(String nmea);

    // Singleton instance created as soon as possibile
    public static final QOneSignalBinding m_instance = new QOneSignalBinding();
    // Activity of which this QOneSignalBinding is associated
    public Activity activity = null;

    //! This has to be called inside the onCreate of Activity
    static public void onCreate(Activity activity, Bundle savedInstanceState) {
        m_instance.activity = activity;

        OneSignal.startInit(m_instance.activity)
            .autoPromptLocation(false) // default call promptLocation later
            .setNotificationReceivedHandler(new QOneSignalNotificationReceivedHandler())
            .setNotificationOpenedHandler(new QOneSignalNotificationOpenedHandler())
            .inFocusDisplaying(OneSignal.OSInFocusDisplayOption.Notification)
            .unsubscribeWhenNotificationsAreDisabled(true)
            .init();

        // Call syncHashedEmail anywhere in your app if you have the user's email.
        // This improves the effectiveness of OneSignal's "best-time" notification scheduling feature.
        // OneSignal.syncHashedEmail(userEmail);
    }

    //! Expose other basic function for consumption
    private static void sendTag(String key, String value) {
        OneSignal.sendTag(key, value);
    }

    private static void deleteTag(String key) {
        OneSignal.deleteTag(key);
    }
}
