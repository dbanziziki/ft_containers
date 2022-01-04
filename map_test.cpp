#include "map.hpp"

#include <map>
#include <iostream>

int main() {
    ft::map<std::string, int> m;
    typedef ft::map<std::string, int>::iterator iterator;

    ft::pair<iterator, bool> res = m.insert(ft::make_pair("David", 23));
    std::cout << res.first->first << " " << res.first->second << std::endl;
    return 0;
}
