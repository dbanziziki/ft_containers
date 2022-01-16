#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "map.hpp"
#include "vector.hpp"

typedef ft::map<int, std::string>::iterator iterator;
typedef ft::map<int, std::string>::const_iterator const_iterator;

int main() {
    ft::map<int, std::string> m;

    for (int i = 0; i < 10; i++) {
        m.insert(ft::make_pair(i, "Plop"));
    }

    ft::map<int, std::string>::iterator it = m.lower_bound(9);
    std::cout << it->first << " " << it->second << std::endl;
    it = m.upper_bound(4);
    std::cout << it->first << " " << it->second << std::endl;
    ft::pair<const_iterator, const_iterator> p = m.equal_range(2);
    std::cout << "Lower bound: " << p.first->first << std::endl;
    std::cout << "upper bound: " << p.second->first << std::endl;
    return 0;
}
