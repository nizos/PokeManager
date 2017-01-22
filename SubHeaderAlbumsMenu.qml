import QtQuick 2.7
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0
import PokeApp.Classes.Core 1.0

Item {
    id: menu
    Rectangle {
        id: cardsSubmenuField
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        width: parent.width
        height: 80
        color: "#16a085"
        clip: true

        RowLayout {
            id: cardsSubMenuRow
            width: parent.width
            height: 40
            anchors.top: parent.top
            anchors.topMargin: 40

            Rectangle {
                id: searchTextFieldRec
                Layout.fillHeight: true
                Layout.fillWidth: true
                color: "#16a085"
                TextField {
                    id: searchTextField
                    anchors.fill: parent
                }
            }


            Rectangle {
                id: searchRec
                Layout.fillHeight: true
                Layout.fillWidth: true
                color: 'Transparent'
                HeaderButton {
                    buttonText: "Search"
                    anchors.fill: parent
                    color: "#16a085"
                    footerSize: 0
                }
            }

            Rectangle {
                id: sortRec
                Layout.fillHeight: true
                Layout.fillWidth: true
                color: 'Transparent'
                HeaderButton {
                    buttonText: "Sort"
                    anchors.fill: parent
                    color: "#16a085"
                    footerSize: 0
                }
            }

            Rectangle {
                id: addTextFieldRec
                Layout.fillHeight: true
                Layout.fillWidth: true
                color: 'Transparent'
                TextField {
                    id: addTextField
                    anchors.fill: parent
                    placeholderText: qsTr("Album name")
                    onAccepted:
                    {
                        albumsSQLManager.addAlbum(addTextField.text);
                    }
                }
            }

            Rectangle {
                id: addAlbumRec
                Layout.fillHeight: true
                Layout.fillWidth: true
                color: 'Transparent'
                HeaderButton {
                    buttonText: "Add Album"
                    anchors.fill: parent
                    color: "#16a085"
                    footerSize: 0
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            albumsSQLManager.addAlbum(addTextField.text);
                        }
                    }
                }
            }


        }
    }
}
