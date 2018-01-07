import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QOneSignal 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Qt OneSignal Test Application")

    Connections {
        target: QOneSignal
        onNotificationReceiveChanged: {
            console.log("notificationReceive: ", QOneSignal.notificationReceive);
        }
        onNotificationOpenChanged: {
            console.log("notificationOpen: ", QOneSignal.notificationOpen);
        }
    }

    Column {
        spacing: 5
        anchors.centerIn: parent
        Label {
            text: qsTr("Second page")
        }
        Label {
            text: "notificationReceive"
        }
        Label {
            text: QOneSignal.notificationReceive
        }
        Label {
            text: "notificationOpen"
        }
        Label {
            text: QOneSignal.notificationOpen
        }
        TextField {
            id: fieldKey
            placeholderText: "key"
        }
        TextField {
            id: fieldValue
            placeholderText: "value"
        }
        Button {
            text: "sendTag"
            onClicked: QOneSignal.sendTag(fieldKey.text, fieldValue.text)
        }
        Button {
            text: "deleteTag"
            onClicked: QOneSignal.deleteTag(fieldKey.text)
        }
    }
}
