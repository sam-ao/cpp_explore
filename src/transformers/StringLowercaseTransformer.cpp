#include "StringLowercaseTransformer.h"

using namespace cppexplore;

std::string StringLowercaseTransformer::transform(std::string input) {
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);
    return input;
}

StringTransformerTypes::Types StringLowercaseTransformer::getType()  {
    return StringTransformerTypes::STRING_LOWERCASE;
}
