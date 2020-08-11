#include "OutputReceiver.h"

cppexplore::OutputReceiver::OutputReceiver(QObject *parent) : QObject(parent)
{
}

void cppexplore::OutputReceiver::onOutputReceived(const QString& output)
{
    emit outputRelay(output);
}

void cppexplore::OutputReceiver::declareQML()
{
    qmlRegisterType<OutputReceiver>("com.cppexplore", 1, 0, "OutputReceiver");
}

