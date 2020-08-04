#include "StringUppercaseTransformer.h"

using namespace cppexplore;

std::string StringUppercaseTransformer::transform(std::string input) {
    std::transform(input.begin(), input.end(), input.begin(), ::toupper);
    return input;
}

StringTransformerTypes::Types StringUppercaseTransformer::getType()  {
    return StringTransformerTypes::STRING_UPPERCASE;
}
