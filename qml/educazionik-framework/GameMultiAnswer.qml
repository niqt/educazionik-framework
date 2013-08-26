import QtQuick 2.1
import QtQuick.Controls 1.0


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
        width: 180; height: 200
        anchors.top: questionText.bottom
        anchors.centerIn: parent

        Component {
            id: contactsDelegate

            Button {

                id: wrapper
                width: 180

                text: logic.answer(index)
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
    }
}
