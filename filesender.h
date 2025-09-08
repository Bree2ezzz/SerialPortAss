#ifndef FILESENDER_H
#define FILESENDER_H

#include <QObject>
#include <QFile>
#include <QTimer>
#include <QUrl>
#include "serialportmanager.h"

class FileSender : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isSending READ isSending NOTIFY isSendingChanged)

public:
    explicit FileSender(SerialPortManager* serialPortManager, QObject *parent = nullptr);
    ~FileSender();

    bool isSending() const;

    Q_INVOKABLE void startSending(const QUrl& fileUrl);
    Q_INVOKABLE void stopSending();

signals:
    void isSendingChanged();
    void logMessage(const QString& message); // 用于向ViewModel发送日志消息

private slots:
    void sendNextChunk();

private:
    void setIsSending(bool isSending);

    SerialPortManager* m_serialPortManager;
    QFile m_file;
    QTimer* m_sendTimer;

    qint64 m_totalBytes = 0;
    qint64 m_sentBytes = 0;
    int m_lastProgressReport = 0;
    bool m_isSending = false;
};

#endif // FILESENDER_H
