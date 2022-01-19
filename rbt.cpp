#include <iostream>

#include "RB_tree.hpp"

int main(int argc, char const *argv[]) {
    ft::RBTree<ft::pair<int, std::string> > tree;
    tree.BSTinsert(ft::make_pair(55, "Hello"));
    tree.BSTinsert(ft::make_pair(40, "Hello"));
    tree.BSTinsert(ft::make_pair(65, "Hello"));
    tree.BSTinsert(ft::make_pair(60, "Hello"));
    tree.BSTinsert(ft::make_pair(75, "Hello"));
    tree.BSTinsert(ft::make_pair(57, "Hello"));
    tree.printHelper(tree.getRoot(), "", true);
    return 0;
}
