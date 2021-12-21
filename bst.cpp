#include "bst.hpp"

#include <iostream>
#include <map>

typedef ft::BST<ft::pair<int, std::string>>::pointer pointer;
typedef std::map<int, std::string>::iterator iterator;
typedef ft::BST<ft::pair<int, std::string>>::iterator ft_iterator;

int main(int argc, char const *argv[]) {
    ft::pair<int, std::string> p = ft::make_pair(1, "a");
    ft::BST<ft::pair<int, std::string>> a;

    pointer head = NULL;
    head = a.insert(head, p);
    head = a.insert(head, ft::make_pair(2, "b"));
    head = a.insert(head, ft::make_pair(3, "c"));
    a.inorder(head);
    ft_iterator ft_begin = a.begin();

    std::cout << "iterator value: " << ft_begin->second << std::endl;

    std::map<int, std::string> m;

    m.insert(std::make_pair(1, "a"));
    m.insert(std::make_pair(2, "b"));
    m.insert(std::make_pair(3, "c"));
    iterator begin = m.begin();
    std::cout << begin->first << " " << begin->second << std::endl;
    return 0;
}
