#include "serialportviewmodel.h"
#include <QDebug>

SerialPortViewModel::SerialPortViewModel(QObject *parent) : QObject(parent)
{
    // 1. Create all the manager objects
    m_serialPortManager = new SerialPortManager(this);
    m_dataProcessor = new DataProcessor(this);
    m_logManager = new LogManager(this);
    m_settingsManager = new PortSettingsManager(this);
    m_fileSender = new FileSender(m_serialPortManager, this);

    // 2. Setup auto-send timer
    m_autoSendTimer = new QTimer(this);
    connect(m_autoSendTimer, &QTimer::timeout, this, &SerialPortViewModel::onAutoSendTimeout);

    // 3. Connect signals from SerialPortManager to our slots
    connect(m_serialPortManager, &SerialPortManager::dataReceived, this, &SerialPortViewModel::onDataReceived);
    connect(m_serialPortManager, &SerialPortManager::errorOccurred, this, &SerialPortViewModel::onErrorOccurred);
    connect(m_serialPortManager, &SerialPortManager::portOpened, this, &SerialPortViewModel::onPortOpened);
    connect(m_serialPortManager, &SerialPortManager::portClosed, this, &SerialPortViewModel::onPortClosed);

    // 4. Connect signals from FileSender
    connect(m_fileSender, &FileSender::logMessage, this, &SerialPortViewModel::onFileSenderLog);
}

// --- Property Getters ---
PortSettingsManager* SerialPortViewModel::settingsManager() const { return m_settingsManager; }
LogManager* SerialPortViewModel::logManager() const { return m_logManager; }
DataProcessor* SerialPortViewModel::dataProcessor() const { return m_dataProcessor; }
FileSender* SerialPortViewModel::fileSender() const { return m_fileSender; }
bool SerialPortViewModel::isConnected() const { return m_serialPortManager->isOpen(); }
qint64 SerialPortViewModel::sentBytesCount() const { return m_sentBytesCount; }
qint64 SerialPortViewModel::receivedBytesCount() const { return m_receivedBytesCount; }

// --- QML Invokable Actions ---

void SerialPortViewModel::connectPort(const QString &portName)
{
    m_serialPortManager->setDuplexMode(m_settingsManager->selectedDuplexMode());
    m_serialPortManager->open(portName,
                             m_settingsManager->selectedBaudRate(),
                             m_settingsManager->selectedDataBits(),
                             m_settingsManager->selectedParity(),
                             m_settingsManager->selectedStopBits());
}

void SerialPortViewModel::disconnectPort()
{
    m_serialPortManager->close();
}

void SerialPortViewModel::sendData(const QString &text)
{
    bool ok;
    QString error;
    QByteArray data = m_dataProcessor->prepareDataForSend(text, ok, error);

    if (ok) {
        m_sentBytesCount += data.size();
        emit sentBytesCountChanged();

        if(m_serialPortManager->write(data)){
        m_logManager->addLog("TX", m_dataProcessor->sendMode(), text);
        }
    } else {
        onErrorOccurred(error);
    }
}

void SerialPortViewModel::setAutoSend(bool enabled, int interval, const QString &data)
{
    setAutoSendEnabled(enabled);
    setAutoSendInterval(interval);
    m_autoSendData = data;

    if (m_autoSendEnabled) {
        if (!m_autoSendData.isEmpty()) {
            m_autoSendTimer->start(m_autoSendInterval);
        } else {
            setAutoSendEnabled(false);
        }
    } else {
        m_autoSendTimer->stop();
    }
}

void SerialPortViewModel::clearByteCounts()
{
    if (m_sentBytesCount != 0 || m_receivedBytesCount != 0) {
        m_sentBytesCount = 0;
        m_receivedBytesCount = 0;
        emit sentBytesCountChanged();
        emit receivedBytesCountChanged();
    }
}

// --- Slots for SerialPortManager signals ---

void SerialPortViewModel::onDataReceived(const QByteArray &data)
{
    m_receivedBytesCount += data.size();
    emit receivedBytesCountChanged();

    QString processedData = m_dataProcessor->processReceivedData(data);
    m_logManager->addLog("RX", m_dataProcessor->receiveMode(), processedData);
}

void SerialPortViewModel::onFileSenderLog(const QString &message)
{
    m_logManager->addLog("SYS", "INFO", message);
}

void SerialPortViewModel::onErrorOccurred(const QString &errorString)
{
    m_logManager->addLog("SYS", "ERROR", errorString);
}

void SerialPortViewModel::onPortOpened()
{
    m_logManager->addLog("SYS", "INFO", "串口已打开");
    emit connectionStatusChanged(true, m_serialPortManager->portName());
}

void SerialPortViewModel::onPortClosed()
{
    m_logManager->addLog("SYS", "INFO", "串口已关闭");
    emit connectionStatusChanged(false, "");
}


// --- Auto-send implementation ---

void SerialPortViewModel::onAutoSendTimeout()
{
    if (!m_autoSendData.isEmpty()) {
        sendData(m_autoSendData);
    }
}

bool SerialPortViewModel::autoSendEnabled() const { return m_autoSendEnabled; }

void SerialPortViewModel::setAutoSendEnabled(bool enabled)
{
    if (m_autoSendEnabled != enabled) {
        m_autoSendEnabled = enabled;
        emit autoSendEnabledChanged();
    }
}

int SerialPortViewModel::autoSendInterval() const { return m_autoSendInterval; }

void SerialPortViewModel::setAutoSendInterval(int ms)
{
    if (m_autoSendInterval != ms) {
        m_autoSendInterval = ms;
        emit autoSendIntervalChanged();
        if (m_autoSendTimer->isActive()) {
            m_autoSendTimer->setInterval(m_autoSendInterval);
        }
    }
}
