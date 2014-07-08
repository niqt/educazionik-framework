import QtQuick 2.0

Rectangle {
    width: 200
    height: 62

    Text {
        id: esattiText
        text: qsTr("0")
        anchors.left: parent.left
        font.pixelSize: parent.height
    }
    Text {
        id: erratiText
        text: qsTr("0")
        anchors.right: parent.right
        font.pixelSize: parent.height

    }
    function esatto() {
        var dum = Number(esattiText.text) + 1;
        esattiText.text = dum.toString();
    }
    function errato() {
        var dum = Number(erratiText.text) + 1;
        erratiText.text = dum.toString();
    }
}
