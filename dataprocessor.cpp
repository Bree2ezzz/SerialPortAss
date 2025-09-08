#include "dataprocessor.h"
#include <QDebug>

DataProcessor::DataProcessor(QObject *parent) : QObject(parent)
{
}

void DataProcessor::setSendMode(const QString &mode)
{
    if (m_sendMode != mode) {
        m_sendMode = mode;
        emit sendModeChanged();
        qDebug() << "Send mode set to:" << m_sendMode;
    }
}

QString DataProcessor::sendMode() const
{
    return m_sendMode;
}

void DataProcessor::setReceiveMode(const QString &mode)
{
    if (m_receiveMode != mode) {
        m_receiveMode = mode;
        qDebug() << "Receive mode set to:" << m_receiveMode;
    }
}

QString DataProcessor::receiveMode() const
{
    return m_receiveMode;
}

QByteArray DataProcessor::prepareDataForSend(const QString &text, bool &ok, QString &error)
{
    ok = false;
    if (text.isEmpty()) {
        error = "发送数据为空";
        return QByteArray();
    }

    QByteArray data;
    if (m_sendMode == "HEX") {
        QString sanitizedText;
        sanitizedText.reserve(text.length());

        for (QChar c : text) {
            if (DataProcessor::isHexDigit(c)) {
                sanitizedText.append(c);
            }
        }

        if (sanitizedText.isEmpty()) {
            error = "发送数据为空";
            return QByteArray();
        }

        if (sanitizedText.length() % 2 != 0) {
            sanitizedText.prepend('0');
        }

        data = QByteArray::fromHex(sanitizedText.toLatin1());
        ok = true;
        return data;

    } else if (m_sendMode == "ASCII") {
        data = text.toUtf8();
        ok = true;
        return data;
    }

    error = "未知的发送模式";
    return QByteArray();
}

QString DataProcessor::processReceivedData(const QByteArray &data)
{
    if (m_receiveMode == "ASCII") {
        return QString::fromUtf8(data);
    } else if (m_receiveMode == "HEX") {
        return QString::fromLatin1(data.toHex(' ').toUpper());
    }
    return QString(); // Should not happen
}

bool DataProcessor::isHexDigit(QChar ch)
{
    return ch.isDigit() ||
           (ch >= 'A' && ch <= 'F') ||
           (ch >= 'a' && ch <= 'f');
}
