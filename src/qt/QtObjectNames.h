#pragma once
#include <QObject>

namespace cppexplore
{
    class QtObjectNames: public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QString inputSubmitName READ inputSubmitName CONSTANT)
        Q_PROPERTY(QString outputReceiverName READ outputReceiverName CONSTANT)

    public:
        QString inputSubmitName();
        QString outputReceiverName();
    };
}
