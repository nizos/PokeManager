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

        ListView {
            id: list_view1
//            x: 125
//            y: 100
            width: parent.width
            height: parent.height
            delegate: CardsItemDelegate {}
            model: cardsSQLModel
        }



//        Text {
//            text: "Home page"
//            anchors.centerIn: parent
//        }

//        Rectangle {
//            width: 500
//            height: 500
//            MouseArea {
//                anchors.fill: parent
//                Text {
//                    id: text1
//                    anchors.verticalCenterOffset: 20
//                    anchors.horizontalCenter: parent.horizontalCenter
//                    text: qsTr("Testing")
//                    font.pixelSize: 12
//                    }
//                ListView {
//                    id: list_view1
//                    x: 125
//                    y: 100
//                    width: 110
//                    height: 160
//                    delegate: CardsItemDelegate {}
//                    model: cardsSQLModel
//                }
//            }
//        }
//        Image { source: "image://rip/https://s3.amazonaws.com/pokemontcg/xy7/54.png" }


    }
}
