#ifndef SERIALPORTMANAGER_H
#define SERIALPORTMANAGER_H
#include "IWriteStrategy.h"
#include <QObject>
#include <QSerialPort>
class SerialPortManager : public QObject
{
    Q_OBJECT
public:
    explicit SerialPortManager(QObject *parent = nullptr);
    enum DuplexMode {
        FullDuplex,
        HalfDuplex
    };
    Q_ENUM(DuplexMode) // 注册到元对象系统，QML中可用
    void setDuplexMode(DuplexMode mode);
    ~SerialPortManager();
    bool write(const QByteArray& data);
    bool open(const QString& portName, QSerialPort::BaudRate baudRate,
                                 QSerialPort::DataBits dataBits, QSerialPort::Parity parity,
                                 QSerialPort::StopBits stopBits);
    void close();
    bool isOpen() const;
    QString portName(){ return m_portName; }
signals:
    void portOpened();
    void errorOccurred(QString error);
    void dataReceived(QByteArray data);
    void portClosed();



private:
    IWriteStrategy* m_writeStrategy; // 持有当前写入策略的指针
    QSerialPort* m_serialPort;
    void onReadyRead();
    void onErrorOccurred(QSerialPort::SerialPortError error);
    QString m_portName{};

signals:
};

#endif // SERIALPORTMANAGER_H
