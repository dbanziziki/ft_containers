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
typedef ft::map<int, std::string>::const_reverse_iterator
    const_reverse_iterator;

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

int main() {
    srand(1234);
    ft::map<int, int> m;

    ft::map<int, int>::iterator it = m.begin();
    for (int i = 0; i < COUNT; ++i) {
        m.insert(ft::make_pair(rand(), rand()));
    }
    for (int i = 0; i < 1000; i++) {
        ft::map<int, int>::iterator it = m.upper_bound(rand());
        m.erase(it);
    }

    ft::map<int, int> copy(m);
    std::cout << "before: " << COUNT << " After: " << copy.size() << " "
              << m.size() << std::endl;
    ft::map<int, int>::const_iterator cit = copy.begin();
    while (it != m.end()) {
        if (*it != *cit) {
            std::cout << "MAPS ARE DIFFERENT" << std::endl;
        }
        ++it;
        cit++;
    }
}
