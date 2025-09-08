import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Popup {
    id: root
    width: 280
    height: 160
    modal: false
    focus: true
    closePolicy: Popup.CloseOnEscape

    // 当弹窗失去焦点时（例如用户点击了其他地方），自动关闭
    onActiveFocusChanged: {
        if (!activeFocus) {
            close()
        }
    }

    padding: 10

    // 信号：当设置改变时发出
    signal settingsChanged(bool enabled, int interval)

    // 对外暴露的属性，用于从外部设置初始值
    property int initialInterval: 1000
    property bool initialEnabled: false

    onOpened: {
        autoSendSwitch.checked = initialEnabled
        intervalSpinBox.value = initialInterval
    }

    background: Rectangle {
        radius: 8
        color: "white"
        border.color: "#e0e0e0"
        border.width: 1
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: 12

        RowLayout {
            Layout.fillWidth: true
            Text {
                text: "自动发送设置"
                font.pixelSize: 16
                font.bold: true
                color: "#333"
            }
            Item { Layout.fillWidth: true }
            Switch {
                id: autoSendSwitch
                onCheckedChanged: root.settingsChanged(checked, intervalSpinBox.value)
            }
        }

        Text {
            text: "启用后自动每 " + intervalSpinBox.value + " 毫秒发送一次数据"
            font.pixelSize: 12
            color: "#666"
            wrapMode: Text.WordWrap
            Layout.fillWidth: true
        }

        RowLayout {
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter
            spacing: 10

            Button {
                text: "-"
                font.pixelSize: 18
                implicitWidth: 50   // 设置固定宽度
                implicitHeight: 40  // 设置固定高度
                onClicked: intervalSpinBox.value -= 100
            }

            SpinBox {
                id: intervalSpinBox
                from: 10
                to: 60000
                stepSize: 10
                value: 1000
                editable: true
                onValueChanged: root.settingsChanged(autoSendSwitch.checked, value)

                contentItem: TextInput {
                    text: intervalSpinBox.textFromValue(intervalSpinBox.value, intervalSpinBox.locale)
                    font.pixelSize: 14
                    horizontalAlignment: TextInput.AlignHCenter
                    verticalAlignment: TextInput.AlignVCenter
                    readOnly: !intervalSpinBox.editable
                }

                background: Rectangle {
                    color: "transparent"
                }
            }

            Button {
                text: "+"
                font.pixelSize: 18
                implicitWidth: 50   // 设置固定宽度
                implicitHeight: 40  // 设置固定高度
                onClicked: intervalSpinBox.value += 100
            }

            Text {
                text: "ms / 次"
                font.pixelSize: 12
                color: "#333"
            }
        }
    }
}
