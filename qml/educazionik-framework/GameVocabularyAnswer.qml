import QtQuick 2.1

import QtQuick.Controls 1.0
import QtQuick.Controls.Private 1.0
import QtQuick.Controls.Styles 1.0

Rectangle {
    id: mainRect
    width: 500
    height: 600

    ListView {
        width: 620; height: 50
        id: consonants
        orientation: ListView.Horizontal
        Component {
            id: delegate
            Rectangle {
                width: 30; height: 30

                Button {
                    width: 30
                    text: letter
                    id:l
                    onClicked: {
                        syllabe.model = sons1.split(",");

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


    ListView {
        width: 120; height: 50
        id: voice
        orientation: ListView.Horizontal
        anchors.top: consonants.bottom
        anchors.left: parent.left
        anchors.leftMargin: 30
        Component {
            id: voiceDelegate
            Rectangle {
                width: 30; height: 30

                Button {
                    width: 30
                    text: letter
                    id:l
                    onClicked: {
                        //syllabe.model = sons1.split(",");

                    }
                }


            }
        }

        model: VoiceModel {}
        delegate: voiceDelegate
    }


    Rectangle {
        id: sub2
        width: 380; height: 30
        anchors.top: voice.bottom
        border.color:  "black"


        ListView {
            id: syllabe
            orientation: ListView.Horizontal
            width: 380; height: 30
            Component {
                id: a
                Button {
                    width: 40; height: 20
                    text: modelData
                }
            }
            delegate: a
            model: ""
        }
    }

    Rectangle {
        id: sub22
        width: 380; height: 30
        anchors.top: sub2.bottom
        border.color:  "green"


        ListView {
            id: syllabe2
            orientation: ListView.Horizontal
            width: 380; height: 30
            Component {
                id: row2
                Button {
                    width: 40; height: 20
                    text: modelData
                }
            }
            delegate: row2
            model: ""
        }
    }


    Rectangle {
        id: sub3
        anchors.top: sub22.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: mainRect.bottom
        anchors.topMargin: 10
        //height: 100
        border.color:  "red"
        Button {
            id: ascolta
            text: "Ascolta"
            anchors.left: parent.left
        }
        Button {
            id: verifica
            text: "Verifica"
            anchors.right: parent.right
        }
        ListView {
            width: sub3.width
            height: 300
            anchors.top: ascolta.bottom
            id: corrects
            model: ["a","b"]
            delegate: Text {
                text: modelData
            }
        }
    }


}


