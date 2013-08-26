import QtQuick 2.1
import QtQuick.Controls 1.0

Item {
    width: 720
    height: 360
    Loader {
        id: pageLoader
        anchors.fill: parent
    }
    Component.onCompleted :{
        logic.start();
        pageLoader.source = "GameMultiAnswer.qml";
    }




}
