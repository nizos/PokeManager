import QtQuick 2.7
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0
import PokeApp.Classes.Core 1.0

Item {
    id: libraryPage

    // Page
    Rectangle {
        id: libraryPageItem
        anchors.fill: parent
        color: '#ecf0f1'

        SubHeaderLibrary {}
    }
}
