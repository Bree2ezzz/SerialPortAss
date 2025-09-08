import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs

ApplicationWindow{
    visible: true
    width: 1280
    height: 720
    id: root
    title: "串口助手 (QML)"
    Connections{
        target: serialPortViewModel
        function onConnectionStatusChanged(isOpen, portName) {
            if (isOpen) {
                // 串口打开时，更新标题
                root.title = "串口助手 - " + portName + " 已连接";
            } else {
                // 串口关闭时，恢复默认标题
                root.title = "串口助手 (QML)";
            }
        }
    }

    PortSelectionDialog{
        id: portDialog
    }

    AutoSendDialog {
        id: autoSendDialog
        parent: autoSendBtn //将弹窗的逻辑父项设置为按钮

        //相对于父项（按钮）进行定位，QML会自动处理位置更新
        x: (parent.width / 2) - (width / 2) // 在按钮的水平中心
        y: -height - 5 // 在按钮的正上方，留出5像素间距

        onSettingsChanged: {
            // 当对话框内的设置变化时，立即更新到ViewModel
            serialPortViewModel.setAutoSend(enabled, interval, sendArea.text)
        }
    }

    SplitView{
        //分割左右的view
        id: mainSpliter
        anchors.fill: parent
        orientation: Qt.Horizontal // 水平分割
        Rectangle{
            id: setingPanel
            SplitView.minimumWidth: 200
            Layout.fillHeight: true
            color: "#f0f0f0"
            SplitView.preferredWidth: 320
            ColumnLayout{
                anchors.fill: parent
                anchors.margins: 16
                spacing: 8

                Text{
                    text: "串口设置"
                    font.pixelSize: 22
                    font.bold: true
                    color: "#222"
                }

                GroupBox {
                    title: "通信统计"
                    Layout.fillWidth: true
                    font.pixelSize: 14

                    // 添加一个主布局容器来管理内部所有组件
                    ColumnLayout {
                        width: parent.width // 确保宽度填充GroupBox
                        spacing: 8 // 设置组件间距

                        GridLayout {
                            columns: 2
                            Layout.fillWidth: true // 填充父布局宽度
                            columnSpacing: 10
                            rowSpacing: 6 // 添加行间距

                            Text {
                                text: "发送字节:";
                                font.pixelSize: 12;
                                color: "#444"
                                Layout.alignment: Qt.AlignVCenter // 垂直居中
                            }
                            Text {
                                text: serialPortViewModel.sentBytesCount
                                font.pixelSize: 12
                                font.bold: true
                                color: "#007ACC"
                                Layout.alignment: Qt.AlignVCenter // 垂直居中
                            }

                            Text {
                                text: "接收字节:";
                                font.pixelSize: 12;
                                color: "#444"
                                Layout.alignment: Qt.AlignVCenter // 垂直居中
                            }
                            Text {
                                text: serialPortViewModel.receivedBytesCount
                                font.pixelSize: 12
                                font.bold: true
                                color: "#D73A49"
                                Layout.alignment: Qt.AlignVCenter // 垂直居中
                            }
                        }

                        Button {
                            text: "清空计数"
                            Layout.fillWidth: true // 按钮填充宽度
                            Layout.topMargin: 8 // 现在这个margin会生效
                            font.pixelSize: 12
                            onClicked: serialPortViewModel.clearByteCounts()
                            background: Rectangle {
                                color: "#e1e4e8"
                                radius: 4
                                border.color: "#d1d5da"
                                border.width: 1
                            }
                            contentItem: Text {
                                text: parent.text
                                color: "#24292e"
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                            }
                        }
                    }
                }

                Text{
                    text: "请选择串口连接相关参数"
                    font.pixelSize: 16
                    color: "#666"
                    Layout.bottomMargin: 10
                }
                Text{ text: "波特率";font.pixelSize: 12;color: "#444"}
                ComboBox{
                    id: bandRateCb
                    Layout.fillWidth: true
                    Layout.preferredHeight: 30
                    font.pixelSize: 12
                    model: serialPortViewModel.settingsManager.baudRatesModel
                    currentIndex: model.indexOf(serialPortViewModel.settingsManager.currentBaudRate)
                    onCurrentTextChanged: serialPortViewModel.settingsManager.currentBaudRate = currentText
                    background: Rectangle {
                        color: "white"
                        radius: 6
                        border.color: "#ddd"
                        border.width: 1
                    }
                }
                // 数据位
                Text{ text: "数据位"; font.pixelSize: 12; color: "#444" }
                ComboBox{
                    id: dataBitsCb
                    Layout.fillWidth: true
                    Layout.preferredHeight: 30
                    font.pixelSize: 12
                    model: serialPortViewModel.settingsManager.dataBitsModel
                    currentIndex: model.indexOf(serialPortViewModel.settingsManager.currentDataBits)
                    onCurrentTextChanged: serialPortViewModel.settingsManager.currentDataBits = currentText
                    background: Rectangle {
                        color: "white"
                        radius: 6
                        border.color: "#ddd"
                        border.width: 1
                    }
                }

                // 校验位
                Text{ text: "校验位"; font.pixelSize: 12; color: "#444" }
                ComboBox{
                    id: parityCb
                    Layout.fillWidth: true
                    Layout.preferredHeight: 30
                    font.pixelSize: 12
                    model: serialPortViewModel.settingsManager.parityModel
                    currentIndex: model.indexOf(serialPortViewModel.settingsManager.currentParity)
                    onCurrentTextChanged: serialPortViewModel.settingsManager.currentParity = currentText
                    background: Rectangle {
                        color: "white"
                        radius: 6
                        border.color: "#ddd"
                        border.width: 1
                    }
                }

                // 停止位
                Text{ text: "停止位"; font.pixelSize: 12; color: "#444" }
                ComboBox{
                    id: stopCb
                    Layout.fillWidth: true
                    Layout.preferredHeight: 30
                    font.pixelSize: 12
                    enabled: !serialPortViewModel.fileSender.isSending
                    model: serialPortViewModel.settingsManager.stopBitsModel
                    currentIndex: model.indexOf(serialPortViewModel.settingsManager.currentStopBits)
                    onCurrentTextChanged: serialPortViewModel.settingsManager.currentStopBits = currentText
                    background: Rectangle {
                        color: "white"
                        radius: 6
                        border.color: "#ddd"
                        border.width: 1
                    }
                }
                Text{ text: "通信模式"; font.pixelSize: 12; color: "#444" }
                ComboBox{
                    id: writeStrategy
                    Layout.preferredHeight: 30
                    Layout.fillWidth: true
                    font.pixelSize: 12
                    enabled: !serialPortViewModel.fileSender.isSending
                    model: serialPortViewModel.settingsManager.duplexOptions
                    currentIndex: model.indexOf(serialPortViewModel.settingsManager.currentDuplexOption)
                    onCurrentTextChanged: serialPortViewModel.settingsManager.currentDuplexOption = currentText
                    background: Rectangle {
                        color: "white"
                        radius: 6
                        border.color: "#ddd"
                        border.width: 1
                    }

                }


                // 按钮
                Button{
                    id: selectPortBtn
                    text: "选择串口设备"
                    font.pixelSize: 20
                    Layout.preferredHeight: 30
                    Layout.fillWidth: true
                    visible: !serialPortViewModel.isConnected // 连接时隐藏
                    background: Rectangle {
                        color: "#181818"
                        radius: 6
                        opacity: selectPortBtn.hovered ? 0.8 : 1.0
                    }
                    contentItem: Text {
                        text: selectPortBtn.text
                        color: "white"
                        font.pixelSize: 15
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        anchors.fill: parent
                    }
                    hoverEnabled: true
                    onClicked: {
                        serialPortViewModel.settingsManager.refreshPortList()
                        portDialog.open()
                    }
                }

                // 连接后显示的操作按钮
                RowLayout {
                    Layout.fillWidth: true
                    visible: serialPortViewModel.isConnected // 连接后显示
                    spacing: 10

                    Button {
                        id: disconnectBtn
                        text: "断开连接"
                        Layout.fillWidth: true
                        Layout.preferredHeight: 30
                        enabled: !serialPortViewModel.fileSender.isSending
                        background: Rectangle {
                            color: "#D73A49" // 红色背景
                            radius: 6
                            opacity: disconnectBtn.hovered ? 0.8 : 1.0
                        }
                        contentItem: Text {
                            text: disconnectBtn.text
                            color: "white"
                            font.pixelSize: 15
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            anchors.fill: parent
                        }
                        onClicked: {
                            serialPortViewModel.disconnectPort()
                        }
                    }

                    Button {
                        id: changePortBtn
                        text: "更换串口"
                        Layout.fillWidth: true
                        Layout.preferredHeight: 30
                        enabled: !serialPortViewModel.fileSender.isSending
                        background: Rectangle {
                            color: "#007ACC" // 蓝色背景
                            radius: 6
                            opacity: changePortBtn.hovered ? 0.8 : 1.0
                        }
                        contentItem: Text {
                            text: changePortBtn.text
                            color: "white"
                            font.pixelSize: 15
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            anchors.fill: parent
                        }
                        onClicked: {
                            serialPortViewModel.settingsManager.refreshPortList()
                            portDialog.open()
                        }
                    }
                }
                Item {
                    Layout.fillHeight: true
                }
            }
        }

        SplitView{
            SplitView.preferredWidth: 960
            SplitView.minimumWidth: 400
            id: contentSpliter
            orientation: Qt.Vertical // 垂直分割
            ListView {
                SplitView.preferredHeight: 480
                id: logListView
                model: serialPortViewModel.logManager.logListModel
                clip: true
                
                delegate: Rectangle {
                    width: logListView.width
                    height: 30
                    color: index % 2 === 0 ? "#f8f8f8" : "white"
                    
                    Row {
                        spacing: 10
                        anchors.fill: parent
                        anchors.leftMargin: 10
                        
                        Text {
                            text: timestamp
                            width: 180
                            font.pixelSize: 12
                            color: "#666"
                            verticalAlignment: Text.AlignVCenter
                        }
                        
                        Text {
                            text: direction === "SYS" ? "系统" :
                                                        direction === "TX" ? "发送" : "接收"
                            width: 40
                            font.pixelSize: 12
                            color: direction === "SYS" ? "#ff9900" :
                                                         direction === "TX" ? "#007acc" : "#d73a49"
                            verticalAlignment: Text.AlignVCenter
                        }
                        
                        Text {
                            text: {
                                // model.type 是访问模型数据的标准写法，更明确
                                switch (model.type) {
                                case "ERROR":
                                    return "错误";
                                case "INFO":
                                    return "INFO";
                                case "HEX":
                                    return "HEX";
                                default: // default 语句可以处理所有未定义的类型，避免崩溃
                                    return "ASCII";
                                }
                            }
                            // text: type === "ERROR" ? "错误" : type === "HEX" ? "HEX" :"ASCII"
                            width: 50
                            font.pixelSize: 12
                            color: type === "ERROR" ? "#ff0000" : "#888"
                            verticalAlignment: Text.AlignVCenter
                        }
                        
                        Text {
                            text: model.data
                            font.pixelSize: 12
                            color: "#333"
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }
                    }
                }
                
                ScrollBar.vertical: ScrollBar {}
                
            }

            Rectangle {
                color: "white"
                border.color: "#eee"
                border.width: 0
                Layout.fillWidth: true
                SplitView.minimumHeight: 200
                SplitView.preferredHeight: 240

                ColumnLayout  {
                    anchors.fill: parent
                    anchors.margins: 8 // 内边距
                    spacing: 2

                    // 上排按钮
                    RowLayout  {
                        height: 38
                        Layout.fillWidth: true
                        spacing: 8

                        // 左侧4个
                        ToggleTextButton{
                            textState1: "接收:HEX"
                            textState2: "接收:ASCII"
                            iconSource: "qrc:/icon/down.png"
                            onModeChanged: (mode)=>{
                                               serialPortViewModel.dataProcessor.setReceiveMode(mode);
                                           }
                        }

                        ToggleTextButton{
                            textState1: "发送:HEX"
                            textState2: "发送:ASCII"
                            iconSource: "qrc:/icon/up.png"
                            onModeChanged: (mode)=>{
                                               serialPortViewModel.dataProcessor.setSendMode(mode);
                                           }
                        }

                        BlackBGBtn{
                            iconSource: "qrc:/icon/bidirection.png"
                            buttonText: serialPortViewModel.logManager.autoScrollEnabled ? "取消自动滚动" : "自动滚动"
                            onClicked: {
                                serialPortViewModel.logManager.autoScrollEnabled = !serialPortViewModel.logManager.autoScrollEnabled
                            }
                        }

                        FolderDialog {
                            id: folderDialog
                            title: "导出日志为JSON文件"
                            onAccepted: {
                                console.log(folderDialog.currentFolder)
                                serialPortViewModel.logManager.exportLog(folderDialog.currentFolder)
                            }


                            onRejected: {
                                console.log("用户取消了日志导出")
                            }
                        }
                        BlackBGBtn{
                            iconSource: "qrc:/icon/upload.png"
                            buttonText: "导出"
                            tooltipText: "点击导出Json文件，包含消息类型，时间戳，显示格式"
                            onClicked: {
                                folderDialog.open()
                            }
                        }

                        Item { Layout.fillWidth: true} // 拉开左右

                        // 右侧2个
                        // Button { text: "清空接收"; width: 80; height: 38 }
                        BlackBGBtn{
                            iconSource: "qrc:/icon/clear1.png"
                            buttonText: "清空接收"
                            tooltipText: "点击清除接收窗口信息"
                            onClicked: {
                                serialPortViewModel.logManager.clearLog();
                            }
                        }
                        // Button { text: "清空发送"; width: 80; height: 38 }
                        BlackBGBtn{
                            iconSource: "qrc:/icon/clear2.png"
                            buttonText: "清空发送"
                            tooltipText: "点击清除发送窗口信息"
                            onClicked: {
                                sendArea.clear()
                            }
                        }
                    }

                    // 发送内容输入框
                    TextArea {
                        id: sendArea
                        Layout.fillWidth: true
                        Layout.minimumHeight: 80
                        Layout.preferredHeight: 120
                        Layout.fillHeight: true // 自动填充高度
                        placeholderText: "这里是发送框...."
                        background: Rectangle {
                            color: "transparent"
                        }
                    }

                    // 下排按钮，右对齐
                    RowLayout {
                        Layout.fillWidth: true
                        spacing: 18
                        Layout.alignment: Qt.AlignRight // 整体内容右对齐

                        FileDialog {
                            id: sendFileDialog
                            title: "请选择要发送的文件"
                            onAccepted: {
                                serialPortViewModel.fileSender.startSending(sendFileDialog.fileUrl)
                            }
                        }

                        TransparentBtn {
                            buttonText: "整理格式"
                            visible: serialPortViewModel.dataProcessor.sendMode === "HEX"
                            enabled: !serialPortViewModel.fileSender.isSending
                            onClicked: {
                                let text = sendArea.text.replace(/[^0-9a-fA-F]/g, '');
                                let formattedText = text.replace(/(.{2})/g, '$1 ').trim().toUpperCase();
                                sendArea.text = formattedText;
                            }
                        }

                        TransparentBtn {
                            buttonText: "发送文件"
                            enabled: !serialPortViewModel.fileSender.isSending
                            onClicked: sendFileDialog.open()
                        }

                        TransparentBtn{
                            id: autoSendBtn // 确保按钮有id，以便被引用
                            buttonText: serialPortViewModel.autoSendEnabled ? "停止自动发送" : "自动发送"
                            enabled: !serialPortViewModel.fileSender.isSending
                            onClicked: {
                                // 3. 点击时，只需初始化数据并打开弹窗即可
                                autoSendDialog.initialEnabled = serialPortViewModel.autoSendEnabled
                                autoSendDialog.initialInterval = serialPortViewModel.autoSendInterval
                                autoSendDialog.open()
                            }
                        }
                        TransparentBtn{
                            buttonText: "发送"
                            enabled: !serialPortViewModel.fileSender.isSending
                            onClicked: {
                                serialPortViewModel.sendData(sendArea.text);
                            }
                        }
                    }
                }
            }

        }
    }
}
