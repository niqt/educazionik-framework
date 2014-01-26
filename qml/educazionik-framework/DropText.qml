import QtQuick 2.0

DropArea {
    id: dragTarget

    property string colorKey
    property alias dropProxy: dragTarget
    property string answerText: ""

    width: 64; height: 64
    keys: [ colorKey ]

    Rectangle {
        id: dropRectangle

        anchors.fill: parent
        //color: colorKey

        Text {
            id: answer
            text: answerText
            font.pixelSize: 48
        }


        states: [
            State {
                when: dragTarget.containsDrag
                PropertyChanges {
                    target: dropRectangle
                    color: "white"

                }
                /*PropertyChanges {
                    target: dragTarget.drag.source


                }*/
            }
        ]
    }
}
