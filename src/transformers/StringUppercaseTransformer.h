#pragma once
#include "StringTransformer.h"

namespace cppexplore
{
    class StringUppercaseTransformer : public StringTransformer
    {
        public:
            std::string transform(std::string input);
            StringTransformerTypes::Types getType();
    };
}
