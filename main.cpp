#include <iostream>
#include <vector>

#include "random_access_iterator.hpp"
#include "vector.hpp"

template <typename T>
void print_vector(ft::Vector<T> &v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << std::endl;
    }
}

int main() {
    ft::Vector<std::string> p;
    // ft::Vector<std::string> v;

    p.push_back("Jhon");
    p.push_back("Kori");
    ft::Vector<std::string>::reverse_iterator r_it = p.rbegin();
    ft::Vector<std::string>::reverse_iterator r_end = p.rend();
    for (r_it = p.rbegin() ; r_it != p.rend(); ++r_it) {
        std::cout << *r_it << std::endl;
    }

    /*v1.push_back(1);
    v1.push_back(5);
    v1.push_back(2);
    ft::Vector<int> ftv(v1.begin(), v1.end());

    ftv.push_back(9);
    ft::random_accses_iterator<int> it = ftv.begin();
    ft::random_accses_iterator<int> end = ftv.end();
    ft::random_accses_iterator<int> p_it = it + 2;
    ft::random_accses_iterator<int> m_it = p_it - 1;

    std::cout << *p_it << std::endl;
    std::cout << *m_it << std::endl;
    for (; it != end; ++it) {
        std::cout << "The values is " << *it << std::endl;
    } */
    // print_vector(ftv);
    // v.push_back("One");
    // p.push_back("Nate");
    // p.push_back("Patie");
    // p.push_back("Jean");
    // p.push_back("Jeanine");
    // p.resize(2);
    // p.push_back("Donie");
    // p.push_back("Donie");
    // p.push_back("Donie");
    // p.resize(6, "end val");
    // p.push_back("another one");
    // p.assign(3, "Banana");
    // p.push_back("Tonie");
    // p.push_back("Tonie");
    // p.push_back("Tonie");
    // p.push_back("Tonie");
    // p.push_back("Tonie");
    // p.push_back("Tonie");
    // p.push_back("Tonie");

    // std::cout << "[ ft::vector<std::string> p ]" << std::endl;
    // print_vector(p);
    // std::cout << "[ ft::vector<std::string> v ]" << std::endl;
    // print_vector(v);

    // p.swap(v);
    // std::cout << "[ after swap ]" << std::endl;
    // std::cout << "[ ft::vector<std::string> p ]" << std::endl;
    // print_vector(p);
    // std::cout << "[ ft::vector<std::string> v ]" << std::endl;
    // print_vector(v);
    return 0;
}
