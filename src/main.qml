import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import com.cppexplore 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Text {
        id: inputLabel
        x: 60
        y: 112
        width: 66
        height: 25
        text: qsTr("Input")
        scale: 0.7
        font.pixelSize: 12
    }

    Text {
        id: outputLabel
        x: 60
        y: 193
        width: 66
        height: 25
        text: qsTr("Output")
        scale: 0.7
        font.pixelSize: 12
    }

    TextInput {
        id: textInput
        x: 142
        y: 112
        width: 80
        height: 20
        text: qsTr("Text Input")
        font.pixelSize: 12
    }

    Text {
        id: textOutput
        x: 142
        y: 193
        width: 120
        height: 15
        text: qsTr("Text")
        font.pixelSize: 12
    }
    OutputReceiver {
        id: outputReceiver
        objectName: qtObjectNames.outputReceiverName
        onOutputRelay: {
            textOutput.text = output
        }
    }

    Item {
        id: inputSubmitter
        objectName: qtObjectNames.inputSubmitName
        signal inputSubmit(string msg, int type)

        Button {
            id: submitButton
            x: 327
            y: 108
            width: 100
            height: 100
            onClicked: {
                inputSubmitter.inputSubmit(textInput.text, transformerSelector.checkedButton.value)
            }

            Text {
                id: element3
                x: 38
                y: 43
                text: qsTr("Submit")
                font.pixelSize: 12
            }
        }
    }

    ButtonGroup {
        id: transformerSelector
        exclusive: true
    }
    Column {
        id: column
        x: 49
        y: 262
        width: 164
        height: 142
        RadioButton {
            checked: true
            text: qsTr("Reverse")
            property int value: StringTransformerTypes.STRING_REVERSE
            ButtonGroup.group: transformerSelector
        }
        RadioButton {
            text: qsTr("Uppercase")
            property int value: StringTransformerTypes.STRING_UPPERCASE
            ButtonGroup.group: transformerSelector
        }
        RadioButton {
            text: qsTr("Lowercase")
            property int value: StringTransformerTypes.STRING_LOWERCASE
            ButtonGroup.group: transformerSelector
        }
    }
}
