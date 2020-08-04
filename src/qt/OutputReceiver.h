#pragma once
#include <QObject>
#include <QQmlApplicationEngine>

namespace cppexplore
{
    class OutputReceiver : public QObject
    {
        Q_OBJECT
    public slots:
        void onOutputReceived(QString output);
    signals:
        void outputRelay(QString output);
    public:
        explicit OutputReceiver(QObject *parent = nullptr);
        static void declareQML();
    };
}
