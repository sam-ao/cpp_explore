#include "StringReverseTransformer.h"

std::string cppexplore::StringReverseTransformer::transform(std::string input) const {
    auto length = input.length();
    for (auto i = 0; i < ((int)length / 2); i++) {
        auto swap = input.at(i);
        auto j = length - 1 - i;
        input.at(i) = input.at(j);
        input.at(j) = swap;
    }

    return input;
}

cppexplore::StringTransformerTypes::Types cppexplore::StringReverseTransformer::getType() const  {
    return cppexplore::StringTransformerTypes::STRING_REVERSE;
}
