#include "map.hpp"

#include <iostream>
#include <map>

typedef ft::map<int, std::string>::reverse_iterator reverse_iterator;
typedef ft::map<int, std::string>::iterator iterator;

template <class T>
ft::node<T> *findSuccessor(ft::node<T> *node) {
    /*if (node->right == u_nullptr && node->left == u_nullptr) {
        return u_nullptr;
    }*/
    ft::node<T> *n = node;
    if (n->right != u_nullptr) {
        return ft::minValueNode(n->right);
    }
    ft::node<T> *p = n->parent;
    while (p != u_nullptr && n == p->right) {
        n = p;
        p = p->parent;
    }
    return p;
}

template <typename T, typename U>
ft::node<T> *findKey(ft::node<T> *node, const U &k) {
    if (node == u_nullptr) return u_nullptr;
    if (node->item.first == k) return node;

    if (node->item.first < k) return findKey(node->right, k);
    return findKey(node->left, k);
}

int main() {
    ft::map<int, std::string> other;

    other[19] = "School";
    other[12] = "Network";
    other[34] = "Network";
    other[41] = "Network";
    other[42] = "Network";

    iterator first = other.begin();
    iterator last = other.end();

    std::cout << "Normal iterator" << std::endl;
    for (; first != last; ++first) {
        std::cout << first->first << " => " << first->second << "\n";
    }
    std::cout << "Reverse iterator" << std::endl;
    reverse_iterator rfirst = other.rbegin();
    reverse_iterator rlast = other.rend();
    while (rfirst != rlast) {
        std::cout << rfirst->first << " => " << rfirst->second << std::endl;
        ++rfirst;
    }
    return 0;
}
