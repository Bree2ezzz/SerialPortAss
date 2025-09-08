#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFontDatabase>
#include <QQuickStyle>
#include <QQmlContext>
#include "serialportviewmodel.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickStyle::setStyle("Fusion");

    QQmlApplicationEngine engine;
    SerialPortViewModel viewModel;
    engine.rootContext()->setContextProperty("serialPortViewModel", &viewModel);
    const QUrl url(QStringLiteral("qrc:/SerialPortAssQml/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);


    return app.exec();
}
