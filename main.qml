import QtQuick 2.5
import QtQuick.Controls 1.4

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("License Generator")

    signal expiryDateEntered(date date)
    signal macAddressEntered(string text)
    signal generateButtonClicked(string text)

    Text {
        id: macAddressLabel
        x: 130
        y: 102
        width: 87
        height: 17
        text: qsTr("MAC Address")
        font.pixelSize: 12
    }

    TextInput {
        id: macAddressInput
        x: 275
        y: 102
        width: 173
        height: 20
        cursorVisible: true
        font.pixelSize: 12
        onAccepted: macAddressEntered(text)
    }

    Text {
        id: expiryDateLabel
        x: 130
        y: 125
        width: 87
        height: 17
        text: qsTr("Expiry Date")
        font.pixelSize: 12
    }

    Calendar {
        id: expiryDatePicker
        x: 275
        y: 125
        width: 294
        height: 231
        onClicked: expiryDateEntered(selectedDate)
    }

    Button {
        id: generateButton
        x: 278
        y: 422
        text: qsTr("Generate")
        onClicked: generateButtonClicked(macAddressInput.text)
    }

    Rectangle {
        id: statusRect
        x: 130
        y: 376
        width: 390
        height: 32
        color: "#72e551"

        Text {
            id: statusText
            text: qsTr("License file generated successfully : ")
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideLeft
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
            anchors.leftMargin: 0
            anchors.topMargin: 0
            anchors.fill: parent
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 12
        }
    }
}
