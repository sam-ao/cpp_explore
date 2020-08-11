#pragma once
#include "StringTransformer.h"

namespace cppexplore
{
    class StringUppercaseTransformer : public IStringTransformer
    {
        public:
            std::string transform(std::string input) const override;
            StringTransformerTypes::Types getType() const override;
    };
}
