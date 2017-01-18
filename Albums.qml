import QtQuick 2.7
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0
import PokeApp.Classes.Core 1.0

Item {
    id: albumsPage

    // Page
    Rectangle {
        id: albumsPageItem
        anchors.fill: parent
        color: '#ecf0f1'

        SubHeaderAlbums {}

        // Albums GridView
        GridView{
            property int albumsInApp: MyAlbumsModel.rowCount()
            id: albumsGridView
            header:  Rectangle { height: 30 }
            footer: Rectangle {height: 80}
            anchors.top: parent.top
            anchors.topMargin: 70
            anchors.horizontalCenter: parent.horizontalCenter
            width: Math.min(albumsInApp, Math.floor(parent.width/cellWidth))*cellWidth
            height: parent.height
            cellHeight: 310
            cellWidth: 250
            model: MyAlbumsModel
            clip: true
            delegate: AlbumsView {}
            z: 0
        }
        Item {
            Connections {
                target: MyAlbumsModel
                onAlbumAdded:
                {
                    albumsGridView.albumsInApp = nrOfAlbums
                }
            }
        }
    }
}
