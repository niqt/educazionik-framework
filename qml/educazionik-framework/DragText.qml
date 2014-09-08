/*
* This file is part of educazionik-framework
*
* Copyright (C) 2014 Nicola De Filippo.
*
* Contact: Nicola De Filippo <nicola@nicoladefilippo.it> or <nicola.defilippo@lizard-solutions.com>
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public License
* version 2.1 as published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
* 02110-1301 USA
*
*/

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
