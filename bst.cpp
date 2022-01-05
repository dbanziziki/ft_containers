#include "bst.hpp"

#include <iostream>
#include <map>

typedef ft::BST<ft::pair<int, std::string> >::pointer pointer;
typedef std::map<int, std::string>::iterator iterator;
typedef ft::BST<ft::pair<int, std::string> >::iterator ft_iterator;
typedef ft::BST<ft::pair<int, std::string> >::pointer pointer;

int main() {
    ft::pair<int, std::string> p = ft::make_pair(78, "a");
    ft::BST<ft::pair<int, std::string> > a;

    ft::pair<ft_iterator, bool> res = a.insert(p);
    res = a.insert(ft::make_pair(2, "Bono"));
    res = a.insert(ft::make_pair(1, "Oregon lowest"));
    res = a.insert(ft::make_pair(4, "Jason"));
    res = a.insert(ft::make_pair(140, "Brandon"));
    res = a.insert(ft::make_pair(21, "Brandon"));
    res = a.insert(ft::make_pair(98, "Brandon"));

    ft_iterator first = a.begin();
    ft_iterator last = a.end();
    for (; first != last; ++first) {
        std::cout << first->first << "-" << first->second << std::endl;
    }
    first = a.begin();
    --last;
    std::cout << "-------\n";
    for (; last != first; --last) {
        std::cout << last->first << " " << last->second << std::endl;
    }
    std::cout << a.begin()->second << std::endl;

    return 0;
}
