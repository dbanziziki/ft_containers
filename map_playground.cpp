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

typedef ft::map<int, int>::iterator iterator;
typedef ft::map<int, int>::const_iterator const_iterator;
typedef ft::map<int, int>::reverse_iterator reverse_iterator;
typedef ft::map<int, int>::const_reverse_iterator const_reverse_iterator;

void inorder(ft::node<ft::pair<int, int> > *node) {
    if (node != u_nullptr) {
        std::cout << node->item.first << " " << node->item.second << std::endl;
        inorder(node->left);
        inorder(node->right);
    }
}

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer {
    int idx;
    char buff[BUFFER_SIZE];
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

void map_test() {
    ft::map<int, int> m;

    for (int i = 0; i < COUNT; ++i) {
        m.insert(ft::make_pair(rand(), rand()));
    }

    ft::map<int, int> copy(m);

    if (copy.size() == m.size()) {
        std::cout << "size is the same " << copy.size() << " " << m.size()
                  << std::endl;
    } else {
        std::cout << "size not the same" << std::endl;
    }
    iterator it = m.begin();
    iterator cit = copy.begin();
    std::cout << "Testing is the same" << std::endl;
    while (it != m.end()) {
        if (it->first != cit->first) {
            std::cout << "Not the same" << std::endl;
            break;
        }
        it++;
        ++cit;
    }
    std::cout << "Testing reverse iterator" << std::endl;
    reverse_iterator rit = m.rbegin();
    reverse_iterator crit = copy.rbegin();
    while (rit != m.rend()) {
        if (rit->first != crit->first) {
            std::cout << "Not the same" << std::endl;
            break;
        }
        rit++;
        crit++;
    }

    ft::map<int, int> assign;
    assign = copy;
}

int main() {
    srand(1234);

    ft::map<char, int> mymap;

    mymap['a'] = 10;
    mymap['b'] = 20;
    mymap['c'] = 30;

    ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> ret;
    ret = mymap.equal_range('b');

    std::cout << "lower bound points to: ";
    std::cout << ret.first->first << " => " << ret.first->second << '\n';

    std::cout << "upper bound points to: ";
    std::cout << ret.second->first << " => " << ret.second->second << '\n';

    ft::map<char, int>::iterator it = mymap.find('b');
    std::cout << it->first << " => " << it->second << std::endl;
}
