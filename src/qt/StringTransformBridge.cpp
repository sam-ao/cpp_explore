#include "StringTransformBridge.h"

void cppexplore::StringTransformBridge::registerTransformer(const cppexplore::IStringTransformer& transformer)
{
    transformerMap.insert(std::make_pair(transformer.getType(), &transformer));
}

void cppexplore::StringTransformBridge::handleInput(const QString& inputString, int transformerType)
{
    emit outputGenerated(QString::fromStdString(transformerMap.at(static_cast<cppexplore::StringTransformerTypes::Types>(transformerType))->transform(inputString.toStdString())));
}

