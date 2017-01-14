import QtQuick 2.0
import PokeApp.Classes.Core 1.0

// Header button
Item {
    id: button
    width: 20
    height: 40
    signal clicked
    property int fontSize: 10
    property alias buttonText: innerText.text;
    property color color: "#2c3e50"
    property color hoverColor: "#34495e"
    property color pressColor: "#2980b9"
    property int footerSize: 1
    onEnabledChanged: state = ""

    // Button Rectangle
    Rectangle {
        id: rectangleButton
        anchors.fill: parent
        color: button.enabled ? button.color : "#7f8c8d"

        // Button Text
        Text {
            id: innerText
            font.pointSize: fontSize
            anchors.centerIn: parent
            color: "#bdc3c7"
        }
        Rectangle {
            id: footerThread
            width: parent.width
            height: footerSize
            color: button.down ? "#17a81a" : "Red"
            anchors.bottom: parent.bottom
        }
    }

    // STATES
    states: [
        State {
            // Hovered
            name: "Hovering"
            PropertyChanges {
                target: rectangleButton
                color: hoverColor
            }
        },
        State {
            // Pressed
            name: "Pressed"
            PropertyChanges {
                target: rectangleButton
                color: pressColor
            }
            PropertyChanges {
                target: button
                fontSize: 10.5
            }
        }
    ]

    // TRANSITIONS
    transitions: [
        Transition {
            from: ""; to: "Hovering"
            ColorAnimation { duration: 200 }
        },
        Transition {
            from: "Hovering"; to: ""
            ColorAnimation { duration: 400 }
        },
        Transition {
            from: "*"; to: "Pressed"
            ColorAnimation { duration: 10 }
        }
    ]

    // MOUSE AREA
    MouseArea {
        hoverEnabled: true
        anchors.fill: button
        onEntered: { button.state='Hovering'}
        onExited: { button.state=''}
        onClicked: { button.clicked();}
        onPressed: { button.state="Pressed" }
        onReleased: {
            if (containsMouse)
              button.state="Hovering";
            else
              button.state="";
        }
    }
}
