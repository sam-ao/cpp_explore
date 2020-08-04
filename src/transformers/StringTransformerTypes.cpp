#include "StringTransformerTypes.h"

using namespace cppexplore;

StringTransformerTypes::StringTransformerTypes()
{
}

void StringTransformerTypes::declareQML()
{
    qRegisterMetaType<Types>("StringTransformerTypes");
    qmlRegisterUncreatableType<StringTransformerTypes>("com.cppexplore", 1, 0, "StringTransformerTypes", "Not creatable as it is an enum type");
}

