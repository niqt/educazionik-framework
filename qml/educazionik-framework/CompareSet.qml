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

import QtQuick 2.2
import QtQuick.XmlListModel 2.0
import QtQuick.Controls 1.1
import QtQuick.Window 2.0
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
            value: "<"
            onDropped: {
                console.log("DROPPED")
                score.esatto();
            }
            onNoDropped: {
                console.log("NODROPPED")
                score.errato();
            }
        }
        DragText {
            id: equalDrag
            textItem: "="
            value: "="
            onDropped: {
                console.log("DROPPED")
                score.esatto();
            }
            onNoDropped: {
                console.log("NODROPPED")
                score.errato();
            }
        }


        DragText {
            id: greaterDrag
            textItem: ">"
            value: ">"
            onDropped: {
                console.log("DROPPED")
                score.esatto();
            }
            onNoDropped: {
                console.log("NODROPPED")
                score.errato();
            }
        }

    }

   /* Grid {
        id:sets
        anchors.top: signs.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        columns: 3
        spacing: 3
        //anchors.horizontalCenter: parent.horizontalCenter*/
        Set {
            id: a
            set: setexercise.setA()
            width: Screen.width / 8
            height: Screen.height / 6
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            //x:0
            //y:0
        }
        DropText {
            id: answer
            answerText: "?"
            value: "="
            //anchors.top: signs.bottom
             anchors.horizontalCenter: parent.horizontalCenter
             anchors.verticalCenter: parent.verticalCenter
             onDropped: {
                 console.log("Dropped")

             }
        }


        Set {
            //y: 0
            //x:400
            id: b
            width: Screen.width / 8
            height: Screen.height / 6
            set: setexercise.setB()
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
        }
    //}
    Button {
        id: nextButton
        text: "Prossimo"
        onClicked: {
            equalDrag.init();
            minorDrag.init();
            greaterDrag.init();
        }
    }
    Score {
        id: score
        width: parent.width
        height: Screen.height / 10
        anchors.bottom: parent.bottom
    }

    ScoreAnimation {
        id: scoreAnimation
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }
}
