#pragma once
#include <QObject>

namespace cppexplore
{
    class QtObjectNames: public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QString inputSubmitName READ inputSubmitName CONSTANT)
        Q_PROPERTY(QString outputReceiverName READ outputReceiverName CONSTANT)
    private:
        static const std::string SUBMIT_INPUT_NAME;
        static const std::string OUPUT_RECEIVER_NAME;

    public:
        QString inputSubmitName();
        QString outputReceiverName();
    };
}
