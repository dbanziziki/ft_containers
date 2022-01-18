#if 0
#include <map>
#include <vector>
namespace ft = std;
#else
#include "map.hpp"
#include "vector.hpp"
#endif

#include <iostream>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer {
    int idx;
    char buff[BUFFER_SIZE];
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

int main() {
    ft::map<int, int> m;
    std::srand(789);

    std::cout << "Inserting: " << COUNT << " values" << std::endl;
    for (int i = 0; i < COUNT; ++i) {
        m.insert(ft::make_pair(std::rand(), std::rand()));
    }
    return 0;
}