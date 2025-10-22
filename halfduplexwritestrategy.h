#ifndef HALFDUPLEXWRITESTRATEGY_H
#define HALFDUPLEXWRITESTRATEGY_H
#include "IWriteStrategy.h"
class HalfDuplexWriteStrategy : public IWriteStrategy
{
public:
    using IWriteStrategy::IWriteStrategy;
    qint64 write(QSerialPort* port,const QByteArray& data) override;
};

#endif // HALFDUPLEXWRITESTRATEGY_H
