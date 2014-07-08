import QtQuick 2.0

Item {
    id: root
    property string value: ""
    property string textItem: ""
    property bool enabledrag: true


    width: 64; height: 64

    signal dropped()
    signal noDropped()

    MouseArea {
        id: mouseArea

        width: 64; height: 64
        anchors.centerIn: parent

        drag.target: tile
        enabled: true
        onReleased: {
            if (tile.Drag.target !== null) {
                parent = tile.Drag.target;
                mouseArea.enabled = false;
                root.dropped()
            } else {
                parent =  root;
                root.noDropped()
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


            Drag.keys: [ value ]
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

    }
}
