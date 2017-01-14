import QtQuick 2.7
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0
import PokeApp.Classes.Core 1.0

Item {
    id: menu
    Rectangle {
        id: librarySubmenuField
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        width: parent.width
        height: 80
        color: "#27ae60"
        clip: true
    }
}
