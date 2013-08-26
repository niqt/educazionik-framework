import QtQuick 2.1
import QtQuick.Controls 1.0

Rectangle {
    width: 360
    height: 360
    Component.onCompleted :{
        logic.start();
        buttons.model = logic.answersNumber();
    }

    Text {
        text: logic.question
        anchors.centerIn: parent
    }

    ListView {
        id: buttons
        width: 180; height: 200

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
                    console.log("jj")
                }
            }
        }

        model: 0
        delegate: contactsDelegate
        focus: true
    }

    Text {
        text: logic.corrects
    }

}
