#include "bst.hpp"

#include <iostream>
#include <map>

typedef ft::BST<ft::pair<int, std::string> >::pointer pointer;
typedef std::map<int, std::string>::iterator iterator;
typedef ft::BST<ft::pair<int, std::string> >::iterator ft_iterator;
typedef ft::BST<ft::pair<int, std::string> >::pointer pointer;

int main() {
    ft::pair<int, std::string> p = ft::make_pair(78, "a");
    ft::BST<ft::pair<int, std::string> > a;

    ft::pair<ft_iterator, bool> res = a.insert(p);
    res = a.insert(ft::make_pair(2, "Bono"));
    res = a.insert(ft::make_pair(1, "Oregon lowest"));
    res = a.insert(ft::make_pair(4, "Jason"));
    res = a.insert(ft::make_pair(21, "Brandon"));

	a.inorder(a.getHead());
	ft_iterator last = a.end();
	std::cout << last->first << " " << last->second << std::endl;
    return 0;
}