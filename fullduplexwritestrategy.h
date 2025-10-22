#ifndef FULLDUPLEXWRITESTRATEGY_H
#define FULLDUPLEXWRITESTRATEGY_H
#include "IWriteStrategy.h"
class FullDuplexWriteStrategy : public IWriteStrategy
{
public:
    //全双工策略write
    using IWriteStrategy::IWriteStrategy; // 继承构造函数
    qint64 write(QSerialPort* port, const QByteArray& data) override;
};

#endif // FULLDUPLEXWRITESTRATEGY_H
