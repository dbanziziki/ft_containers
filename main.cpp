#include <iostream>
#include <map>
#include <vector>

#include "map.hpp"
#include "vector.hpp"

typedef ft::map<std::string, int>::const_iterator const_iterator;
typedef ft::map<std::string, int>::iterator iterator;
int main() {
    ft::map<std::string, int> m;

    m["hello"] = 21;
    m["hllo"] = 24;
    m["ello"] = 29;

    iterator it = m.begin();
    const_iterator cit = it;

    it->second = 67;
    for (; cit != m.end(); ++cit) {
        std::cout << cit->first << " " << cit->second << std::endl;
    }
    --cit;

    std::cout << cit->first << " " << cit->second << std::endl;
    /*    ft::map<int, std::string> other;
        ft::map<int, std::string>::iterator it;

        other[4] = "Hello";
        it = other.begin();
        std::cout << it->first << " " << it->second << std::endl;

        other = m;

        it = other.begin();
        std::cout << it->first << " " << it->second << std::endl;*/
    return 0;
}
