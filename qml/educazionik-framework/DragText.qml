import QtQuick 2.0

Item {
    id: root
    property string colorKey
    property string textItem: ""
    property bool enabledrag: true


    width: 64; height: 64

    MouseArea {
        id: mouseArea

        width: 64; height: 64
        anchors.centerIn: parent

        drag.target: tile
        enabled: true
        onReleased: {
            console.log("release");
            if (tile.Drag.target !== null) {
                parent = tile.Drag.target;

                console.log("!null "+ tile.Drag.target);
                mouseArea.enabled = false;
                //enabledrag = false;
            } else {
                parent =  root;
                console.log("pp "+ tile.Drag.target);
            }
        }
        onClicked: {
            console.log("click");
        }


        Rectangle {
            id: tile
            border.color: "green"
            width: 64; height: 64
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

            //color: colorKey

            Drag.keys: [ colorKey ]
            Drag.active: mouseArea.drag.active
            Drag.hotSpot.x: 32
            Drag.hotSpot.y: 32
//! [0]
            Text {
                anchors.fill: parent

                font.pixelSize: 48
                text: textItem
                horizontalAlignment:Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
//! [1]
            states: [
                State {
                name: "dragState"
                when: mouseArea.drag.active
                ParentChange { target: tile; parent: root }
                AnchorChanges { target: tile; anchors.verticalCenter: undefined; anchors.horizontalCenter: undefined }
            }
            ]

        }
    }
    function init() {
        mouseArea.parent = root;
        mouseArea.enabled = true;
        //mouseArea.enabled = true;
        //tile.Drag.active = mouseArea.drag.active;
        //mouseArea.drag.target = tile;
        //mouseArea.anchors.centerIn = parent;
    }
}
