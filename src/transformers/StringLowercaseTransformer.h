#pragma once
#include "StringTransformer.h"

namespace cppexplore
{
    class StringLowercaseTransformer : public IStringTransformer
    {
        public:
            std::string transform(std::string input) const override;
            StringTransformerTypes::Types getType() const override;
    };
}
