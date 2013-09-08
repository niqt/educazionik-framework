import QtQuick 2.1

import QtQuick.Controls 1.0
import QtQuick.Controls.Private 1.0
import QtQuick.Controls.Styles 1.0

Rectangle {
    id: mainRect
    width: 500
    height: 600

    ListView {
        width: 620; height: 50
        id: letters
        orientation: ListView.Horizontal
        Component {
            id: delegate
            Rectangle {
                width: 30; height: 30

                Button {
                    width: 30
                    text: letter
                    id:l
                    onClicked: {
                        syllabe.model = sons.split(",");

                    }
                }


            }
        }

        model: VocabularyModel {}
        delegate: delegate
    }


    Rectangle {
        id: sub2
        width: 380; height: 30
        anchors.top: letters.bottom
        border.color:  "black"


        ListView {
            id: syllabe
            orientation: ListView.Horizontal
            width: 380; height: 30
            Component {
                id: a
                Button {
                    width: 40; height: 20
                    text: modelData
                }
            }
            delegate: a
            model: ""
        }
    }


    Rectangle {
        id: sub3
        anchors.top: sub2.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: mainRect.bottom
        anchors.topMargin: 10
        //height: 100
        border.color:  "red"
        Button {
            id: ascolta
            text: "Ascolta"
            anchors.left: parent.left
        }
        Button {
            id: verifica
            text: "Verifica"
            anchors.right: parent.right
        }
        ListView {
            width: sub3.width
            height: 300
            anchors.top: ascolta.bottom
            id: corrects
            model: ["a","b"]
            delegate: Text {
                text: modelData
            }
        }
    }


}


