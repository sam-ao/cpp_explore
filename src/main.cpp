#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include "qt/QtObjectNames.h"
#include "qt/StringTransformBridge.h"
#include "qt/OutputReceiver.h"
#include "transformers/StringReverseTransformer.h"
#include "transformers/StringUppercaseTransformer.h"
#include "transformers/StringLowercaseTransformer.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    cppexplore::QtObjectNames qtObjectNames;
    engine.rootContext()->setContextProperty("qtObjectNames", &qtObjectNames);

    cppexplore::OutputReceiver::declareQML();

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    cppexplore::StringTransformerTypes::declareQML();

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    auto *object = engine.rootObjects().first();

    auto bridge = std::make_unique<cppexplore::StringTransformBridge>();

    auto reverseStringTransformer = std::make_unique<cppexplore::StringReverseTransformer>();
    auto uppercaseStringTransformer = std::make_unique<cppexplore::StringUppercaseTransformer>();
    auto lowercaseStringTransformer = std::make_unique<cppexplore::StringLowercaseTransformer>();

    bridge->registerTransformer(*reverseStringTransformer);
    bridge->registerTransformer(*uppercaseStringTransformer);
    bridge->registerTransformer(*lowercaseStringTransformer);

    QObject::connect(object->findChild<QObject*>(qtObjectNames.inputSubmitName()), SIGNAL(inputSubmit(QString, int)),
                      bridge.get(), SLOT(handleInput(QString, int)));
    QObject::connect(bridge.get(), SIGNAL(outputGenerated(QString)),
                      object->findChild<QObject*>(qtObjectNames.outputReceiverName()), SLOT(onOutputReceived(QString)));

    return app.exec();
}
