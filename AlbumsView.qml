import QtQuick 2.0
import PokeApp.Classes.Core 1.0

// Albums Deligate
Item {
    id: albumsDeligate
    Rectangle {
        id: album
        property int totalCards: model.nrOfCards
        height: 400
        width: 300
        color: 'Transparent'
        property string cardOne: model.cardOneInAlbum
        property string cardTwo: model.cardTwoInAlbum
        property string cardThree: model.cardThreeInAlbum
        property string cardFour: model.cardFourInAlbum
        property bool cardOneReady: model.cardOneLoaded
        property bool cardTwoReady: model.cardTwoLoaded
        property bool cardThreeReady: model.cardThreeLoaded
        property bool cardFourReady: model.cardFourLoaded

        function showThumbnails()
        {
            album.totalCards = model.nrOfCards
            album.cardOneReady = model.cardOneLoaded
            album.cardTwoReady = model.cardTwoLoaded
            album.cardThreeReady = model.cardThreeLoaded
            album.cardFourReady = model.cardFourLoaded
            thumbnail1.imageReady = model.cardOneLoaded;
            thumbnail2.imageReady = model.cardTwoLoaded;
            thumbnail3.imageReady = model.cardThreeLoaded;
            thumbnail4.imageReady = model.cardFourLoaded;
            if(album.totalCards < 1)
            {
                thumbnail1.enableThumbNail = false;
                thumbnail2.enableThumbNail = false;
                thumbnail3.enableThumbNail = false;
                thumbnail4.enableThumbNail = false;
            }
            if(album.totalCards == 1)
            {
                thumbnail1.enableThumbNail = true;
                thumbnail2.enableThumbNail = false;
                thumbnail3.enableThumbNail = false;
                thumbnail4.enableThumbNail = false;
            }
            if(album.totalCards == 2)
            {
                thumbnail1.enableThumbNail = true;
                thumbnail2.enableThumbNail = true;
                thumbnail3.enableThumbNail = false;
                thumbnail4.enableThumbNail = false;
            }
            if(album.totalCards == 3)
            {
                thumbnail1.enableThumbNail = true;
                thumbnail2.enableThumbNail = true;
                thumbnail3.enableThumbNail = true;
                thumbnail4.enableThumbNail = false;
            }
            if(album.totalCards >= 4)
            {
                thumbnail1.enableThumbNail = true;
                thumbnail2.enableThumbNail = true;
                thumbnail3.enableThumbNail = true;
                thumbnail4.enableThumbNail = true;
            }
        }
        Column {
            anchors.fill: parent
            width: 300
            Rectangle {
                id: thumbs
                height: 240
                width: 250
                color: 'Transparent'
                ThumbNail {
                    id: thumbnail1
                    imageHeight: 209
                    imageWidth: 150
                    imageSource: album.cardOne
                    imageReady: album.cardOneReady
                    anchors.centerIn: parent
                    enableThumbNail: false
                }
                ThumbNail {
                    id: thumbnail2
                    imageHeight: 209
                    imageWidth: 150
                    imageSource: album.cardTwo
                    imageReady: album.cardTwoReady
                    anchors.centerIn: parent
                    enableThumbNail: false
                }
                ThumbNail {
                    id: thumbnail3
                    imageHeight: 209
                    imageWidth: 150
                    imageSource: album.cardThree
                    imageReady: album.cardThreeReady
                    anchors.centerIn: parent
                    enableThumbNail: false
                }
                ThumbNail {
                    id: thumbnail4
                    imageHeight: 209
                    imageWidth: 150
                    imageSource: album.cardFour
                    imageReady: album.cardFourReady
                    anchors.centerIn: parent
                    enableThumbNail: false
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        mainApp.albumCardsModel.showAlbum(model.albumId);
                        swipeView.currentIndex = 3;
                        appWindow.currentAlbum = model.albumId;
                    }
                }
            }
            Component.onCompleted: album.showThumbnails()
            Rectangle {
                id: info
                color: "Transparent"
                height: 70
                width: 230
                Rectangle {
                    anchors.centerIn: parent
                    color: "#16a085"
                    width: 130
                    height: 55
                    Column {
                        anchors.fill: parent
                        anchors.topMargin: 10
                        Text {
                            text: model.albumName
                            font.pointSize: 12
                            anchors.horizontalCenter: parent.horizontalCenter
                        }
                        Text {
                            text: "Cards in album: " + model.nrOfCards
                            font.pointSize: 9
                            anchors.horizontalCenter: parent.horizontalCenter
                        }
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            mainApp.albumCardsModel.showAlbum(model.albumId);
                            swipeView.currentIndex = 3;
                            appWindow.currentAlbum = model.albumId;
                        }
                    }
                }
            }
        }
        Item {
            Connections {
                target: MyModel
                onCardAdded:
                {
                    album.showThumbnails();
                }
            }
            Connections {
                target: MyModel
                onCardUpdated:
                {
                    album.showThumbnails();
                }
            }
            Connections {
                target: MyAlbumsModel
                onCardUpdated:
                {
                    album.showThumbnails();
                }
            }
        }
    }
}
