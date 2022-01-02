#include <iostream>

#include "utils.hpp"

int main(int argc, char const *argv[]) {
    ft::pair<std::string, int> p;

    p = ft::make_pair("David", 23);
    std::cout << "first: " << p.first << " "
              << "Age: " << p.second << std::endl;
    ft::pair<int, float> t = ft::make_pair(21, 21.0f);
    return 0;
}
