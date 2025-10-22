#include "halfduplexwritestrategy.h"
#include <QDebug>
#include <QTimer>
qint64 HalfDuplexWriteStrategy::write(QSerialPort *port, const QByteArray &data)
{
    if (!port || !port->isOpen() || data.isEmpty()) {
        return -1;
    }
    /*半双工模式不能同时发送与读取，在发送和读取前需要进行状态切换*/
    port->setRequestToSend(true);
    qDebug() << "RS485: Set RTS to TRUE (Sending)";

    const qint64 bytesWritten = port->write(data);
    const int bitsPerByte = 10;
    const int minDelayMs = qMax(
                               (bitsPerByte * data.length() * 1000) / port->baudRate(),  // 数据发送时间
                               1  // 硬件切换时间（1ms足够覆盖大部分RS485芯片）
                               ) + 1;  // 额外裕量
    QTimer::singleShot(minDelayMs, this, [port]() {
        port->setRequestToSend(false);
        qDebug() << "RS485: Set RTS to FALSE (Receiving)";
    });
    return bytesWritten;
}
