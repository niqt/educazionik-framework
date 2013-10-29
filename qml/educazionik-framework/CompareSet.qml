import QtQuick 2.0
import QtQuick.XmlListModel 2.0

Rectangle {
    width: 1024
    height: 768


    XmlListModel {
        id: xmlModel
        source: "sets.xml"
        query: "/sets/exercise/setA"

        XmlRole { name: "element"; query: "element/string()" }

    }

    ListView {
        width: 500; height: 300
        model: xmlModel
        delegate: Text { text: element  }
    }

}
