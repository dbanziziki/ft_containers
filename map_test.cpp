#include "map.hpp"

#include <iostream>
#include <map>

int main() {
    ft::map<std::string, int> m;
    typedef ft::map<std::string, int>::iterator iterator;

    ft::pair<iterator, bool> res = m.insert(ft::make_pair("David", 23));
    (void)res;
    m.insert(ft::make_pair("Jhon", 42));
    iterator begin = m.begin();
    iterator end = m.end();

    for (; begin != end; ++begin) {
        std::cout << begin->first << " " << begin->second << std::endl;
    }

    begin = m.begin();

    ft::map<std::string, int> other(begin, end);

    iterator other_begin = other.begin();
    iterator other_end = other.end();
    for (; other_begin != other_end; ++other_begin) {
        std::cout << other_begin->first << " " << other_begin->second
                  << std::endl;
    }

    other.erase("David");
    std::cout << "After erase" << std::endl;
    other_begin = other.begin();
    std::cout << other_begin->first << " " << other_begin->second << std::endl;
    return 0;
}
