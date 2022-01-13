// #include "bst.hpp"
#include <iostream>
#include <map>

// #include "vector.hpp"
#include "map.hpp"

typedef ft::BST<ft::pair<int, std::string> >::pointer pointer;
typedef ft::BST<ft::pair<int, std::string> >::iterator iterator;
typedef ft::BST<ft::pair<int, std::string> >::const_iterator const_iterator;

int main() {
    ft::BST<ft::pair<int, std::string> > tree;

    tree.insert(ft::make_pair(21, "Savege"));
    tree.insert(ft::make_pair(12, "Manga"));
    iterator it = tree.begin();
    std::cout << it->first << " " << it->second << std::endl;
    return 0;
}
