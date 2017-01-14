import QtQuick 2.0

Item {
    id: thumbnail
    state: "disabled"
    property bool enableThumbNail: false
    property string imageSource
    property int imageHeight
    property int imageWidth
    property bool imageAntiAliasing: true
    property double randomAngle: Math.random() * (2 * 16 + 1) -16
    function showThumnail(enableThumbNail)
    {
        if(thumbnail.enableThumbNail == false)
        {
            thumbnail.state = "disabled"
        }
        if(thumbnail.enableThumbNail == true)
        {
            thumbnail.state = "enabled"
            thumbnailEnabled.source = thumbnail.imageSource
        }
    }
    onStateChanged: showThumnail(enableThumbNail)
    Image {
        id: thumbnailDisabled
        visible: true
        width: thumbnail.imageWidth
        height: thumbnail.imageHeight
        antialiasing: thumbnail.imageAntiAliasing
        rotation: thumbnail.randomAngle
        anchors.centerIn: parent
    }
    Image {
        id: thumbnailEnabled;
        visible: false
        height: thumbnail.imageHeight
        width: thumbnail.imageWidth
        antialiasing: thumbnail.imageAntiAliasing
        rotation: thumbnail.randomAngle
        anchors.centerIn: parent
    }
    Component.onCompleted: showThumnail(enableThumbNail)
    states: [
        State {
            name: "disabled"
            PropertyChanges { target: thumbnailDisabled; visible: true }
            PropertyChanges { target: thumbnailEnabled; visible: false }
        },
        State {
            name: "enabled"
            PropertyChanges { target: thumbnailDisabled; visible: false }
            PropertyChanges { target: thumbnailEnabled; visible: true }
            PropertyChanges { target: thumbnailEnabled; source: thumbnail.imageSource }
        }
    ]
}
