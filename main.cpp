#include <iostream>

#include "bst.hpp"
#include "utils.hpp"

// ft::node<int> *insert(ft::node<int> *root, int val) {
//     if (root == NULL) {
//         return new ft::node<int>(val);
//     }
//     if (val < root->item)
//         return root->left = insert(root->left, val);
//     else if (val == root->item) {
//         std::cout << "same" << std::endl;
//         return root;
//     } else
//         return root->right = insert(root->right, val);
//     return root;
// }

typedef ft::BST<ft::pair<int, std::string> >::iterator iterator;
 
int main() {
    ft::BST<ft::pair<int, std::string> > tree;

    ft::pair<iterator, bool> inserted = tree.insert(ft::make_pair(5, "Hello"));
    inserted = tree.insert(ft::make_pair(42, "school"));
    inserted = tree.insert(ft::make_pair(12, "school"));
    ft::BST<ft::pair<int, std::string> >::pointer p = tree.getRoot();
    std::cout << "inserted: " << inserted.first->first << " "
              << inserted.first->second << std::endl;
    std::cout << "Root: " << p->item.first << " " << p->item.second
              << std::endl;
    return 0;
}
