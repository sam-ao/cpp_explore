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
        std::map<StringTransformerTypes::Types, const IStringTransformer*> transformerMap;
    public slots:
        void handleInput(const QString& input, int transformerType);
    signals:
        void outputGenerated(const QString& ouptut);
    public:
        void registerTransformer(const IStringTransformer& transformer);
    };
}
