import QtQuick 2.0

Item {
    id: thumbnail
    property string imageSource
    property int imageHeight
    property int imageWidth
    property bool showThumbNail: true
    property bool imageAntiAliasing: true
    property double randomAngle: Math.random() * (2 * 16 + 1) -16
    Image {
        source: thumbnail.imageSource
        width: thumbnail.imageWidth
        height: thumbnail.imageHeight
        visible: thumbnail.showThumbNail
        antialiasing: thumbnail.imageAntiAliasing
        rotation: thumbnail.randomAngle
        anchors.centerIn: parent
    }
}
