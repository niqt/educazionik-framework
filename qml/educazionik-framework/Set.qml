import QtQuick 2.0






Rectangle {
    width: 200
    height: 200
    color: "black"
    property variant set: null;
    Grid {
        x: parent.x + 5
        y: parent.y + 5
        rows: 2
        columns: 2
        spacing: 10
        anchors.fill: parent
        Repeater {
            id: repeater
            model: 4
            Rectangle {
                width: 70
                height: 70
                color: "lightgreen"

                Text {
                    text: index
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
                Text {
                    text: index + "iffffffffffffffffff"
                    font.pointSize: 30
                    anchors.centerIn: parent
                    visible: false
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

