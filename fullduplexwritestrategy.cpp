#include "fullduplexwritestrategy.h"



void FullDuplexWriteStrategy::write(QSerialPort *port, const QByteArray &data)
{
    if (!port || !port->isOpen() || data.isEmpty()) {
        return;
    }
    //全双工可以直接调用write
    if(port && port->isOpen())
    {
        port->write(data);
    }
}
