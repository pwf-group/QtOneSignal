# QtOneSignal

Credit to [QtFacebook](https://github.com/GMaxera/QtFacebook) for the basic framework of setup for private project.

There is also link to my blog [Qt 5.9 Android Extra OneSignal – Building it and take away](http://choong.pw/2018/01/qt-5-9-android-extra-onesignal-building-it-and-take-away/). If you encounter any errors, check out the blog, as I have documented the common errors I have encounter along the way.

Code for use OneSignal SDK from C++ and Qt Quick 2 in Qt 5 projects targeted on mobile devices (Android & iOS)

**NOTE** iOS is currently not implemented. Contributor are welcome to help fill up the iOS implementation.

The aim of this project is to provide code to include into your Qt project in order to use OneSignal functionality easily. Hence, it provides ready-to-use code for common scenarion of receiving push notification with OneSignal, but you need to manually install into your Qt project. Binary packages and plugins to install into Qt distributions are not provided.

Include QtOneSignal in your project including the qtonesignal.pri in your .pro file:

```
## include the QtFacebook library as project
include(/Adjust/the/path/to/repos/QtOneSignal/qtonesignal.pri)
```

# How to use for Android platform

## Prepare OneSignal SDK for Android

Setup the gradle as guided from the [OneSignal SDK guide](https://documentation.onesignal.com/v4.0/docs/android-sdk-setup).

If you are starting from the example project. Remember to change a few of the settings before use.

Update the following in the `build.gradle`.

```
defaultConfig {
    applicationId "org.qtproject.example"

    // TODO: Update OneSignal ID below
    manifestPlaceholders = [onesignal_app_id: "PUT YOUR ONESIGNAL APP ID HERE",
                          // Project number pulled from dashboard, local value is ignored.
                          onesignal_google_project_number: "REMOTE"]
}
```

and `AndroidManifest.xml`.

```
<meta-data android:name="onesignal_app_id" android:value="PUT YOUR ONESIGNAL APP ID HERE"/>
```


# How to use in Qt Quick

Foremost, you'll need to register the Qml type in the `main.cpp`.

```
QOneSignal::registerQMLTypes();
```

Next, in the Qml can import the following
```
import QOneSignal 1.0
```

The expose property, can be obtain from the following
```
QOneSignal.notificationReceive
QOneSignal.notificationOpen

or

Connections {
    target: QOneSignal
    onNotificationReceiveChanged: {
        console.log("notificationReceive: ", QOneSignal.notificationReceive);
    }
    onNotificationOpenChanged: {
        console.log("notificationOpen: ", QOneSignal.notificationOpen);
    }
}
```

Currently available methods for OneSignalSDK are as follow:
```
QOneSignal.sendTag(key, value)
QOneSignal.deleteTag(key)
```

# TODO

- To handle [Multiple definition of JNI_OnLoad](https://github.com/GMaxera/QtFacebook#multiple-definition-of-jni_onload)
- To add support for iOS.
- To fix notification opened with data callback.
- To expose more of the OneSignalSDK method in Qt Quick.
