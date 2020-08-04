#pragma once
#include "StringTransformer.h"

namespace cppexplore
{
    class StringReverseTransformer : public StringTransformer
    {
        public:
            std::string transform(std::string input);
            StringTransformerTypes::Types getType();
    };
}
