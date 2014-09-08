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

import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Private 1.0
import QtQuick.Controls.Styles 1.0

Rectangle {

    Text {
        id: questionText
        anchors.top: parent.top
        text: logic.question
        anchors.left: parent.left
        anchors.right: parent.right
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 24
    }



    ListView {
        id: buttons
        width: 180; height: 300
        anchors.top: questionText.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin:  10
        Component {
            id: contactsDelegate

            Button {
                width: 280

                id: wrapper
                text: ""
                style: ButtonStyle {
                        label: Label {
                                font.pointSize: 24
                                text: modelData
                                horizontalAlignment: Text.AlignHCenter
                            }
                        }
                onClicked:  {
                    logic.test(modelData);
                    wrapper.enabled = false;
                    wrapper.opacity = 0.5
                }

            }
        }

        model: logic.answers();
        delegate: contactsDelegate
        focus: true
    }

    Text {
        id: corrects
        text: logic.corrects
        anchors.top : buttons.bottom
        anchors.left: parent.left
        font.pointSize: 24
    }

    Text {
        id: wrongs
        text: logic.wrongs
        anchors.top : buttons.bottom
        anchors.right: parent.right
        font.pointSize: 24
    }


    Button {

        id: next

        anchors.top: buttons.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        text: "Prossimo"
        style: ButtonStyle {
                label: Label {
                        id: label
                        font.pointSize: 24
                        text: next.text
                        horizontalAlignment: Text.AlignHCenter
                    }
                }



        onClicked:  {
            logic.next();
            buttons.model = logic.answers();
            for (var counter = 0; counter < logic.answersNumber(); counter++) {
                buttons.currentIndex = counter;
                buttons.currentItem.enabled = true;
                buttons.currentItem.opacity = 1;
                //buttons.currentItem.text = logic.answer(counter);
            }

        }
    }


}
