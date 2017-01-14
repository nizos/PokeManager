import QtQuick 2.0
import PokeApp.Classes.Core 1.0
import "./"

// Cards Deligate
Rectangle {
    id: cardsView
    signal cardClicked(string imageURL);

    Image {
        id: cardPic
        source: model.imageURL
        width: 245
        height: 342
    }
}
