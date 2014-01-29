import QtQuick 2.0






Rectangle {
    //width: 400
    //height: 400
    color: "black"
    property variant set: null;
    property int nRows: 3
    property int nColumns: 2
    Grid {
        x: parent.x + 5
        y: parent.y + 5
        rows: nRows
        columns: nColumns
        spacing: 10
        anchors.fill: parent
        Repeater {
            id: repeater
            model: set
            Rectangle {
                width: ((parent.width / nColumns ) - ((nColumns - 1) * 10))
                height: 200
                color: "lightgreen"

                Text {

                    text:  modelData.value
                    font.pixelSize: 30
                    anchors.centerIn: parent
                    visible: (modelData.type == "text")
                }
                Image {
                    id: name
                    source: ((modelData.type == "image")?"/tmp/"+ modelData.value: "")
                    visible: (modelData.type == "image")
                }

            }
            Component.onCompleted: {
                var i;
                for (i = 0; i < setexercise.setASize(); i++)
                   console.log(i);
            }
        }
    }
}

