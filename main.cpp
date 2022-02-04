#include <list>

#include "map.hpp"
#include "test.hpp"

int main(int argc, char const *argv[]) {
    ft::map<char, int> m;

    for (int i = 0; i <= 5; i++) {
        m.insert(ft::make_pair('a' + i, i * 5));
    }
    m.erase('c');
    ft::map<char, int>::iterator it = m.begin();
    for (; it != m.end(); ++it) {
        std::cout << it->first << " " << it->second << "\n";
    }
    m.erase('a');
    // m.erase(m.begin(), m.end());
    return 0;
}
