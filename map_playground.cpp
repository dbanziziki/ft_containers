#include <list>

#include "test.hpp"
#define TESTED_NAMESPACE std

int main() {
    TESTED_NAMESPACE::map<char, int> m;

    m.insert(TESTED_NAMESPACE::make_pair('a', 12));
    TESTED_NAMESPACE::map<char, int>::iterator it = m.begin();
    TESTED_NAMESPACE::map<char, int>::iterator e_it = m.end();
    std::cout << it->first << " " << it->second << std::endl;
    e_it--;
    std::cout << e_it->first << " " << e_it->second << std::endl;
    return 0;
}
