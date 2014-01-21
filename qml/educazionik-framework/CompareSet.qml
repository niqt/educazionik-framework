import QtQuick 2.0
import QtQuick.XmlListModel 2.0

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
            textItem: "<"
        }



        Text {
            id: max
            text: "="
            font.pixelSize: 40
        }
        Text {
            id: eq
            text: "="
            font.pixelSize: 40
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

}
