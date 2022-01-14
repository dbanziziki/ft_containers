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

    tree.insert(ft::make_pair(21, "Savage"));
    tree.insert(ft::make_pair(12, "Manga"));
    tree.insert(ft::make_pair(42, "school"));

    /*
                [21]
            [12] .  [42]
    */
    const_iterator cit = tree.begin();
    std::cout << cit->first << " " << cit->second << std::endl;
    cit++;
    std::cout << cit->first << " " << cit->second << std::endl;
    return 0;
}
