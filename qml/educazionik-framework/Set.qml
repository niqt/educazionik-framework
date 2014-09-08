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


import QtQuick.Window 2.0



Rectangle {
    //width: 400
    //height: 400
    //width: Screen.width / 3
    //height: 200
    id: mainRect
    color: "grey"
    property variant set: null;
    property int nRows: 3
    property int nColumns: 2
    Grid {
        //x: parent.x + 5
        //y: parent.y + 5
        rows: nRows
        columns: nColumns
        spacing: 5
        anchors.fill: parent
        Repeater {
            id: repeater
            model: set
            Rectangle {
                width: mainRect.width / 2
                height: ((modelData.type == "text")?textElem.height:imgElem.height)
                //color: "lightgreen"
                //height: Screen.height / 2
                Text {
                    id: textElem
                    width: parent.width
                    text:  modelData.value
                    font.pixelSize: 30
                    //anchors.centerIn: parent
                    visible: (modelData.type == "text")
                }
                Image {
                    id: imgElem
                    source: ((modelData.type == "image")?"/tmp/"+ modelData.value: "")
                    visible: (modelData.type == "image")
                    width: mainRect.width / 2
                    fillMode: Image.PreserveAspectFit
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

