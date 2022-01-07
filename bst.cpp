#include "bst.hpp"

#include <iostream>
#include <map>

typedef ft::BST<ft::pair<std::string, int> >::pointer pointer;
typedef std::map<std::string, int>::iterator iterator;
typedef ft::BST<ft::pair<std::string, int> >::iterator ft_iterator;
typedef ft::BST<ft::pair<std::string, int> >::pointer pointer;

int main() {
    ft::pair<std::string, int> p = ft::make_pair("b", 78);
    ft::BST<ft::pair<std::string, int> > a;
    // what if we delete the root node that has 2 children: it goes into case n 3
    // head is b 78
    // tail is a 2
    // right child is NULL
    // left child is a 2
    // [b, 78]
    //  -    -
   //-         -
//[a, 2]     [c, 19]
    ft::pair<ft_iterator, bool> res = a.insert(p);
    res = a.insert(ft::make_pair("a", 2));
    res = a.insert(ft::make_pair("c", 19));
    // a.inorder(a.getHead());
    a.deleteNode(a.getHead(), "b");
    ft_iterator begin = a.begin();
    std::cout << "Tail node: " << begin->first << " " << begin->second << std::endl;
    pointer root = a.getHead();
    std::cout << "Head node: " << root->item.first << " " << root->item.second << std::endl;
    return 0;
}
