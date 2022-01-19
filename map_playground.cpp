// #include "bst.hpp"
#include <iostream>
#include <map>

// #include "vector.hpp"
#if 1
#define TAG "ft"
#include "map.hpp"
#else
#include <map>
#define TAG "std"
namespace ft = std;
#endif

typedef ft::map<int, std::string>::iterator iterator;
typedef ft::map<int, std::string>::const_iterator const_iterator;
typedef ft::map<int, std::string>::reverse_iterator reverse_iterator;
typedef ft::map<int, std::string>::const_reverse_iterator const_reverse_iterator;


void inorder(ft::node<ft::pair<int, std::string> > *node) {
    if (node != u_nullptr) {
        inorder(node->left);

        std::cout << node->item.first << " " << node->item.second << std::endl;
        inorder(node->right);
    }
}

int main() {
    ft::map<int, std::string> m;

    m.insert(ft::make_pair(21, "Savage"));
    m.insert(ft::make_pair(12, "Manga"));
    m.insert(ft::make_pair(2, "Manga"));
    m.insert(ft::make_pair(42, "school"));

    reverse_iterator rit = m.rbegin(); 
    reverse_iterator rit1;
    rit1  = rit;
    for (; rit != m.rend(); ++rit) {
        std::cout << rit->first << " " << rit->second << std::endl;
    }
    return 0;
}
