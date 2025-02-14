#include "assignment2.hpp"

std::string exclaim(std::string& value)
{
    for (auto& ch : value) {
        if (std::ispunct(ch)) {
            ch = '!';
        }
    }
    return value;
}