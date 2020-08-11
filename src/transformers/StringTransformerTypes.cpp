#include "StringTransformerTypes.h"

cppexplore::StringTransformerTypes::StringTransformerTypes()
{
}

void cppexplore::StringTransformerTypes::declareQML()
{
    qRegisterMetaType<cppexplore::StringTransformerTypes::Types>("StringTransformerTypes");
    qmlRegisterUncreatableType<cppexplore::StringTransformerTypes>("com.cppexplore", 1, 0, "StringTransformerTypes", "Not creatable as it is an enum type");
}

