import QtQuick 2.0



Rectangle {
    width: 100
    height: 10



    ListView {
        Component {
            id: delegate
            Rectangle {
                width: 180; height: 200

            Text {
                text: letter
            }

            ListView {
                model: sons
            }
        }
        }
        width: 180; height: 200
        model: VocabularyModel {}
        delegate: delegate
    }

}
