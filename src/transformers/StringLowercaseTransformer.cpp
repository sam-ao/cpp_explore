#include "StringLowercaseTransformer.h"

std::string cppexplore::StringLowercaseTransformer::transform(std::string input) const {
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    return input;
}

cppexplore::StringTransformerTypes::Types cppexplore::StringLowercaseTransformer::getType() const {
    return cppexplore::StringTransformerTypes::STRING_LOWERCASE;
}
