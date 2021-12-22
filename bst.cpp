#include "bst.hpp"

#include <iostream>
#include <map>

typedef ft::BST<ft::pair<int, std::string>>::pointer pointer;
typedef std::map<int, std::string>::iterator iterator;
typedef ft::BST<ft::pair<int, std::string>>::iterator ft_iterator;

int main(int argc, char const *argv[]) {
    ft::pair<int, std::string> p = ft::make_pair(1, "a");
    ft::BST<ft::pair<int, std::string>> a;
    std::map<int, std::string> m;

    ft::pair<ft_iterator, bool> res = a.insert(p);
    res = a.insert(ft::make_pair(2, "b"));
    res = a.insert(ft::make_pair(4, "f"));
    // res = a.insert(ft::make_pair(1, "a"));

    pointer ptr = a.getHead();
    ft_iterator ft_begin = a.begin();
    std::cout << "Begin: " << ft_begin->first << " " << ft_begin->second
              << std::endl;
    std::cout << "Head after insert: " << ptr->item.first << " "
              << ptr->item.second << std::endl;

    std::pair<iterator, bool> s_res = m.insert(std::make_pair(1, "a"));
    s_res = m.insert(std::make_pair(5, "e"));
    s_res = m.insert(std::make_pair(1, "a"));

    std::cout << "values: " << res.first->first << " " << res.first->second
              << std::endl;
    return 0;
}
