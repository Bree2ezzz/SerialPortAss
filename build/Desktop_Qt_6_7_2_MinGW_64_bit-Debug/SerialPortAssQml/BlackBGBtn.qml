import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Button{
    id: root
    // 外部可配置
    property url iconSource: ""      // 图标
    property string buttonText: ""   // 文本
    property string tooltipText: ""  // 悬停提示文本
    property int tooltipDelayMs: 400  // 延迟显示
    Layout.minimumHeight: 38
    Layout.maximumHeight: 38
    Layout.minimumWidth: 110
    Layout.maximumWidth: 150

    background: Rectangle{
        radius: 5
        color: "black"
    }

    // 行布局
    contentItem: RowLayout{
        anchors.centerIn: parent
        // anchors.margins: 10
        spacing: 6
        Image {
            id: buttonIcon
            source: root.iconSource
            width: 18
            height: 18
            fillMode: Image.PreserveAspectFit
            sourceSize.width: 18

            sourceSize.height: 18
        }
        Text{
            text: root.buttonText
            font.pixelSize: 16
            color: "white"
            verticalAlignment: Text.AlignVCenter
        }
    }

    // 悬停提示气泡
    Timer { id: tipTimer; interval: root.tooltipDelayMs; running: false; repeat: false; onTriggered: {
            // 将按钮局部坐标映射到窗口 overlay 坐标系
            var p = root.mapToItem(Overlay.overlay, 0, 0);
            // 使用 implicit 尺寸，避免未打开时 width/height 为 0
            var w = tipPopup.implicitWidth;
            var h = tipPopup.implicitHeight;
            tipPopup.x = p.x + root.width / 2 - w / 2;
            tipPopup.y = p.y - h - 8;
            tipPopup.open();
        } }
    hoverEnabled: true
    // 某些样式下需要指针穿透修正，显式声明鼠标区域
    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        onEntered: { if (root.tooltipText.length > 0) tipTimer.restart() }
        onExited: { tipTimer.stop(); tipPopup.close() }
        acceptedButtons: Qt.NoButton
    }
    onHoveredChanged: {
        if (hovered && root.tooltipText.length > 0) {
            tipTimer.restart()
        } else {
            tipTimer.stop(); tipPopup.close()
        }
    }

    Popup {
        id: tipPopup
        modal: false
        focus: false
        closePolicy: Popup.CloseOnPressOutside | Popup.CloseOnEscape
        parent: Overlay.overlay
        padding: 0
        background: Rectangle { color: "transparent" }
        property bool below: false
        property real arrowCenterX: 0
        onOpened: {
            // 再次矫正位置，确保按实际尺寸定位
            var p = root.mapToItem(Overlay.overlay, 0, 0);
            var w = tipPopup.implicitWidth;
            var h = tipPopup.implicitHeight;
            var xCand = p.x + root.width / 2 - w / 2;
            // 屏幕边界收敛
            xCand = Math.max(8, Math.min(Overlay.overlay.width - w - 8, xCand));

            var yAbove = p.y - h - 8;
            var yBelow = p.y + root.height + 8;
            if (yAbove < 0 && yBelow + h <= Overlay.overlay.height) {
                tipPopup.below = true;
                tipPopup.x = xCand;
                tipPopup.y = yBelow;
            } else {
                tipPopup.below = false;
                tipPopup.x = xCand;
                tipPopup.y = Math.max(8, yAbove);
            }
            // 记录按钮中心相对 popup 的 X，用于放置箭头
            tipPopup.arrowCenterX = p.x + root.width / 2 - tipPopup.x;
        }
        onXChanged: {
            // 当 popup 因窗口变化被移动时，更新箭头中心
            var p = root.mapToItem(Overlay.overlay, 0, 0);
            tipPopup.arrowCenterX = p.x + root.width / 2 - tipPopup.x;
        }
        // 自动换行与宽度限制
        contentItem: Item {
            id: tipRoot
            property int maxW: 360
            // 来自 popup 的按钮中心（相对 popup 的坐标）
            property real arrowCenterX: tipPopup.arrowCenterX
            implicitWidth: Math.min(tipText.implicitWidth + 24, maxW + 24)
            implicitHeight: tipText.paintedHeight + 24 + 8 // 箭头高度
            // 气泡主体
            Rectangle {
                id: bubble
                width: Math.min(tipText.implicitWidth + 24, parent.maxW + 24)
                height: tipText.paintedHeight + 24
                anchors.top: parent.top
                radius: 8
                color: "black"
                border.color: "#333"
                border.width: 1
                Text {
                    id: tipText
                    text: root.tooltipText
                    color: "white"
                    font.pixelSize: 16
                    wrapMode: Text.Wrap
                    anchors.margins: 12
                    anchors.fill: parent
                    // 控制行宽触发换行
                    maximumLineCount: 0
                }
            }
            // 小三角箭头
            Canvas {
                id: arrowTop
                visible: !tipPopup.below
                anchors.top: bubble.bottom
                width: 14; height: 8
                x: Math.max(7, Math.min(bubble.width - 7, tipRoot.arrowCenterX)) - width/2
                onPaint: {
                    var ctx = getContext('2d');
                    ctx.clearRect(0,0,width,height);
                    ctx.fillStyle = bubble.color;
                    ctx.beginPath();
                    ctx.moveTo(0,0); ctx.lineTo(width,0); ctx.lineTo(width/2,height); ctx.closePath();
                    ctx.fill();
                }
            }
            Canvas {
                id: arrowBottom
                visible: tipPopup.below
                anchors.bottom: bubble.top
                width: 14; height: 8
                x: Math.max(7, Math.min(bubble.width - 7, tipRoot.arrowCenterX)) - width/2
                onPaint: {
                    var ctx = getContext('2d');
                    ctx.clearRect(0,0,width,height);
                    ctx.fillStyle = bubble.color;
                    ctx.beginPath();
                    ctx.moveTo(0,height); ctx.lineTo(width,height); ctx.lineTo(width/2,0); ctx.closePath();
                    ctx.fill();
                }
            }
        }
    }
    onClicked: {
        console.log("black btn clicked")
    }
}
