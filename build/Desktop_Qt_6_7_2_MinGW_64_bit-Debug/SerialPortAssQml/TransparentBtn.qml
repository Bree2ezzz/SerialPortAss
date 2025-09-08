import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
Button{
    // 固定尺寸在 Layout 中也生效
    property int btnWidth: 80
    property int btnHeight: 38

    width: btnWidth
    height: btnHeight
    Layout.preferredWidth: btnWidth
    Layout.preferredHeight: btnHeight
    Layout.minimumWidth: btnWidth
    Layout.minimumHeight: btnHeight
    Layout.maximumWidth: btnWidth
    Layout.maximumHeight: btnHeight
    id: root
    property string buttonText: "" // 用于外部设置文本
    background: Rectangle{
        border.width: 0
        anchors.fill: parent
        color: parent.hovered ? "#e0e0e0" : "transparent" // 悬停时为浅灰色，否则为透明
        radius: 6
    }
    contentItem: Text{
        text: buttonText
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.fill: parent
        font.pixelSize: 16
    }

}
