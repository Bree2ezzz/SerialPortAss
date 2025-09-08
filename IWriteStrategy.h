#ifndef IWRITESTRATEGY_H
#define IWRITESTRATEGY_H
#include <QObject>
#include <QSerialPort>
#include <QByteArray>

class IWriteStrategy : public QObject
{
    Q_OBJECT
public:
    explicit IWriteStrategy(QObject *parent = nullptr) : QObject(parent) {}
    virtual ~IWriteStrategy() = default;

    virtual void write(QSerialPort* port, const QByteArray& data) = 0;
};

#endif // IWRITESTRATEGY_H
