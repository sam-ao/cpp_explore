#pragma once
#include <QObject>
#include <map>
#include "../transformers/StringTransformerTypes.h"
#include "../transformers/StringTransformer.h"

namespace cppexplore
{
    class StringTransformBridge: public QObject
    {
        Q_OBJECT

    private:
        std::map<StringTransformerTypes::Types, StringTransformer*> transformerMap;
    public slots:
        void handleInput(QString input, int transformerType);
    signals:
        void outputGenerated(QString ouptut);
    public:
        void registerTransformer(StringTransformer* transformer);
    };
}
