import QtQuick 2.0
import PokeApp.Classes.Core 1.0
import "./"

// Cards Deligate
Rectangle {
    id: cardsView
    signal cardClicked(string imageURL);
    state: "loading"

    Image {
        id: dummyPic
        source: "qrc:/gui/GUI/emptyCard.png"
        width: 245
        height: 342
        visible: true
    }

    Image {
        id: cardPic
        source: model.imageURL
        width: 245
        height: 342
        visible: false
        Component.onCompleted: cardsView.state = "loaded"
    }

    states: [
        State {
            name: "loading"
            when: cardsView.currentState = "loading"
            PropertyChanges { target: dummyPic; visible: true }
            PropertyChanges { target: cardPic; visible: false }
        },
        State {
            name: "loaded"
            when: cardsView.currentState = "loaded"
            PropertyChanges { target: dummyPic; visible: false }
            PropertyChanges { target: cardPic; visible: true }
        }
    ]
}
