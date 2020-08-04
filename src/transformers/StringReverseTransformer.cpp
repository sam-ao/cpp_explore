#include "StringReverseTransformer.h"

using namespace cppexplore;

std::string StringReverseTransformer::transform(std::string input) {
    int length = input.length();
    for (int i = 0; i < (length / 2); i++) {
        char swap = input[i];
        int j = length - 1 - i;
        input[i] = input[j];
        input[j] = swap;
    }

    return input;
}

StringTransformerTypes::Types StringReverseTransformer::getType()  {
    return StringTransformerTypes::STRING_REVERSE;
}
