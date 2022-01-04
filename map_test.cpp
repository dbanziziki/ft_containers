#include "map.hpp"

#include <map>
#include <iostream>

int main() {
    ft::map<std::string, int> m;
    typedef ft::map<std::string, int>::iterator iterator;

    ft::pair<iterator, bool> res = m.insert(ft::make_pair("David", 23));
	  m["David"] = 42;
    m["Jhon"] = 32;
	  std::cout << "[] operator: " << m["David"] << std::endl;
	  std::cout << "[] operator: " << m["Jhon"] << std::endl;
    std::cout << res.first->first << " " << res.first->second << std::endl;
    std::cout << "size is: " << m.size() << std::endl;
    return 0;
}
