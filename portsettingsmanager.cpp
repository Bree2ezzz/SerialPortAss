#include "portsettingsmanager.h"
#include <QDebug>

PortSettingsManager::PortSettingsManager(QObject *parent) : QObject(parent)
{
    m_baudRatesModel << "9600" << "19200" << "38400" << "115200";
    m_dataBitsModel << "8" << "7" << "6" << "5";
    m_parityModel << "None" << "Even" << "Odd" << "Mark" << "Space";
    m_stopBitsModel << "1" << "1.5" << "2";
    m_duplexOptions << "half duplex" << "full duplex";

    // Default settings
    m_currentBaudRate = "9600";
    m_currentDataBits = "8";
    m_currentParity = "None";
    m_currentStopBits = "1";
    m_currentduplexOption = "full duplex";

    refreshPortList();
}

QStringList PortSettingsManager::baudRatesModel() const { return m_baudRatesModel; }
QStringList PortSettingsManager::dataBitsModel() const { return m_dataBitsModel; }
QStringList PortSettingsManager::stopBitsModel() const { return m_stopBitsModel; }
QStringList PortSettingsManager::parityModel() const { return m_parityModel; }
QStringList PortSettingsManager::availablePorts() const { return m_availablePorts; }
QStringList PortSettingsManager::duplexOptions() const { return m_duplexOptions; }

QString PortSettingsManager::currentBaudRate() const { return m_currentBaudRate; }
void PortSettingsManager::setCurrentBaudRate(const QString &baudRate)
{
    if (m_currentBaudRate != baudRate) {
        m_currentBaudRate = baudRate;
        emit currentBaudRateChanged();
    }
}

QString PortSettingsManager::currentDataBits() const { return m_currentDataBits; }
void PortSettingsManager::setCurrentDataBits(const QString &dataBits)
{
    if (m_currentDataBits != dataBits) {
        m_currentDataBits = dataBits;
        emit currentDataBitsChanged();
    }
}

QString PortSettingsManager::currentStopBits() const { return m_currentStopBits; }
void PortSettingsManager::setCurrentStopBits(const QString &stopBits)
{
    if (m_currentStopBits != stopBits) {
        m_currentStopBits = stopBits;
        emit currentStopBitsChanged();
    }
}

QString PortSettingsManager::currentParity() const { return m_currentParity; }
void PortSettingsManager::setCurrentParity(const QString &parity)
{
    if (m_currentParity != parity) {
        m_currentParity = parity;
        emit currentParityChanged();
    }
}

QString PortSettingsManager::currentDuplexOption() const { return m_currentduplexOption; }

void PortSettingsManager::setCurrentDuplexOption(const QString &duplexOption)
{
    if(m_currentduplexOption != duplexOption){
        m_currentduplexOption = duplexOption;
        emit currentDuplexOptionChanged();
    }
}

void PortSettingsManager::refreshPortList()
{
    m_availablePorts.clear();
    const auto portInfos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &portInfo : portInfos) {
        m_availablePorts << portInfo.portName();
    }
    emit availablePortsChanged();
    qDebug() << "Refreshed port list:" << m_availablePorts;
}

QSerialPort::BaudRate PortSettingsManager::selectedBaudRate() const
{
    if (m_currentBaudRate == "115200") return QSerialPort::Baud115200;
    if (m_currentBaudRate == "38400") return QSerialPort::Baud38400;
    if (m_currentBaudRate == "19200") return QSerialPort::Baud19200;
    return QSerialPort::Baud9600;
}

QSerialPort::DataBits PortSettingsManager::selectedDataBits() const
{
    if (m_currentDataBits == "5") return QSerialPort::Data5;
    if (m_currentDataBits == "6") return QSerialPort::Data6;
    if (m_currentDataBits == "7") return QSerialPort::Data7;
    return QSerialPort::Data8;
}

QSerialPort::Parity PortSettingsManager::selectedParity() const
{
    if (m_currentParity == "Even") return QSerialPort::EvenParity;
    if (m_currentParity == "Odd") return QSerialPort::OddParity;
    if (m_currentParity == "Mark") return QSerialPort::MarkParity;
    if (m_currentParity == "Space") return QSerialPort::SpaceParity;
    return QSerialPort::NoParity;
}

QSerialPort::StopBits PortSettingsManager::selectedStopBits() const
{
    if (m_currentStopBits == "1.5") return QSerialPort::OneAndHalfStop;
    if (m_currentStopBits == "2") return QSerialPort::TwoStop;
    return QSerialPort::OneStop;
}

SerialPortManager::DuplexMode PortSettingsManager::selectedDuplexMode() const
{
    if (m_currentduplexOption == "half duplex") return SerialPortManager::HalfDuplex;
    return SerialPortManager::FullDuplex;
}
