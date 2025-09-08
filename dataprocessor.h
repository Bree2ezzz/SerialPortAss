#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include <QObject>
#include <QByteArray>
#include <QString>
#include <QRegularExpression>

class DataProcessor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString sendMode READ sendMode NOTIFY sendModeChanged)

public:
    explicit DataProcessor(QObject *parent = nullptr);

    Q_INVOKABLE void setSendMode(const QString& mode);
    QString sendMode() const;

    Q_INVOKABLE void setReceiveMode(const QString& mode);
    QString receiveMode() const;

    QByteArray prepareDataForSend(const QString& text, bool& ok, QString& error);
    QString processReceivedData(const QByteArray& data);
    static bool isHexDigit(QChar ch);
signals:
    void sendModeChanged();

private:
    QString m_sendMode = "HEX";
    QString m_receiveMode = "HEX";
};

#endif // DATAPROCESSOR_H
