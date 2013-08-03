// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    id: rectangle1
    width: 400
    height: 200
    color: "#0800ff"
    radius: 2
    border.width: 3
    border.color: "#00005e"

    // Signals to C++
    signal sendBananaLaunchData(string pAngle, string pVelocity)

    Rectangle {
        id: rectangleOk
        x: 136
        y: 152
        width: 128
        height: 32
        color: "#0014b3"
        radius: 8
        smooth: true
        border.color: "#000773"
        MouseArea {
            id: mouseAreaPlay
            x: 0
            y: 0
            width: 408
            height: 68
            hoverEnabled: true
            anchors.fill: parent
            onClicked: sendBananaLaunchData(inputAngle.text,inputVelocity.text)
            Text {
                id: textPlay
                x: 0
                y: 0
                color: "#e2ff05"
                text: qsTr("OK")
                anchors.rightMargin: 0
                anchors.bottomMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 0
                anchors.fill: parent
                smooth: true
                font.pixelSize: 20
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 16
        border.width: 7
        anchors.leftMargin: 136
        anchors.left: parent.left
        states: [
            State {
                name: "stateClick"
                PropertyChanges {
                    target: rectangleOk
                    color: "#061784"
                }
            },
            State {
                name: "stateHover"
                PropertyChanges {
                    target: rectangleOk
                    color: "#1024c3"
                }
            }]
        transitions: [
            Transition {
                to: "*"
                from: "*"
                ColorAnimation {
                    properties: "color"
                    duration: 100
                }
            }]
    }

    Rectangle {
        id: rectangleVelocity
        x: 53
        y: 103
        width: 282
        height: 31
        color: "#00000000"
        Rectangle {
            id: rectangleInputVelocity
            x: 174
            y: 4
            width: 267
            height: 24
            color: "#ffffff"
            radius: 2
            border.color: "#000773"
            TextInput {
                id: inputVelocity
                text: qsTr("")
                inputMask: "9999"
                font.pixelSize: 22
                anchors.fill: parent
                anchors.topMargin: 3
                anchors.rightMargin: 3
                anchors.bottomMargin: 3
                font.bold: true
                horizontalAlignment: TextInput.AlignLeft
                anchors.leftMargin: 3
            }
            anchors.rightMargin: 0
            border.width: 3
            anchors.right: parent.right
            anchors.leftMargin: 8
            anchors.left: textVelocity.right
        }

        Text {
            id: textVelocity
            color: "#e2ff05"
            text: qsTr("Velocity :")
            smooth: true
            font.pixelSize: 20
            font.bold: true
            anchors.leftMargin: 0
            horizontalAlignment: Text.AlignHCenter
            anchors.left: parent.left
        }
        anchors.bottom: parent.bottom
        anchors.rightMargin: 65
        anchors.bottomMargin: 66
        anchors.right: parent.right
    }

    Rectangle {
        id: rectangleAngle
        x: 74
        y: 62
        width: 261
        height: 32
        color: "#00000000"
        Rectangle {
            id: rectangleInputAngle
            x: 174
            y: 4
            width: 290
            height: 24
            color: "#ffffff"
            radius: 2
            border.color: "#000773"
            TextInput {
                id: inputAngle
                x: 0
                y: 3
                width: 252
                height: 30
                text: qsTr("")
                inputMask: "9999"
                passwordCharacter: "*"
                font.pixelSize: 22
                anchors.fill: parent
                anchors.topMargin: 3
                anchors.rightMargin: 3
                anchors.bottomMargin: 3
                font.bold: true
                anchors.leftMargin: 0
                horizontalAlignment: TextInput.AlignLeft
            }
            anchors.rightMargin: 0
            border.width: 3
            anchors.right: parent.right
            anchors.leftMargin: 8
            anchors.left: textAngle.right
        }

        Text {
            id: textAngle
            x: 0
            y: 4
            color: "#e2ff05"
            text: qsTr("Angle :")
            smooth: true
            font.pixelSize: 20
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            anchors.leftMargin: 0
            anchors.left: parent.left
        }
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 106
    }

    Text {
        id: textPlayerName
        x: 0
        y: 8
        width: 400
        height: 36
        color: "#e2ff05"
        text: qsTr("PLAYER 1")
        font.bold: true
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 30
    }
}
