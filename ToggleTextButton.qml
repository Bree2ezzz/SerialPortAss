import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
Button {
    // 1. 定义可定制的属性
    property url iconSource: ""
    property string textState1: ""  // 切换前的文本
    property string textState2: ""  // 切换后的文本

    // 内部状态，用于追踪按钮当前显示的是哪个文本
    property bool isToggled: false

    height: 38
    width: 80
    id: root
    Layout.minimumHeight: 38
    Layout.minimumWidth: 110
    Layout.maximumHeight: 38
    Layout.maximumWidth: 110
    signal modeChanged(string mode)

    // 2. 自定义背景：透明背景，淡蓝色边框
    background: Rectangle {

        color: "transparent"
        border.color: "#4a90e2"
        border.width: 1
        radius: 5
    }

    // 3. 自定义内容：图标 + 文字
    contentItem: RowLayout {

        spacing: 2
        anchors.centerIn: parent

        Image {
            visible: root.iconSource !== ""
            source: root.iconSource
            width: 18
            height: 18
            sourceSize.width: 18   // 强制解码为 24x24 大小
            sourceSize.height: 18
            fillMode: Image.PreserveAspectFit
        }

        Text {
            // 根据 isToggled 状态来显示不同的文本
            text: root.isToggled ? root.textState2 : root.textState1
            font.pixelSize: 16
            color: "#4a90e2" // 淡蓝色字体
            verticalAlignment: Text.AlignVCenter
        }
    }

    // 4. 定义按钮的点击行为
    onClicked: {
        isToggled = !isToggled // 点击后切换内部状态
        root.modeChanged(isToggled ? textState2.split(":")[1] : textState1.split(":")[1])
    }

}
