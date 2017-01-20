import QtQuick 2.0

Item {
    id: delegate
    width: 500
    height: 30
    clip: true
    anchors.margins: 4
    Row {
        anchors.margins: 4
        anchors.fill: parent
        spacing: 4;
        Text {
            text: model.cardMID
        }
        Text {
            text: model.albumMID
        }
        Text {
            text: model.imageURL
        }
        Text {
            text: model.artist
        }
        Text {
            text: model.name
        }
        Text {
            text: model.rarity
        }
    }
}
