#ifndef LOGLISTMODEL_H
#define LOGLISTMODEL_H

#include <QAbstractListModel>
#include "logentry.h"
#include <QUrl>
class LogListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    LogListModel(QObject *parent = nullptr);
    enum LogRoles {
        TimestampRole = Qt::UserRole + 1,//时间
        DirectionRole,//发送or接受
        TypeRole,//编码格式
        DataRole//数据
    };

    // QAbstractListModel接口 必选重写的函数
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;//有多少行
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;//提供每行的数据
    QHash<int, QByteArray> roleNames() const override;//告诉qml角色名称

    // 日志操作
    Q_INVOKABLE void addLog(const QString &direction, const QString &type, const QString &data);
    Q_INVOKABLE void clear();
    Q_INVOKABLE void exportLog(const QUrl &folderPath);


private:
    QList<LogEntry> m_logs;
    int m_maxLines = 1000; // 默认最大1000条
};

#endif // LOGLISTMODEL_H
