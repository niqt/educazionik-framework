import QtQuick 2.0
import QtQuick.XmlListModel 2.0
import QtQuick.Controls 1.1

import "."


Rectangle {
    width: 1024
    height: 1024


    Grid {
        id: signs
        columns: 3
        spacing: 30
        anchors.horizontalCenter: parent.horizontalCenter

        DragText {
            id: minorDrag
            textItem: "<"
        }
        DragText {
            id: equalDrag
            textItem: "="
        }


        DragText {
            id: greaterDrag
            textItem: ">"
        }

    }

    Grid {
        id:sets
        anchors.top: signs.bottom
        columns: 3
        spacing: signs.width
        anchors.horizontalCenter: parent.horizontalCenter
        Set {
            id: a
            //x:0
            //y:0
        }
        DropText {
            id: answer
            answerText: "?"
        }


        Set {
            //y: 0
            //x:400
            id: b
        }
    }
    Button {
        id: nextButton
        text: "Prossimo"
        onClicked: {

            minorDrag.init();
        }
    }
    ListView {
        anchors.top: sets.bottom
        model: setexercise.setA();
        width: 400
        height: 400
        delegate: Rectangle {

        height: 25
            width: 100

            Text { text: modelData.value }
        }
    }
}
