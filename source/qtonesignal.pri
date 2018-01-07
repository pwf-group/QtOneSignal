INCLUDEPATH += $$PWD

SOURCES += \
	$$PWD/qonesignal.cpp

HEADERS += \
	$$PWD/qonesignal.h

android {
	QT += androidextras
	SOURCES += $$PWD/qonesignal_android.cpp

	QONESIGNAL_JAVASRC.path = /src/org/pwf/qtonesignal
	QONESIGNAL_JAVASRC.files += $$files($$PWD/android/src/org/pwf/qtonesignal/*)
	INSTALLS += QONESIGNAL_JAVASRC
} else:ios {
	## the objective sources should be put in this variable
	OBJECTIVE_SOURCES += \
		$$PWD/qonesignal_ios.mm
} else {
	SOURCES += \
		$$PWD/qonesignal_desktop.cpp
}

OTHER_FILES += \
        $$PWD/README.md \
        $$files($$PWD/android/src/org/pwf/qtonesignal/*)

DISTFILES += \
    $$PWD/android/src/org/pwf/qtonesignal/QOneSignalNotificationReceivedHandler.java \
    $$PWD/android/src/org/pwf/qtonesignal/QOneSignalNotificationOpenedHandler.java

