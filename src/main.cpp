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

using namespace cppexplore;

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QtObjectNames qtObjectNames;
    engine.rootContext()->setContextProperty("qtObjectNames", &qtObjectNames);

    OutputReceiver::declareQML();

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    StringTransformerTypes::declareQML();

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    QObject *object = engine.rootObjects().first();

    std::unique_ptr<StringTransformBridge> bridge(new StringTransformBridge());

    std::unique_ptr<StringTransformer> reverseStringTransformer(new StringReverseTransformer());
    std::unique_ptr<StringTransformer> uppercaseStringTransformer(new StringUppercaseTransformer());
    std::unique_ptr<StringTransformer> lowercaseStringTransformer(new StringLowercaseTransformer());
    bridge.get()->registerTransformer(reverseStringTransformer.get());
    bridge.get()->registerTransformer(uppercaseStringTransformer.get());
    bridge.get()->registerTransformer(lowercaseStringTransformer.get());

    QObject::connect(object->findChild<QObject*>(qtObjectNames.inputSubmitName()), SIGNAL(inputSubmit(QString, int)),
                      bridge.get(), SLOT(handleInput(QString, int)));
    QObject::connect(bridge.get(), SIGNAL(outputGenerated(QString)),
                      object->findChild<QObject*>(qtObjectNames.outputReceiverName()), SLOT(onOutputReceived(QString)));

    return app.exec();
}
