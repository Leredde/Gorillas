// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import QtQuick 1.0

Rectangle {
    id: rectangle1
    width: 1280
    height: 720
    color: "#0022ff"

    // Signals to C++
    signal gameStarted()
    signal gameQuit()

    Text {
        id: textWelcome
        color: "#fffb00"
        text: qsTr("GORILLAS")
        anchors.topMargin: 100
        anchors.fill: parent
        smooth: true
        font.bold: true
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 100
    }

    Rectangle {
        id: rectanglePlay
        y: 592
        width: 408
        height: 68
        color: "#0014b3"
        radius: 8
        anchors.left: parent.left
        anchors.leftMargin: 90
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 60
        smooth: true
        border.color: "#000773"
        border.width: 7

        MouseArea {
            id: mouseAreaPlay
            x: 0
            y: 0
            width: 408
            height: 68
            hoverEnabled: true
            anchors.fill: parent
            onClicked: rectangle1.state = 'statePlayer';
            onEntered: parent.state = 'stateHover'
            onExited: parent.state = ''
            onPressed: parent.state = 'stateClick'
            onReleased: {
                if (containsMouse)
                    parent.state = 'stateHover';
                else
                    parent.state = '';
            }

            Text {
                id: textPlay
                x: 0
                y: 0
                width: 408
                height: 68
                color: "#e2ff05"
                text: qsTr("PLAY")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                smooth: true
                font.pixelSize: 30
                font.bold: true
            }
        }
        states: [
            State {
                name: "stateClick"
                PropertyChanges {
                    target: rectanglePlay
                    color: "#061784"
                }
            },
            State {
                name: "stateHover"
                PropertyChanges {
                    target: rectanglePlay
                    color: "#1024c3"
                }
            }
        ]

        transitions: [
            Transition {
                from: "*"; to: "*"
                ColorAnimation {
                    properties: "color";
                    duration: 100
                }

            }
        ]
    }

    Rectangle {
        id: rectangleQuit
        x: 782
        y: 592
        width: 408
        height: 68
        color: "#0014b3"
        radius: 8
        anchors.right: parent.right
        anchors.rightMargin: 90
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 60
        border.width: 7
        border.color: "#000773"
        smooth: true

        MouseArea {
            id: mouseAreaQuit
            x: 0
            y: 0
            width: 408
            height: 68
            hoverEnabled: true
            anchors.fill: parent
            onClicked: gameQuit()
            onEntered: parent.state = 'stateHover'
            onExited: parent.state = ''
            onPressed: parent.state = 'stateClick'
            onReleased:{
                if (containsMouse)
                    parent.state = 'stateHover';

                else
                    parent.state = '';
            }

            Text {
                id: textQuit
                x: 0
                y: 0
                width: 408
                height: 68
                color: "#e2ff05"
                text: qsTr("QUIT")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                smooth: true
                font.bold: true
                font.pixelSize: 30
            }
        }
        states: [
            State {
                name: "stateClick"
                PropertyChanges {
                    target: rectangleQuit
                    color: "#061784"
                }
            },
            State {
                name: "stateHover"
                PropertyChanges {
                    target: rectangleQuit
                    color: "#1024c3"
                }
            }
        ]
        transitions: [
            Transition {
                from: "*"; to: "*"
                ColorAnimation {
                    properties: "color";
                    duration: 100
                }

            }
        ]
    }

    Rectangle {
        id: rectanglePlayer2
        x: 782
        y: 506
        width: 408
        height: 43
        color: "#00000000"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 171
        anchors.right: parent.right
        anchors.rightMargin: 90

        Rectangle {
            id: rectangleInputPlayer2
            x: 174
            y: 4
            height: 36
            color: "#ffffff"
            radius: 2
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: textPlayer2.right
            anchors.leftMargin: 8
            border.color: "#000773"
            TextInput {
                id: inputPlayer2
                text: qsTr("PLAYER2")
                font.pixelSize: 22
                anchors.fill: parent
                anchors.topMargin: 3
                anchors.rightMargin: 3
                anchors.bottomMargin: 3
                font.bold: true
                horizontalAlignment: TextInput.AlignLeft
                anchors.leftMargin: 3
            }
            visible: false
            border.width: 3
        }

        Text {
            id: textPlayer2
            x: 0
            y: 4
            color: "#e2ff05"
            text: qsTr("PLAYER 2 :")
            anchors.left: parent.left
            anchors.leftMargin: 0
            smooth: true
            font.pixelSize: 30
            visible: false
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
        }
    }

    Rectangle {
        id: rectanglePlayer1
        x: 90
        y: 506
        width: 408
        height: 43
        color: "#00000000"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 171
        Rectangle {
            id: rectangleInputPlayer1
            x: 174
            y: 4
            height: 36
            color: "#ffffff"
            radius: 2
            border.color: "#000773"
            TextInput {
                id: inputPlayer1
                text: qsTr("PLAYER1")
                font.pixelSize: 22
                anchors.fill: parent
                anchors.topMargin: 3
                anchors.rightMargin: 3
                anchors.bottomMargin: 3
                font.bold: true
                anchors.leftMargin: 3
                horizontalAlignment: TextInput.AlignLeft
            }
            visible: false
            anchors.rightMargin: 0
            border.width: 3
            anchors.right: parent.right
            anchors.leftMargin: 8
            anchors.left: textPlayer1.right
        }

        Text {
            id: textPlayer1
            x: 0
            y: 4
            color: "#e2ff05"
            text: qsTr("PLAYER 1 :")
            smooth: true
            font.pixelSize: 30
            visible: false
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            anchors.leftMargin: 0
            anchors.left: parent.left
        }
    }

    Image {
        id: imageWelcome
        x: 580
        y: 283
        width: 120
        height: 154
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        fillMode: Image.PreserveAspectCrop
        source: "gorilla_norm.png"
    }

    Image {
        id: imagePlayer1
        y: 283
        width: 408
        height: 154
        anchors.left: rectanglePlayer1.right
        anchors.leftMargin: -408
        anchors.bottom: rectanglePlayer1.top
        anchors.bottomMargin: 69
        fillMode: Image.PreserveAspectFit
        source: "gorilla_left.png"
        opacity: 0
    }

    Image {
        id: imagePlayer2
        x: 782
        y: 283
        width: 408
        height: 154
        anchors.bottom: rectanglePlayer2.top
        anchors.bottomMargin: 69
        anchors.right: rectanglePlayer2.left
        anchors.rightMargin: -408
        fillMode: Image.PreserveAspectFit
        source: "gorilla_right.png"
        opacity: 0
    }

    states: [
        State {
            name: "statePlayer"

            PropertyChanges {
                target: textWelcome
                x: 0
                y: 54
                width: 1280
                height: 666
                text: qsTr("PLAYERS")
                anchors.topMargin: 54
            }

            PropertyChanges {
                target: rectanglePlay
                visible: true
            }

            PropertyChanges {
                target: rectangleQuit
                visible: true
            }

            PropertyChanges {
                target: imageWelcome
                visible: false
            }

            PropertyChanges {
                target: textPlayer1
                visible: true
            }

            PropertyChanges {
                target: textPlay
                text: "START"
            }

            PropertyChanges {
                target: textQuit
                text: "RETURN"
            }

            PropertyChanges {
                target: mouseAreaQuit
                onClicked: {
                    rectangle1.state = '';
                }
            }

            PropertyChanges {
                target: mouseAreaPlay
                onClicked: gameStarted()
                    //rectangle1.state = 'stateGame'
            }

            PropertyChanges {
                target: textPlayer2
                visible: true
            }

            PropertyChanges {
                target: rectangleInputPlayer1
                visible: true
            }

            PropertyChanges {
                target: rectangleInputPlayer2
                visible: true
            }

            PropertyChanges {
                target: imagePlayer2
                x: 782
                y: 339
                width: 408
                height: 98
                fillMode: "PreserveAspectFit"
                opacity: 1
            }

            PropertyChanges {
                target: imagePlayer1
                x: 90
                y: 339
                width: 408
                height: 98
                anchors.topMargin: 339
                fillMode: "PreserveAspectFit"
                opacity: 1
            }

        },
        State {
            name: "stateGame"

            PropertyChanges {
                target: textWelcome
                visible: false
            }

            PropertyChanges {
                target: imageWelcome
                visible: false
            }

            PropertyChanges {
                target: rectanglePlay
                visible: false
            }

            PropertyChanges {
                target: rectangleQuit
                visible: false
            }

            PropertyChanges {
                target: rectanglePlayer2
                visible: false
            }

            PropertyChanges {
                target: rectanglePlayer1
                visible: false
            }
        }
    ]

}
