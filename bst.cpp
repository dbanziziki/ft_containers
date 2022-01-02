#include "bst.hpp"

#include <iostream>
#include <map>

typedef ft::BST<ft::pair<int, std::string> >::pointer pointer;
typedef std::map<int, std::string>::iterator iterator;
typedef ft::BST<ft::pair<int, std::string> >::iterator ft_iterator;
typedef ft::BST<ft::pair<int, std::string> >::pointer pointer;

int main() {
    ft::pair<int, std::string> p = ft::make_pair(1, "a");
    ft::BST<ft::pair<int, std::string> > a;

    ft::pair<ft_iterator, bool> res = a.insert(p);
    res = a.insert(ft::make_pair(2, "Bono"));
    res = a.insert(ft::make_pair(3, "Dono"));
    res = a.insert(ft::make_pair(2, "Bono"));
    if (!res.second) {
        std::cout << "Value already in three" << std::endl;
    }
    
    ft_iterator first = a.begin();
    ft_iterator end = a.end();
    std::cout << "Begin: " << first->first << " " << first->second << std::endl;
    std::cout << "End: " << end->first << " " << end->second << std::endl;
    std::cout << res.first->first << " " << res.first->second << std::endl;
    a.inorder(a.getHead());
    return 0;
}
