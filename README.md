# 串口助手 (QML)

这是一个基于 Qt QML 和 C++ 的现代化串口助手，旨在为嵌入式系统的开发和调试提供一个强大、灵活且易于扩展的工具。

## 项目架构

项目采用 Model-View-ViewModel (MVVM) 设计模式，以确保 UI 与业务逻辑的清晰分离。

- **View (QML)**: 负责用户界面的声明式定义，包括窗口、按钮、文本框等。
  - `Main.qml`: 主窗口界面。
  - `PortSelectionDialog.qml`: 串口选择对话框。
  - `AutoSendDialog.qml`: 自动发送设置对话框。

- **ViewModel (`SerialPortViewModel`)**: 作为 View 和 Model 之间的桥梁，负责处理 UI 逻辑和数据绑定。它暴露 Q_PROPERTY 和 Q_INVOKABLE 方法给 QML，以便 UI 可以访问和操作后端数据。

- **Model**: 负责核心业务逻辑和数据管理。
  - `SerialPortManager`: 管理串口的连接、断开、读写操作。
  - `PortSettingsManager`: 管理串口配置，如波特率、数据位等。
  - `DataProcessor`: 处理数据的格式转换（ASCII/HEX）。
  - `FileSender`: 负责文件发送功能。
  - `LogManager`: 管理日志的记录、显示和导出。

## 工作流程

1. **初始化**: `main.cpp` 创建 `SerialPortViewModel` 实例，并将其注册到 QML 上下文，使其在 QML 中可用。
2. **UI 加载**: QML 引擎加载 `Main.qml`，并根据 ViewModel 的初始状态渲染 UI。
3. **用户交互**:
   - 用户在 UI 上选择串口配置（如波特率、数据位等）。
   - `PortSettingsManager` 负责维护这些配置项。
   - 用户点击“选择串口设备”按钮，`PortSelectionDialog` 显示可用串口列表。
   - 用户选择一个串口并点击“连接”，`SerialPortViewModel` 调用 `SerialPortManager` 的 `open` 方法来建立连接。
4. **数据收发**:
   - **发送**: 用户在输入框中输入数据，点击“发送”按钮。`SerialPortViewModel` 调用 `SerialPortManager` 的 `write` 方法。`SerialPortManager` 将数据委托给当前的写入策略（`IWriteStrategy`），由策略对象将数据写入串口。
   - **接收**: `SerialPortManager` 通过 `readyRead` 信号接收数据，并通过 `dataReceived` 信号将数据传递给 `DataProcessor`。`DataProcessor` 根据当前的接收模式（ASCII/HEX）处理数据，并更新日志。
5. **文件发送**:
   - 用户点击“发送文件”按钮，`FileDialog` 打开。
   - 用户选择文件后，`FileSender` 的 `startSending` 方法被调用。
   - `FileSender` 以数据块的形式读取文件，并通过 `SerialPortManager` 将数据写入串口。
   - `isSending` 属性用于在发送期间禁用 UI 上的相关控件。

## 如何添加新功能

### 示例：添加一个新的通信模式

1. **创建新的写入策略**:
   - 创建一个继承自 `IWriteStrategy` 的新类（例如 `MyNewWriteStrategy`）。
   - 在 `MyNewWriteStrategy` 中实现 `write` 方法，定义新的数据发送逻辑。

2. **更新 `SerialPortManager`**:
   - 在 `SerialPortManager::setDuplexMode` 方法中，添加一个新的模式选项，用于创建 `MyNewWriteStrategy` 的实例。

3. **更新 `PortSettingsManager`**:
   - 在 `duplexOptions` 字符串列表中添加新模式的名称。

4. **更新 UI (QML)**:
   - `Main.qml` 中的通信模式下拉框将自动显示新的模式选项，无需额外修改。

## TODO List

- [ ] **多条发送**: 支持一次性发送多条预设指令。
- [ ] **定时发送**: 允许用户设置定时任务，在指定时间间隔内循环发送数据。
- [ ] **数据绘图**: 将接收到的数据以波形图的形式实时显示。
- [ ] **脚本支持**: 支持使用脚本（如 Lua、Python）来处理和响应接收到的数据。
- [ ] **自定义协议解析**: 允许用户定义自己的通信协议，并根据协议解析和显示数据。
- [ ] **保存和加载配置**: 支持将当前的串口配置保存到文件，并在下次启动时加载。
- [ ] **日志过滤**: 提供按关键字、发送/接收方向等条件过滤日志的功能。
- [ ] **多语言支持**: 添加国际化支持，允许用户切换界面语言。
