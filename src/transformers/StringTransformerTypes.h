#pragma once
#include <QObject>
#include <QQmlApplicationEngine>

namespace cppexplore
{
    class StringTransformerTypes : public QObject
    {
        Q_OBJECT
        public:
            explicit StringTransformerTypes();
            static void declareQML();

            enum Types {
                STRING_REVERSE,
                STRING_UPPERCASE,
                STRING_LOWERCASE
            };
            Q_ENUM(Types)
    };
}
