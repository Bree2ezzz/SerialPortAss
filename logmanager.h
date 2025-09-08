#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <QObject>
#include <QUrl>
#include "loglistmodel.h"

class LogManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(LogListModel* logListModel READ logListModel CONSTANT)
    Q_PROPERTY(bool autoScrollEnabled READ autoScrollEnabled WRITE setAutoScrollEnabled NOTIFY autoScrollEnabledChanged)

public:
    explicit LogManager(QObject *parent = nullptr);

    LogListModel* logListModel() const;

    Q_INVOKABLE void addLog(const QString& direction, const QString& type, const QString& data);
    Q_INVOKABLE void clearLog();
    Q_INVOKABLE void exportLog(const QUrl& folderPath);

    bool autoScrollEnabled() const;
    void setAutoScrollEnabled(bool enabled);

signals:
    void autoScrollEnabledChanged();
    void logMessage(const QString& type, const QString& msg); // 用于向UI发送通知

private:
    LogListModel* m_logListModel;
    bool m_autoScrollEnabled = true;
};

#endif // LOGMANAGER_H
