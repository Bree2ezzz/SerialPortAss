#include "filesender.h"
#include <QFileInfo>

const int CHUNK_SIZE = 64; // 每次发送的块大小（字节）
const int SEND_INTERVAL = 10; // 发送时间间隔（毫秒）

FileSender::FileSender(SerialPortManager* serialPortManager, QObject *parent)
    : QObject(parent), m_serialPortManager(serialPortManager)
{
    m_sendTimer = new QTimer(this);
    connect(m_sendTimer, &QTimer::timeout, this, &FileSender::sendNextChunk);
}

FileSender::~FileSender()
{
    stopSending();
}

bool FileSender::isSending() const
{
    return m_isSending;
}

void FileSender::startSending(const QUrl& fileUrl)
{
    if (m_isSending) {
        emit logMessage("错误：已有一个文件正在发送中。");
        return;
    }

    if (!m_serialPortManager || !m_serialPortManager->isOpen()) {
        emit logMessage("错误：串口未连接，无法发送文件。");
        return;
    }

    if (m_file.isOpen()) {
        m_file.close();
    }

    m_file.setFileName(fileUrl.toLocalFile());

    if (!m_file.open(QIODevice::ReadOnly)) {
        emit logMessage("错误：无法打开文件: " + m_file.errorString());
        return;
    }

    m_totalBytes = m_file.size();
    m_sentBytes = 0;
    m_lastProgressReport = 0;

    if (m_totalBytes == 0) {
        emit logMessage("警告：文件为空，无需发送。");
        m_file.close();
        return;
    }

    setIsSending(true);
    emit logMessage("开始发送文件: " + QFileInfo(m_file).fileName());
    m_sendTimer->start(SEND_INTERVAL);
}

void FileSender::stopSending()
{
    if (!m_isSending) {
        return;
    }

    m_sendTimer->stop();
    if (m_file.isOpen()) {
        m_file.close();
    }
    setIsSending(false);
    emit logMessage("文件发送已手动停止。");
}

void FileSender::sendNextChunk()
{
    if (!m_file.isOpen() || !m_serialPortManager->isOpen()) {
        m_sendTimer->stop();
        setIsSending(false);
        emit logMessage("错误：文件发送中断（文件或串口已关闭）。");
        return;
    }

    if (m_file.atEnd()) {
        m_sendTimer->stop();
        m_file.close();
        setIsSending(false);
        emit logMessage("文件发送完成。");
        return;
    }

    QByteArray chunk = m_file.read(CHUNK_SIZE);
    if (!chunk.isEmpty()) {
        m_serialPortManager->write(chunk);
        m_sentBytes += chunk.size();

        int currentProgress = (m_sentBytes * 100) / m_totalBytes;
        if (currentProgress >= m_lastProgressReport + 25 && currentProgress < 100) {
            m_lastProgressReport = (currentProgress / 25) * 25; // Round down to nearest 25
            emit logMessage(QString("文件发送进度: %1%").arg(m_lastProgressReport));
        }
    }
}

void FileSender::setIsSending(bool isSending)
{
    if (m_isSending != isSending) {
        m_isSending = isSending;
        emit isSendingChanged();
    }
}
