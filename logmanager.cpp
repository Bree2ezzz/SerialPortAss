#include "logmanager.h"
#include <QtConcurrent>
#include <QDebug>

LogManager::LogManager(QObject *parent) : QObject(parent)
{
    m_logListModel = new LogListModel(this);
}

LogListModel *LogManager::logListModel() const
{
    return m_logListModel;
}

void LogManager::addLog(const QString &direction, const QString &type, const QString &data)
{
    if (m_logListModel) {
        m_logListModel->addLog(direction, type, data);
    }
}

void LogManager::clearLog()
{
    if (m_logListModel) {
        m_logListModel->clear();
    }
}

void LogManager::exportLog(const QUrl &folderPath)
{
    if (!m_logListModel) {
        return;
    }
    qDebug() << "开始导出";

    const QList<LogEntry> logsCopy = m_logListModel->snapshot();
    QtConcurrent::run([folderPath, logsCopy]() {
        LogListModel::writeLogs(folderPath, logsCopy);
    });
}

bool LogManager::autoScrollEnabled() const
{
    return m_autoScrollEnabled;
}

void LogManager::setAutoScrollEnabled(bool enabled)
{
    if (m_autoScrollEnabled != enabled) {
        m_autoScrollEnabled = enabled;
        emit autoScrollEnabledChanged();
    }
}
