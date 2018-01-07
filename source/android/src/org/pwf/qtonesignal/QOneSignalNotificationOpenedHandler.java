package org.pwf.qtonesignal;

import android.content.Intent;

import com.onesignal.OneSignal;
import com.onesignal.OSNotificationOpenResult;
import com.onesignal.OSNotificationAction;
import com.onesignal.OSNotification;
import com.onesignal.OSNotificationPayload;

import org.json.JSONObject;
import java.util.List;

public class QOneSignalNotificationOpenedHandler implements OneSignal.NotificationOpenedHandler {
    // This fires when a notification is opened by tapping on it.
    @Override
    public void notificationOpened(OSNotificationOpenResult result) {
        JSONObject data = result.notification.payload.additionalData;

        if (data != null) {
            // not able to call this when app not at foreground, thus disable this feature
            // QOneSignalBinding.m_instance.notificationOpen(data.toString());
        }
    }
}
