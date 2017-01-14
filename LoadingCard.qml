import QtQuick 2.0

Image {
    id: emptyCard
    property bool on: false
    visible: emptyCard.on
    source: "qrc:/gui/GUI/emptyCard.png"
    width: 245
    height: 342

    Image {
        id: container
        anchors.centerIn: parent
        source: "qrc:/gui/GUI/busy.png"; visible: emptyCard.on
        NumberAnimation on rotation { running: emptyCard.on; from: 0; to: 360; loops: Animation.Infinite; duration: 1200 }
    }

}
