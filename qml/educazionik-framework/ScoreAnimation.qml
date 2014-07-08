import QtQuick 2.2

Rectangle {
    id: rect
    width: 100; height: 100

    Image {
        id: img
        source: "qrc:///images/ok.jpg"
        width: 0
        height: 0
    }

    SequentialAnimation {
        running: true
        NumberAnimation { target: img; property: "width"; to: 150; duration: 500 }
        NumberAnimation { target: img; property: "height"; to: 150; duration: 500 }

    }
}
