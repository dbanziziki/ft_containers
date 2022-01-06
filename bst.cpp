#include "bst.hpp"

#include <iostream>
#include <map>

typedef ft::BST<ft::pair<std::string, int> >::pointer pointer;
typedef std::map<std::string, int>::iterator iterator;
typedef ft::BST<ft::pair<std::string, int> >::iterator ft_iterator;
typedef ft::BST<ft::pair<std::string, int> >::pointer pointer;

int main() {
    ft::pair<std::string, int> p = ft::make_pair("a", 78);
    ft::BST<ft::pair<std::string, int> > a;
    std::map<std::string, int> map;

    map.insert(std::make_pair(p.first, p.second));
    map["Bono"] = 2;

    ft::pair<ft_iterator, bool> res = a.insert(p);
    res = a.insert(ft::make_pair("Bono", 2));

    // a.inorder(a.getHead());
    a.deleteNode(a.getHead(), "Bono");
    map.erase("Bono");
    // std::cout << "---------" << std::endl;
    ft_iterator it = a.begin();
    iterator begin = map.begin();
    std::cout << it->first << " - " << it->second << std::endl;
    std::cout << begin->first << " - " << begin->second << std::endl;
    return 0;
}
