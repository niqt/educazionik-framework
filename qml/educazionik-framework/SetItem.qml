import QtQuick 2.0

Item {
    property int typeChild: 0
    Rectangle {
        width: 100
        height: 62

        Image {
            id: nameImg
            source: "file"
            visible: {typeChild == 1}
        }

        Text {
            id: nameText
            text: qsTr("text")
            visible: {typeChild == 0}
        }
    }
}
