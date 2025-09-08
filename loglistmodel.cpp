#include "loglistmodel.h"
#include <QFileInfo>
#include <QDir>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

LogListModel::LogListModel(QObject *parent){}

int LogListModel::rowCount(const QModelIndex &parent) const
{
    return m_logs.size();
}

QVariant LogListModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() < 0 || index.row() >= m_logs.size())
        return QVariant();
    const LogEntry &entry = m_logs.at(index.row());
    switch (role) {
    case TimestampRole: return entry.timestamp.toString("yyyy-MM-dd HH:mm:ss.zzz");
    case DirectionRole: return entry.direction;
    case TypeRole:      return entry.type;
    case DataRole:      return entry.data;
    default:            return QVariant();
    }
}

QHash<int, QByteArray> LogListModel::roleNames() const
{
    return {
        {TimestampRole, "timestamp"},
        {DirectionRole, "direction"},
        {TypeRole, "type"},
        {DataRole, "data"}
    };
}

void LogListModel::addLog(const QString &direction, const QString &type, const QString &data)
{
    //发出信号 即将向viewlist插入新行
    /*parma
     * 父项索引，对于QAbstractListModel一维列表，父对象是空
     * 插入的第一行索引-》插入位置
     * 插入的最后一行索引
     * 单词插入一行，所以两值相同
*/
    beginInsertRows(QModelIndex(), m_logs.size(), m_logs.size());
    LogEntry entry;
    entry.timestamp = QDateTime::currentDateTime();
    entry.direction = direction;
    entry.type = type;
    entry.data = data;
    m_logs.append(entry);
    endInsertRows();//发出信号，插入完成
}

void LogListModel::clear()
{
    beginResetModel();
    m_logs.clear();
    endResetModel();
}

void LogListModel::exportLog(const QUrl &folderPath)
{
    QString localFolderPath = folderPath.toLocalFile();
    if (localFolderPath.isEmpty()) {
        qWarning() << "无效的导出路径。";
        return;
    }
    qDebug() << " 开始拼接";
    QDir dir(localFolderPath);
    QString dataTime = QDateTime::currentDateTime().toString("yyyy-MM-dd_hh-mm");
    QString fileName = QString("log_export_%1.json").arg(dataTime);
    QString fullPath = dir.filePath(fileName);
    qDebug() << " 拼接后fullpath为" << fullPath;

    QFile file(fullPath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "无法打开文件进行写入:" << file.errorString();
        return;
    }
    qDebug() << " 打开文件成功";
    QJsonArray logArray;
    for(auto const& log : m_logs){
        QJsonObject object;
        object["timestamp"] = log.timestamp.toString(Qt::ISODateWithMs);
        object["direction"] = (log.direction == "TX" ? "Sent" :
                                   log.direction == "RX" ? "Received" : "System");
        object["type"] = log.type;
        object["data"] = log.data;
        logArray.append(object);
    }
    qDebug() << " 数据读取完毕";
    
    QJsonDocument doc(logArray);
    file.write(doc.toJson());
    file.close();
    qDebug() << "写入文件成功";
}
