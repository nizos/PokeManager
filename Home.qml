import QtQuick 2.0
import PokeApp.Classes.Core 1.0

Item {
    id: homePage
    Rectangle {
        id: demo
        color: '#ecf0f1'
        width: 500
        height: 500
        anchors.fill: parent
        Text {
            text: "Home page"
            anchors.centerIn: parent
        }
//        Image { source: "image://resourceImageProvider/https://s3.amazonaws.com/pokemontcg/xy7/54.png" }


    }
}
