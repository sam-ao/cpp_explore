#include "StringTransformBridge.h"

using namespace cppexplore;

void StringTransformBridge::registerTransformer(StringTransformer* transformer)
{
    transformerMap.insert(std::make_pair(transformer->getType(), transformer));
}

void StringTransformBridge::handleInput(QString inputString, int transformerType)
{
    emit outputGenerated(QString::fromStdString(transformerMap.at(static_cast<StringTransformerTypes::Types>(transformerType))->transform(inputString.toStdString())));
}

