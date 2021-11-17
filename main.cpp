#include <iostream>
#include <vector>

#include "vector.hpp"

template <typename T>
void print_vector(ft::Vector<T> &v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << std::endl;
    }
}

int main(int argc, char const *argv[]) {
    /* code */

    ft::Vector<std::string> p(7, "ben");

    p.push_back("Tonere");
    print_vector(p);
    int n = 9;
    return 0;
}
