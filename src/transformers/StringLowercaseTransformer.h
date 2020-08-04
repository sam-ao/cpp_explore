#pragma once
#include "StringTransformer.h"

namespace cppexplore
{
    class StringLowercaseTransformer : public StringTransformer
    {
        public:
            std::string transform(std::string input);
            StringTransformerTypes::Types getType();
    };
}
