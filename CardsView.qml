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
            cardsView.state = "loading"
        }
        if(model.loaded === true)
        {
            cardsView.state = "loaded"
            cardPic.source = model.imageURL
        }
    }
    Image {
        id: dummyPic
        property bool on: true
        source: "qrc:/gui/GUI/emptyCard.png"
        width: 245
        height: 342
        visible: dummyPic.on

        Image {
            id: spinner
            source: "qrc:/gui/GUI/busy.png"
            visible: dummyPic.on
            anchors.centerIn: parent
            NumberAnimation on rotation {
                running: dummyPic.on;
                from: 0;
                to: 360;
                loops: Animation.Infinite;
                duration: 1200
            }
        }
    }
    Image {
        id: cardPic
        source: model.imageURL
        width: 245
        height: 342
        opacity: 0
        visible: false
    }
    states: [
        State {
            name: "loading"
            PropertyChanges { target: dummyPic; on: true }
            PropertyChanges { target: cardPic; visible: false }
        },
        State {
            name: "loaded"
            PropertyChanges { target: dummyPic; on: true }
            PropertyChanges { target: cardPic; visible: true }
            PropertyChanges { target: cardPic; opacity: 1 }
        }
    ]
    transitions: [
      Transition {
          from: "loading"; to: "loaded"
          NumberAnimation  { target: cardPic; property: "opacity"; easing.type: Easing.InOutQuad; duration: 1000 }
      } ]
    Item {
        Connections {
            target: MyModel
            onCardUpdated:
            {
                cardsView.isCardLoaded();
            }
        }
    }
    Component.onCompleted: cardsView.isCardLoaded();
}
