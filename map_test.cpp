#include "map.hpp"

#include <iostream>
#include <map>

int main() {
    ft::map<int, std::string> m;
    std::map<int, std::string> map;
    typedef ft::map<int, std::string>::iterator iterator;
    typedef ft::map<int, std::string>::reverse_iterator reverse_iterator;

    for (int i = 0; i < 4; i++) {
        m.insert(ft::make_pair(i, "hello " + std::to_string(i)));
    }
    
    /*for (; begin != end; ++begin) {
        std::cout << begin->first << " " << begin->second << std::endl;
    }
    begin = m.begin();
    end--;
    end--;
    m.erase(begin, end);
    std::cout << "---------\n";
    m[5] = "There";
    std::cout << "Should be null: " << m[78] << std::endl;
    begin = m.begin();
    end = m.end();
    for (; begin != end; ++begin) {
        std::cout << begin->first << " " << begin->second << std::endl;
    }

    int n = m.erase(78);
    std::cout << "Erased: " << n << std::endl;
*/
    ft::map<int, std::string> other;

    other[19] = "School";
    other[42] = "Network";

    m.swap(other);
    iterator begin = m.begin();
    iterator end = m.end();
    for (; begin != end; ++begin) {
        std::cout << begin->first << " " << begin->second << std::endl;
    }
    reverse_iterator rfirst = other.rbegin();
    reverse_iterator rlast = other.rend();

    for (; rfirst != rlast; ++rfirst) {
        std::cout << rfirst->item.first << "=> " << rfirst->item.second << std::endl;
    }
    // typedef std::map<int, std::string>::iterator iterator;
    // std::map<int, std::string> map;
    // for (int i = 0; i < 4; ++i) {
    //     map.insert(std::make_pair(i, "There " + std::to_string(i)));
    // }
    // iterator last = map.end();
    // iterator first = map.begin();
    // last--;
    // last--;
    // map.erase(first, last);
    // first = map.begin();
    // last = map.end();
    // for (; first != last; ++first) {
    //     std::cout << first->first << " " << first->second << std::endl;
    // }
    return 0;
}
