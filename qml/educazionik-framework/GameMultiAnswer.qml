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
