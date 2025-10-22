#include "fullduplexwritestrategy.h"

qint64 FullDuplexWriteStrategy::write(QSerialPort *port, const QByteArray &data)
{
    if (!port || !port->isOpen() || data.isEmpty()) {
        return -1;
    }
    //全双工可以直接调用write
    return port->write(data);
}
