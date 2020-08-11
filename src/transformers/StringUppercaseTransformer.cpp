#include "StringUppercaseTransformer.h"

std::string cppexplore::StringUppercaseTransformer::transform(std::string input) const {
    std::transform(input.begin(), input.end(), input.begin(), ::toupper);
    return input;
}

cppexplore::StringTransformerTypes::Types cppexplore::StringUppercaseTransformer::getType() const  {
    return cppexplore::StringTransformerTypes::STRING_UPPERCASE;
}
