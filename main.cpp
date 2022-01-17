#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "map.hpp"
#include "vector.hpp"

typedef ft::map<int, std::string>::iterator iterator;
typedef ft::map<int, std::string>::const_iterator const_iterator;

int main() {
    ft::vector<int> v;
    for (int i = 0; i < 5; ++i) {
        v.push_back(i + 42);
    }
    for (ft::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << "\n";
    }
    std::cout << "Capacity: " << v.capacity() << std::endl;
    std::cout << "size: " << v.size() << std::endl;
    v.clear();
    std::cout << "size: " << v.size() << std::endl;
    return 0;
}
