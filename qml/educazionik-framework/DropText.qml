import QtQuick 2.2

DropArea {
    id: dragTarget

    property string value: ""
    property alias dropProxy: dragTarget
    property string answerText: ""

    width: 64; height: 64
    keys: [ value ]

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
            }
        ]
    }
}
