import QtQuick 2.0
import PokeApp.Classes.Core 1.0
import "./"

// Cards Deligate
Rectangle {
    id: cardsView
    signal cardClicked(string imageURL);
    function isCardLoaded()
    {
        if(model.loaded === false)
        {
            spinner.state = "Run"
            cardPic.state = "Loading"
        }
        if(model.loaded === true)
        {
            spinner.state = "End"
            cardPic.state = "Loaded"
        }
    }

    Image {
        id: dummyPic
        source: "qrc:/gui/GUI/emptyCard.png"
        width: 245
        height: 342
        cache: false
        visible: false
        AnimatedImage {
            id: spinner
            source: "qrc:/gui/GUI/pokeLoader100.gif"
            visible: false
            anchors.centerIn: parent
            height: 100
            width: 100
            cache: false
            opacity: 1
//            z: 5
            states: [
                State {
                    name: "Run"
                    PropertyChanges { target: spinner; opacity: 1 }
                    PropertyChanges { target: spinner; visible: true }
                    PropertyChanges { target: dummyPic; visible: true }
                },
                State {
                    name: "End"
                    PropertyChanges { target: spinner; opacity: 0 }
                    PropertyChanges { target: spinner; height: 250 }
                    PropertyChanges { target: spinner; width: 250 }
                }
            ]
            transitions: [
                Transition {
                    from: "Run"; to: "End"
                    NumberAnimation  { target: spinner; property: "opacity"; easing.type: Easing.InOutQuad; duration: 2000 }
                    NumberAnimation  { target: spinner; property: "height"; easing.type: Easing.InOutQuad; duration: 2000 }
                    NumberAnimation  { target: spinner; property: "width"; easing.type: Easing.InOutQuad; duration: 2000 }
                } ]
        }
    }

    Image {
        id: cardPic
        source: "image://rip/" + model.imageURL
        width: 245
        height: 342
        opacity: 1
        cache: false
        visible: true
        state: "Loaded"
        Text{
            text: "Card here"
            anchors.centerIn: parent.Center
        }

        states: [
            State {
                name: "Loading"
                PropertyChanges { target: cardPic; opacity: 0 }
            },
            State {
                name: "Loaded"
                PropertyChanges { target: cardPic; opacity: 1 }
            }
        ]
        transitions: [
            Transition {
                from: "Loading"; to: "Loaded"
                NumberAnimation  { target: cardPic; property: "opacity"; easing.type: Easing.InOutQuad; duration: 2000 }
            } ]





        Item {
            Connections {
                target: albumsSQLManager
                onCardUpdated:
                {
                    cardsView.isCardLoaded();
                }
            }
        }
    }
}
