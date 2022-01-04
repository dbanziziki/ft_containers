#include <iostream>
#include <vector>

#include "random_access_iterator.hpp"
#include "vector.hpp"

template <typename T>
void print_vector(ft::vector<T> &v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << std::endl;
    }
}

template <typename T>
void print_vector(std::vector<T> &v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << std::endl;
    }
}

int main (int argc, char *argv[])
{
  return 0;
}
