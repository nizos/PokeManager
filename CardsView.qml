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
        if(cardPic.displayed === true)
        {

        }
    }

    Image {
        id: dummyPic
        property bool on: true
        source: "qrc:/gui/GUI/emptyCard.png"
        width: 245
        height: 342
        visible: dummyPic.on
        AnimatedImage {
            id: spinner
            source: "qrc:/gui/GUI/pokeLoader100.gif"
            visible: dummyPic.on
            anchors.centerIn: parent
            height: 100
            width: 100
            opacity: 1
            states: [
                State {
                    name: "Run"
                    PropertyChanges { target: spinner; opacity: 1 }
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
        visible: true
//        state: "Loaded"
//        onStatusChanged: if (Image.status == cardPic.Ready)
//                         {
//                             if(displayed === true)
//                             {
//                                 cardPic.opacity = 1
//                                 cardPic.state = "Loaded"
//                             }
//                             else
//                             {
//                                 spinner.state = "Run"
//                                 cardPic.state = "Loading"
//                                 cardPic.displayed = true;
//                                 spinnerTimer.start();
//                             }
                         }
//        }

//        Timer {
//            id: spinnerTimer
//            interval: 2000; running: false; repeat: false
//            onTriggered: {
//                spinner.state = "End";
//                revealTimer.start();
//            }
//        }
//        Timer {
//            id: revealTimer
//            interval: 2000; running: false; repeat: false
//            onTriggered: {
//                cardPic.state = "Loaded";
//                cardsView.isCardLoaded();
//            }
//        }

        states: [
            State {
                name: "Loading"
                PropertyChanges { target: cardPic; opacity: 0 }
                PropertyChanges { target: cardPic; visible: true }
            },
            State {
                name: "Loaded"
                PropertyChanges { target: cardPic; visible: true }
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
            target: MyModel
            onCardUpdated:
            {
                cardsView.isCardLoaded();
            }
        }
Component.onCompleted: cardsView.isCardLoaded();
}
}
