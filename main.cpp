#include <iostream>
#include <vector>

#include "map.hpp"

int main() {
    ft::map<int, std::string> m;
    m[14] = "plop";
    m[12] = "Momo";

    ft::map<int, std::string> other;
    ft::map<int, std::string>::iterator it;

    other[4] = "Hello";
    it = other.begin();
    std::cout << it->first << " " << it->second << std::endl;

    other = m;

    it = other.begin();
    std::cout << it->first << " " << it->second << std::endl;
    return 0;
}
