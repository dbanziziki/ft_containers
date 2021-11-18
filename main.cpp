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
    ft::Vector<std::string> p;
    ft::Vector<std::string> v;

    v.push_back("One");
    p.push_back("Nate");
    p.push_back("Patie");
    p.push_back("Jean");
    p.push_back("Jeanine");
    p.resize(2);
    p.push_back("Donie");
    p.push_back("Donie");
    p.push_back("Donie");
    p.resize(6, "end val");
    p.push_back("another one");
    p.assign(3, "Banana");
    p.push_back("Tonie");
    p.push_back("Tonie");
    p.push_back("Tonie");
    p.push_back("Tonie");
    p.push_back("Tonie");
    p.push_back("Tonie");
    p.push_back("Tonie");

    std::cout << "[ ft::vector<std::string> p ]" << std::endl;
    print_vector(p);
    std::cout << "[ ft::vector<std::string> v ]" << std::endl;
    print_vector(v);

    p.swap(v);
    std::cout << "[ after swap ]" << std::endl;
    std::cout << "[ ft::vector<std::string> p ]" << std::endl;
    print_vector(p);
    std::cout << "[ ft::vector<std::string> v ]" << std::endl;
    print_vector(v);
    return 0;
}
