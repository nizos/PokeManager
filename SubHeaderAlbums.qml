import QtQuick 2.0
import PokeApp.Classes.Core 1.0

Item {
    id: subHeaderItem
    property int receivedValue: 0
    anchors.top: parent.top
    anchors.right: parent.right
    anchors.left: parent.left
    z: 8

    // Sub Header
    Rectangle {
        id: subHeader
        property int subHeaderAnimDuration: 500
        property int subHeaderWidth: parent.width
        property int subHeaderHeight: 80
        property int subHeaderSeizurWidth: 15
        property bool subHeaderVisible: Math.abs(subHeaderMenuView.y) < (30) ? true : false
        anchors.fill: parent
        color: 'transparent'
        z: 8

        // SLIDING MENU
        Rectangle {
            id: subHeaderMenuView
            height: subHeader.subHeaderHeight
            width: subHeader.subHeaderWidth
            y: -subHeader.subHeaderHeight
            z: 8

            // CONTENT
            SubHeaderAlbumsMenu {
                id: subHeaderMenu
                anchors.fill: parent
            }

            // ANIMATION
            Behavior on y { NumberAnimation { duration: subHeader.subHeaderAnimDuration; easing.type: Easing.OutQuad } }
        }

        // EDGE SHADOW
        Image {
            id: subHeaderShadow
            source: "qrc:/gui/GUI/subMenuShadow.png"
            visible: subHeaderMenuView.y != -subHeader.subHeaderHeight
            anchors.top: subHeaderMenuView.bottom
            anchors.right: subHeader.right
            anchors.left: subHeader.left
            height: 5
            z: 8
        }
    }

    // TOGGLE SLIDE MENU FUNCTION
    function menuToggle() {
        if (subHeaderItem.receivedValue == 2)
            subHeaderMenuView.y = 0
        if (subHeaderItem.receivedValue != 2)
            subHeaderMenuView.y = -subHeader.subHeaderHeight;
    }

    // Connection
    Connections {
        id: cardsConnecttion
        target: pageIndicator
        onCurrentIndexChanged: {
            subHeaderItem.receivedValue = appWindow.indexC
            subHeaderItem.menuToggle()}
    }

}
