#include <iostream>
#include <vector>

#include "map.hpp"

int main() {
    ft::map<int, std::string> m;
    m[14] = "Hello";
    m[12] = "Momo";

    ft::map<int, std::string> other(m);

    return 0;
}
