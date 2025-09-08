#ifndef PORTSETTINGSMANAGER_H
#define PORTSETTINGSMANAGER_H

#include <QObject>
#include <QStringList>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "serialportmanager.h"

class PortSettingsManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList baudRatesModel READ baudRatesModel CONSTANT)
    Q_PROPERTY(QStringList dataBitsModel READ dataBitsModel CONSTANT)
    Q_PROPERTY(QStringList stopBitsModel READ stopBitsModel CONSTANT)
    Q_PROPERTY(QStringList parityModel READ parityModel CONSTANT)
    Q_PROPERTY(QStringList availablePorts READ availablePorts NOTIFY availablePortsChanged)
    Q_PROPERTY(QStringList duplexOptions READ duplexOptions CONSTANT)

    Q_PROPERTY(QString currentBaudRate READ currentBaudRate WRITE setCurrentBaudRate NOTIFY currentBaudRateChanged)
    Q_PROPERTY(QString currentDataBits READ currentDataBits WRITE setCurrentDataBits NOTIFY currentDataBitsChanged)
    Q_PROPERTY(QString currentStopBits READ currentStopBits WRITE setCurrentStopBits NOTIFY currentStopBitsChanged)
    Q_PROPERTY(QString currentParity READ currentParity WRITE setCurrentParity NOTIFY currentParityChanged)
    Q_PROPERTY(QString currentDuplexOption READ currentDuplexOption WRITE setCurrentDuplexOption NOTIFY currentDuplexOptionChanged FINAL)

public:
    explicit PortSettingsManager(QObject *parent = nullptr);

    QStringList baudRatesModel() const;
    QStringList dataBitsModel() const;
    QStringList stopBitsModel() const;
    QStringList parityModel() const;
    QStringList availablePorts() const;
    QStringList duplexOptions() const;

    QString currentBaudRate() const;
    void setCurrentBaudRate(const QString &baudRate);

    QString currentDataBits() const;
    void setCurrentDataBits(const QString &dataBits);

    QString currentStopBits() const;
    void setCurrentStopBits(const QString &stopBits);

    QString currentParity() const;
    void setCurrentParity(const QString &parity);

    QString currentDuplexOption() const;
    void setCurrentDuplexOption(const QString &duplexOption);

    Q_INVOKABLE void refreshPortList();

    // Conversion utilities
    QSerialPort::BaudRate selectedBaudRate() const;
    QSerialPort::DataBits selectedDataBits() const;
    QSerialPort::Parity selectedParity() const;
    QSerialPort::StopBits selectedStopBits() const;
    SerialPortManager::DuplexMode selectedDuplexMode() const;

signals:
    void currentBaudRateChanged();
    void currentDataBitsChanged();
    void currentStopBitsChanged();
    void currentParityChanged();
    void availablePortsChanged();
    void currentDuplexOptionChanged();

private:
    QStringList m_baudRatesModel;
    QStringList m_dataBitsModel;
    QStringList m_stopBitsModel;
    QStringList m_parityModel;
    QStringList m_availablePorts;
    QStringList m_duplexOptions;

    QString m_currentBaudRate;
    QString m_currentDataBits;
    QString m_currentStopBits;
    QString m_currentParity;
    QString m_currentduplexOption;
};

#endif // PORTSETTINGSMANAGER_H
