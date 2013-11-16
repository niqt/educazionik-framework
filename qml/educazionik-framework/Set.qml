import QtQuick 2.0




Item {
    id: set

Rectangle {
    width: 400
    height: 400
    color: "black"

    var component;
    var setItem;

    function createItemObjects() {
        component = Qt.createComponent("SetItem.qml");
        if (component.status == Component.Ready)
            finishCreation();
        else
            component.statusChanged.connect(finishCreation);
    }

    function finishCreation() {
        if (component.status == Component.Ready) {
            setItem = component.createObject(repeater, {"x": 100, "y": 100});
            if (setItem == null) {
                // Error Handling
                console.log("Error creating object");
            }
        } else if (component.status == Component.Error) {
            // Error Handling
            console.log("Error loading component:", component.errorString());
        }
    }


    Grid {
        x: 5
        y: 5
        rows: 5
        columns: 5
        spacing: 10

        Repeater {
            id: repeater
            model: 24
            Rectangle {
                width: 70
                height: 70
                color: "lightgreen"

                Text {
                    text: index
                    font.pointSize: 30
                    anchors.centerIn: parent
                }
            }
            Component.onCompleted: {
                for (i = 0; i < repeater.model; i++)
                    set.createItemObjects();
            }
        }
    }
}
}
