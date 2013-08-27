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
        anchors.centerIn: parent

        Component {
            id: contactsDelegate

            Button {
                width: 180
                id: wrapper


                text: logic.answer(index)
                style: ButtonStyle {
                        label: Label {
                                font.pointSize: 24
                                text: wrapper.text
                                horizontalAlignment: Text.AlignHCenter
                            }
                        }
                onClicked:  {
                    logic.test(wrapper.text);
                    wrapper.enabled = false;
                    wrapper.opacity = 0.5
                }
            }
        }

        model: logic.answersNumber()
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
                        font.pointSize: 24
                        text: next.text
                        horizontalAlignment: Text.AlignHCenter
                    }
                }



        onClicked:  {
            logic.next();
            for (var counter = 0; counter < logic.answersNumber(); counter++) {
                buttons.currentIndex = counter;
                buttons.currentItem.enabled = true;
                buttons.currentItem.opacity = 1;
            }
        }
    }


}
