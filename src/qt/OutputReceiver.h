#pragma once
#include <QObject>
#include <QQmlApplicationEngine>

namespace cppexplore
{
    class OutputReceiver : public QObject
    {
        Q_OBJECT
    public slots:
        void onOutputReceived(const QString& output);
    signals:
        void outputRelay(const QString& output);
    public:
        explicit OutputReceiver(QObject *parent = nullptr);
        static void declareQML();
    };
}
