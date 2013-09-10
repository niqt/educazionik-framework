import QtQuick 2.1
import QtQuick.Controls 1.0

Item {
    width: 1024
    height: 768
    Loader {
        id: pageLoader
        anchors.fill: parent
    }
    Component.onCompleted :{
        logic.start();
        pageLoader.source = "GameVocabularyAnswer.qml";
    }




}
