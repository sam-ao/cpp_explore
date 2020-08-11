#pragma once
#include "string"
#include "StringTransformerTypes.h"

namespace cppexplore
{
    class IStringTransformer
    {
        public:
            ~IStringTransformer() {};
            virtual std::string transform(std::string input) const = 0;
            virtual StringTransformerTypes::Types getType() const = 0;
    };
}
