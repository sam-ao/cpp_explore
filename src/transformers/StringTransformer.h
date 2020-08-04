#pragma once
#include "string"
#include "StringTransformerTypes.h"

namespace cppexplore
{
    class StringTransformer
    {
        public:
            virtual std::string transform(std::string input) = 0;
            virtual StringTransformerTypes::Types getType() = 0;
    };
}
