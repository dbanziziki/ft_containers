#include "map.hpp"

#include <iostream>
#include <map>

int main() {
    ft::map<std::string, int> m;
    std::map<std::string, int> map;
    typedef ft::map<std::string, int>::iterator iterator;
    m.insert(ft::make_pair("David", 23));
    m["A"] = 78;
    iterator begin = m.begin();
    iterator end = m.end();
    // begin++;
    m.erase(begin, end);
    for (; begin != end; ++begin) {
        std::cout << begin->first << " " << begin->second << std::endl;
    }
    // m.erase(begin, end);
    // begin = m.begin();
    // std::cout << begin->first << " " << begin->second << std::endl;
    return 0;
}
