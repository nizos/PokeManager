import QtQuick 2.0
import PokeApp.Classes.Core 1.0

// Albums Deligate
Item {
    id: albumsDeligate
    Rectangle {
        id: album
        property int totalCards: model.nrOfCards
        property int stackedCards: model.nrOfCards
        height: 400
        width: 300
        color: 'Transparent'
        property string cardOne: model.cardOneInAlbum
        property string cardTwo: model.cardTwoInAlbum
        property string cardThree: model.cardThreeInAlbum
        property string cardFour: model.cardFourInAlbum

        function showThumbnails(totalCards)
        {
            if(album.totalCards < 1)
            {
                thumbnail1.showThumbNail = false;
                thumbnail2.showThumbNail = false;
                thumbnail3.showThumbNail = false;
                thumbnail4.showThumbNail = false;
            }
            if(album.totalCards == 1)
            {
                thumbnail1.showThumbNail = true;
                thumbnail2.showThumbNail = false;
                thumbnail3.showThumbNail = false;
                thumbnail4.showThumbNail = false;
            }
            if(album.totalCards == 2)
            {
                thumbnail1.showThumbNail = true;
                thumbnail2.showThumbNail = true;
                thumbnail3.showThumbNail = false;
                thumbnail4.showThumbNail = false;
            }
            if(album.totalCards == 3)
            {
                thumbnail1.showThumbNail = true;
                thumbnail2.showThumbNail = true;
                thumbnail3.showThumbNail = true;
                thumbnail4.showThumbNail = false;
            }
            if(album.totalCards >= 4)
            {
                thumbnail1.showThumbNail = true;
                thumbnail2.showThumbNail = true;
                thumbnail3.showThumbNail = true;
                thumbnail4.showThumbNail = true;
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
                    anchors.centerIn: parent
                }
                ThumbNail {
                    id: thumbnail2
                    imageHeight: 209
                    imageWidth: 150
                    imageSource: album.cardTwo
                    anchors.centerIn: parent
                }
                ThumbNail {
                    id: thumbnail3
                    imageHeight: 209
                    imageWidth: 150
                    imageSource: album.cardThree
                    anchors.centerIn: parent
                }
                ThumbNail {
                    id: thumbnail4
                    imageHeight: 209
                    imageWidth: 150
                    imageSource: album.cardFour
                    anchors.centerIn: parent
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
                            mainApp.albumsardsModel.showAlbum(model.albumId);
                            swipeView.currentIndex = 3;
                            appWindow.currentAlbum = model.albumId;
                        }
                    }
                }


            }


        }

    }

}
