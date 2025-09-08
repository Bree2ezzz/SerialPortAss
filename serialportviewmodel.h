#ifndef SERIALPORTVIEWMODEL_H
#define SERIALPORTVIEWMODEL_H

#include <QObject>
#include <QTimer>
#include "serialportmanager.h"
#include "dataprocessor.h"
#include "logmanager.h"
#include "portsettingsmanager.h"
#include "filesender.h"

class SerialPortViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(PortSettingsManager* settingsManager READ settingsManager CONSTANT)
    Q_PROPERTY(LogManager* logManager READ logManager CONSTANT)
    Q_PROPERTY(DataProcessor* dataProcessor READ dataProcessor CONSTANT)
    Q_PROPERTY(FileSender* fileSender READ fileSender CONSTANT)
    Q_PROPERTY(bool isConnected READ isConnected NOTIFY connectionStatusChanged)
    Q_PROPERTY(qint64 sentBytesCount READ sentBytesCount NOTIFY sentBytesCountChanged)
    Q_PROPERTY(qint64 receivedBytesCount READ receivedBytesCount NOTIFY receivedBytesCountChanged)

    // Auto-send properties remain here as they are pure UI state
    Q_PROPERTY(bool autoSendEnabled READ autoSendEnabled NOTIFY autoSendEnabledChanged)
    Q_PROPERTY(int autoSendInterval READ autoSendInterval NOTIFY autoSendIntervalChanged)

public:
    explicit SerialPortViewModel(QObject *parent = nullptr);

    PortSettingsManager* settingsManager() const;
    LogManager* logManager() const;
    DataProcessor* dataProcessor() const;
    FileSender* fileSender() const;
    bool isConnected() const;
    qint64 sentBytesCount() const;
    qint64 receivedBytesCount() const;

    // --- Actions invoked from QML ---
    Q_INVOKABLE void connectPort(const QString& portName);
    Q_INVOKABLE void disconnectPort();
    Q_INVOKABLE void clearByteCounts();
    Q_INVOKABLE void sendData(const QString& text);
    Q_INVOKABLE void setAutoSend(bool enabled, int interval, const QString& data);

    // --- Auto-send property accessors ---
    bool autoSendEnabled() const;
    int autoSendInterval() const;

public slots:
    // --- Slots for signals from SerialPortManager ---
    void onDataReceived(const QByteArray& data);
    void onErrorOccurred(const QString& errorString);
    void onPortOpened();
    void onPortClosed();

private slots:
    // --- Internal slots ---
    void onAutoSendTimeout();
    void onFileSenderLog(const QString& message);

signals:
    void autoSendEnabledChanged();
    void autoSendIntervalChanged();
    void connectionStatusChanged(bool isOpen, const QString& portName);
    void sentBytesCountChanged();
    void receivedBytesCountChanged();

private:
    // --- Byte Counters ---
    qint64 m_sentBytesCount = 0;
    qint64 m_receivedBytesCount = 0;

    // --- Child Objects ---
    SerialPortManager* m_serialPortManager;
    DataProcessor* m_dataProcessor;
    LogManager* m_logManager;
    PortSettingsManager* m_settingsManager;
    FileSender* m_fileSender;

    // --- Auto-send members ---
    QTimer* m_autoSendTimer;
    bool m_autoSendEnabled = false;
    int m_autoSendInterval = 1000;
    QString m_autoSendData;

    void setAutoSendEnabled(bool enabled);
    void setAutoSendInterval(int ms);
};

#endif // SERIALPORTVIEWMODEL_H
