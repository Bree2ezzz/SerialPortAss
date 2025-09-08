#ifndef LOGENTRY_H
#define LOGENTRY_H
#include <QDateTime>
struct LogEntry {
    QDateTime timestamp;
    QString direction; // "TX" or "RX" "warn"
    QString type;      // "HEX" or "ASCII"
    QString data;      // 显示用字符串
};
#endif // LOGENTRY_H
