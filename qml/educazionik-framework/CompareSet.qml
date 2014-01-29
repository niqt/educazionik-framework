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
        anchors.left: parent.left
        anchors.right: parent.right
        columns: 3
        spacing: 30
        //anchors.horizontalCenter: parent.horizontalCenter
        Set {
            id: a
            set: setexercise.setA()
            width: parent.width / 3
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
            width: parent.width / 3
            set: setexercise.setB()
        }
    }
    Button {
        id: nextButton
        text: "Prossimo"
        onClicked: {

            minorDrag.init();
        }
    }

}
