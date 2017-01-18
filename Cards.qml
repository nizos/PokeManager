import QtQuick 2.7
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0
import PokeApp.Classes.Core 1.0
import "./"

Item {
    id: cardsPage
    property int cId: 0
    property string fullScreenCard


    // Page
    Rectangle {
        id: cardsPageItem
        anchors.fill: parent
        color: '#ecf0f1'
        state: "GridView"

        Text {
            id: clickHandler
            property int receivedClick: 0
            text: receivedClick
        }

        Text {
            id: hoverEnterHandler
            property int receivedEnterHover: 0
            text: receivedEnterHover
        }

        Text {
            id: hoverExitHandler
            property int receivedExitHover: 0
            text: receivedExitHover
        }

        SubHeaderCards {}

        Item{
            id: cardsWrapper
            property string fullScreenView
            property string normalGridView
            x: 0;
            y: 0;
            Image {
                id: fullScreenCardImage
                source: fullScreenCard
                visible: false
                height: mainApp.height
                z: -1
            }

            states: [
                State {
                    name: "GridView"

                },
                State {
                    name: "FullScreen"
                }
            ]
//            Connections {
//                id: cardsWrapperConnection
//                target: cardsView
//                onClicked:
//                    print("Signal received!")

//            }
        }

        // Cards GridView
        GridView{
            property int cardsInAlbum: MyModel.rowCount()
            id: cardsGridView
            header:  Rectangle { height: 30 }
            footer: Rectangle {height: 80}
            anchors.top: parent.top
            anchors.topMargin: 70
            anchors.horizontalCenter: parent.horizontalCenter
            width: Math.min(cardsInAlbum, Math.floor(parent.width/cellWidth))*cellWidth
            height: parent.height
            cellHeight: 350
            cellWidth: 253
            model: MyModel
            clip: true
            delegate: CardsView {id: cardsView}
            z: 0
        }

        Item {
            Connections {
                target: MyModel
                onCardAdded:
                {
                    cardsGridView.cardsInAlbum = nrOfCards
                }
            }
        }


    }
}
