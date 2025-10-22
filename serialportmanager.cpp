#include "serialportmanager.h"
#include "fullduplexwritestrategy.h"
#include "halfduplexwritestrategy.h"
#include <QDebug>
SerialPortManager::SerialPortManager(QObject *parent)
    : QObject{parent}
{
    m_serialPort = new QSerialPort(this);
    setDuplexMode(FullDuplex);
    connect(m_serialPort, &QSerialPort::readyRead, this, &SerialPortManager::onReadyRead);
    connect(m_serialPort,&QSerialPort::errorOccurred,this,&SerialPortManager::onErrorOccurred);
}

void SerialPortManager::setDuplexMode(DuplexMode mode)
{
    if (m_writeStrategy) {
        delete m_writeStrategy;
        m_writeStrategy = nullptr;
    }

    // 根据模式创建新的策略实例
    if (mode == FullDuplex) {
        m_writeStrategy = new FullDuplexWriteStrategy(this);
    } else if (mode == HalfDuplex) {
        m_writeStrategy = new HalfDuplexWriteStrategy(this);
    }else{
        emit errorOccurred("无效的双工模式");
        return;
    }
}

SerialPortManager::~SerialPortManager()
{
    delete m_writeStrategy; // 清理策略对象
}

bool SerialPortManager::write(const QByteArray &data)
{
    if (!m_serialPort) {
        emit errorOccurred("串口未初始化");
        return false;
    }

    if (!m_serialPort->isOpen()) {
        emit errorOccurred("串口未打开，无法发送数据");
        return false;
    }

    if (!m_writeStrategy) {
        emit errorOccurred("写入策略未初始化");
        return false;
    }

    if (data.isEmpty()) {
        emit errorOccurred("发送数据为空");
        return false;
    }
    // 将写入任务委托给当前的策略对象
    if (m_writeStrategy) {
        const qint64 bytesWritten = m_writeStrategy->write(m_serialPort, data);
        if (bytesWritten < 0 || bytesWritten != data.size()) {
            emit errorOccurred(m_serialPort->errorString().isEmpty()
                               ? QStringLiteral("串口写入失败")
                               : m_serialPort->errorString());
            return false;
        }
    }
    return true;
}

bool SerialPortManager::open(const QString &portName, QSerialPort::BaudRate baudRate, QSerialPort::DataBits dataBits,
                             QSerialPort::Parity parity, QSerialPort::StopBits stopBits)
{
    if (m_serialPort->isOpen()) {
        // 如果端口名和所有设置都相同，则无需任何操作
        if (m_serialPort->portName() == portName &&
            m_serialPort->baudRate() == baudRate &&
            m_serialPort->dataBits() == dataBits &&
            m_serialPort->parity() == parity &&
            m_serialPort->stopBits() == stopBits
            )
        {
            qDebug() << "Port" << portName << "is already open with the same settings.";
            return true; // 直接返回成功，因为已经连接
        }
        // 如果设置不同，则先关闭当前连接，以便用新设置重新打开
        m_serialPort->close();
    }

    m_serialPort->setPortName(portName);
    m_serialPort->setBaudRate(baudRate);
    m_serialPort->setDataBits(dataBits);
    m_serialPort->setParity(parity);
    m_serialPort->setStopBits(stopBits);
    m_serialPort->setFlowControl(QSerialPort::NoFlowControl);
    if (m_serialPort->open(QIODevice::ReadWrite)) {
        qDebug() << "Port" << portName << "opened successfully.";
        m_portName = portName;
        emit portOpened();
        return true;
    } else {
        qDebug() << "Failed to open port" << portName << ":" << m_serialPort->errorString();
        emit errorOccurred(m_serialPort->errorString());
        return false;
    }
}

void SerialPortManager::close()
{
    if (m_serialPort->isOpen()) {
        m_serialPort->close();
        m_portName = "";
        qDebug() << "Port closed.";
        emit portClosed();
    }
}

bool SerialPortManager::isOpen() const
{
    return m_serialPort->isOpen();
}



void SerialPortManager::onReadyRead()
{
    QByteArray data = m_serialPort->readAll();
    if (!data.isEmpty()) {
        emit dataReceived(data);
    }
}
//捕捉QSerialPort的错误
void SerialPortManager::onErrorOccurred(QSerialPort::SerialPortError error)
{
    if (error != QSerialPort::NoError) {
        emit errorOccurred(m_serialPort->errorString());
    }
}
