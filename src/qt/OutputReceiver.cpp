#include "OutputReceiver.h"

using namespace cppexplore;

OutputReceiver::OutputReceiver(QObject *parent) : QObject(parent)
{
}

void OutputReceiver::onOutputReceived(QString output)
{
    emit outputRelay(output);
}

void OutputReceiver::declareQML()
{
    qmlRegisterType<OutputReceiver>("com.cppexplore", 1, 0, "OutputReceiver");
}

