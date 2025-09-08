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

    QtConcurrent::run([this, folderPath]() {
/*        bool success = */m_logListModel->exportLog(folderPath);
        // if (success) {
        //     qDebug() << "Log exported successfully to:" << fileUrl.toLocalFile();
        //     emit logMessage("Success", "日志导出成功");
        // } else {
        //     qWarning() << "Failed to export log to:" << fileUrl.toLocalFile();
        //     emit logMessage("Error", "日志导出失败");
        // }
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
