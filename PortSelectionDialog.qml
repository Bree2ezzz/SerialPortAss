import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

// 使用Popup作为根组件，以获得最大的自定义灵活性
Popup {
    id: popup
    modal: true
    width: 320
    height: 420
    padding: 16 // 为整个弹窗提供内边距

    // 设置弹窗的背景，实现圆角效果
    background: Rectangle {
        radius: 12 // 圆角大小
        color: "#f7f7f7" // 背景色
        border.color: "#d0d0d0"
        border.width: 1
    }

    // 使用ColumnLayout来垂直排列所有元素
    ColumnLayout {
        anchors.fill: parent
        spacing: 15 // 元素之间的垂直间距

        // 1. 顶部的提示文字
        Label {
            text: "选择要连接的串行端口"
            font.pixelSize: 16
            color: "#333"
            Layout.alignment: Qt.AlignHCenter // 居中
        }

        // 2. 使用Frame来包围列表，创建带边框的视觉效果
        Frame {
            Layout.fillWidth: true
            Layout.fillHeight: true // 占据大部分可用空间
            padding: 0 // Frame本身的内边距设为0
            background: Rectangle {
                color: "white"
                radius: 8
                border.color: "#ccc"
            }

            ListView {
                id: portListView
                anchors.fill: parent
                clip: true // 确保内容不会溢出Frame的圆角

                // 关键修复：设置初始currentIndex为-1，避免默认选中第一项
                currentIndex: -1

                model: serialPortViewModel.settingsManager.availablePorts

                delegate: ItemDelegate {
                    width: parent.width
                    text: modelData
                    font.pixelSize: 14
                    highlighted: portListView.currentIndex === index

                    onClicked: {
                        portListView.currentIndex = index
                    }
                }
            }
        }

        // 3. 底部的按钮区域
        RowLayout {
            Layout.alignment: Qt.AlignRight // 让按钮靠右对齐

            Button {
                text: "取消"
                onClicked: popup.close()
            }

            Button {
                text: "连接"
                highlighted: true // 让它成为焦点按钮

                // 关键修复：只有当currentIndex不为-1（即用户已选择）时才可用
                enabled: portListView.currentIndex !== -1

                onClicked: {
                    // 直接从model中获取选中的端口名，这是最安全的方式
                    var selectedPort = serialPortViewModel.settingsManager.availablePorts[portListView.currentIndex]
                    serialPortViewModel.connectPort(selectedPort)
                    popup.close()
                }
            }
        }
    }
}
