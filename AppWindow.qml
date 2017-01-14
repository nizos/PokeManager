import QtQuick 2.7
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0
import PokeApp.Classes.Core 1.0

Rectangle {
    id: appWindow
    property int indexC: 0
    property int currentAlbum: 1001
    signal message(int indexC)
    width: parent.width
    height: parent.height
    anchors.fill: parent


    // SWIPEVIEW
    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: 0

        // Navigation Pages
        Home {}
        Library {}
        Albums {}
        Cards {}
    }

    // HEADER
    Rectangle {
        id: tabBar
        height: 40
        width: parent.width
        color: "#2c3e50"
        RowLayout {
            spacing: 0
            anchors.fill: parent
            HeaderButton {
                buttonText: "Home"
                height: 40
                width: (appWindow.width/4)
                implicitWidth: 60
                Layout.preferredWidth: (appWindow.width/4)
                onClicked: swipeView.currentIndex = 0
            }

            HeaderButton {
                buttonText: "Library"
                height: 40
                width: (appWindow.width/4)
                implicitWidth: 60
                Layout.preferredWidth: (appWindow.width/4)
                onClicked: swipeView.currentIndex = 1
            }

            HeaderButton {
                buttonText: "Albums"
                height: 40
                width: (appWindow.width/4)
                implicitWidth: 60
                Layout.preferredWidth: (appWindow.width/4)
                onClicked: swipeView.currentIndex = 2
            }

            HeaderButton {
                buttonText: "Cards"
                height: 40
                width: (appWindow.width/4)
                implicitWidth: 60
                Layout.preferredWidth: (appWindow.width/4)
                onClicked: swipeView.currentIndex = 3
            }
        }
        Rectangle {
            id: tabBarDecoration
            height: 3
            width: mainWindow.width
            color: "black"
            anchors.top: tabBar.bottom
            visible: true
        }
    }
    PageIndicator {
        id: pageIndicator
        currentIndex: swipeView.currentIndex
        count: swipeView.count
        visible: false
        onCurrentIndexChanged: {
            appWindow.indexC = currentIndex
            message(appWindow.indexC)
        }
    }
}
