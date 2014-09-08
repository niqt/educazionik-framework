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
    id: mainRect
    anchors.left: parent.left
    anchors.right: parent.right

    property int withButton: 60
    property int heightButton: 40
    property variant colors: ["red", "green", "yellow", "orange", "blue", "black", "steelblue"]
    property int headFontSize: 24

    Text {
        id: head1
        text: "Consonanti"
        anchors.top: parent.top
        font.pointSize: headFontSize
        anchors.bottomMargin: 10
    }

    ListView {
        anchors.top: head1.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: 70
        id: consonants
        orientation: ListView.Horizontal
        Component {
            id: delegate
            Rectangle {
                width: withButton; height: heightButton

                Button {
                    width: withButton
                    height: heightButton
                    text: letter
                    id:l
                    onClicked: {
                        syllabeHead.visible = true;

                        var son = letter + "," + sons1
                        syllabeList.model = son.split(",");

                        syllabe2.model = "";
                        if (sons2 != "")
                            syllabe2.model = sons2.split(",");
                    }
                }


            }
        }

        model: ConsonantsModel {}
        delegate: delegate
    }


    Text {
        id: head2
        text: "Vocali"
        font.pointSize: headFontSize
        anchors.top: consonants.bottom
        anchors.bottomMargin: 10
    }

    ListView {
        height: 70
        id: voice
        orientation: ListView.Horizontal
        anchors.top: head2.bottom
        anchors.left: parent.left
        anchors.leftMargin: 60
        anchors.right: parent.right

        Component {
            id: voiceDelegate
            Rectangle {
                width: withButton; height: 70

                Button {
                    width: withButton
                    height: heightButton
                    text: letter
                    id:l
                    onClicked: {

                        wordModel.append({"text" : letter})
                        leftRow.enabled = true;
                    }
                }


            }
        }

        model: VoiceModel {}
        delegate: voiceDelegate
    }

    Text {
        id: syllabeHead
        text: "Sillabe"
        font.pointSize: headFontSize
        anchors.top: voice.bottom
        anchors.bottomMargin: 10
        visible: false
    }


    Rectangle {
        id: sub2
        width: 380; height: 60
        anchors.top: syllabeHead.bottom
        //border.color:  "black"

        ListView {
            id: syllabeList
            orientation: ListView.Horizontal

            width: 380; height: 40
            Component {
                id: a
                Button {
                    width: withButton
                    height: heightButton
                    text: modelData
                    onClicked: {
                        wordModel.append({"text" : modelData})
                        leftRow.enabled = true;
                    }
                }
            }
            delegate: a
            model: ""
        }
    }

    Rectangle {
        id: sub22
        height: 70
        anchors.top: sub2.bottom
        //border.color:  "green"
        anchors.left: voice.left
        anchors.right: parent.right

        ListView {
            id: syllabe2
            orientation: ListView.Horizontal
            width: parent.width; height: 70


            Component {
                id: row2
                Button {

                    width: withButton
                    height: heightButton
                    text: modelData
                    onClicked: {
                        wordModel.append({"text" : modelData})
                        leftRow.enabled = true;
                    }
                }
            }
            delegate: row2
            model: ""
        }
    }


    Rectangle {
        id: command
        height: 40
        anchors.top: sub22.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.topMargin: 10
        //border.color:  "red"

        Button {
            id: leftRow
            text: "Elimina"
            anchors.left: parent.left
            enabled: false
            onClicked: {
                wordModel.remove(wordModel.count - 1);

                if (wordModel.count == 0)
                    leftRow.enabled = false;

            }
        }


        ListView {
            id: word
            orientation: ListView.Horizontal

            anchors.left: leftRow.right
            anchors.right: rightRow.left
            anchors.leftMargin: 30
            anchors.rightMargin: 30

            model: ListModel {
                id: wordModel

            }

            delegate: Text {
                text: modelData
                font.pointSize: 18
                color: colors[((index < 0)?0:index) % colors.length]
            }
        }


        Button {
            id: rightRow
            text: "Right"
            anchors.right: parent.right
            enabled: false
        }

    }

    Rectangle {
        id: sub3
        anchors.top: command.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: mainRect.bottom
        anchors.topMargin: 10

        //border.color:  "red"
        Button {
            id: ascolta
            text: "Ascolta"
            anchors.left: parent.left
            enabled: false
        }
        Button {
            id: verifica
            text: "Verifica"
            anchors.right: parent.right
            onClicked: {
                var insertedWord = "";
                for (var i = 0; i < wordModel.count; i++)
                    insertedWord += wordModel.get(i).text;

                if (vocabulary.answerFounded(insertedWord)) {
                    correctsModel.append({"text" : insertedWord})
                    wordModel.clear();
                    leftRow.enabled = false;
                }

            }
        }


        Text {
            id: head4
            text: "Parole Esatte"
            font.pointSize: headFontSize
            anchors.top: ascolta.bottom
            anchors.bottomMargin: 10
        }


        ListView {
            width: sub3.width
            height: 300
            anchors.top: head4.bottom
            id: corrects
            model: ListModel {
                id: correctsModel

            }

            delegate: Text {
                text: modelData

            }
        }
    }


}


