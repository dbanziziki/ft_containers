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

int main() {
    std::srand(time(NULL));
    ft::vector<int> ft_vec;
    std::vector<int> std_vec;
    typedef ft::vector<int>::iterator iterator;
    typedef std::vector<int>::iterator std_it;

    std::cout << "Testing ft::vector void assign(InputIterator first, "
                 "InputIterator last)"
              << std::endl;
    assert(ft_vec.size() == std_vec.size());
    for (int i = 0; i < 5; i++) {
        std_vec.push_back(std::rand() % 100);
    }
    std::vector<int>::iterator first = std_vec.begin();
    std::vector<int>::iterator last = std_vec.end();
    ft_vec.assign(first, last);
    assert(ft_vec.size() == std_vec.size());
    for (int i = 0; i < 5; i++) {
        assert(ft_vec[i] == std_vec[i]);
    }
    std::cout << "[OK]" << std::endl;
    std::cout << "Testing ft::vector iterator erase(iterator position)"
              << std::endl;
    ft::vector<int>::iterator it = ft_vec.erase(ft_vec.begin());
    std_vec.erase(std_vec.begin());
    assert(ft_vec.size() == std_vec.size());
    std::cout << "[OK]" << std::endl;
    std::cout
        << "Testing ft::vector iterator erase(iterator first, iterator last)"
        << std::endl;
    iterator val = ft_vec.erase(ft_vec.begin(), ft_vec.begin() + 2);
    std_it std_val = std_vec.erase(std_vec.begin(), std_vec.begin() + 2);
    std::cout << "first element after erasing: " << *val << std::endl;
    assert(ft_vec.size() == std_vec.size());
    std::cout << "[OK]" << std::endl;
    ft::vector<int> temp;
    ft::vector<int> temp1;
    for (int i = 0; i < 5; i++) {
        int val = std::rand() % 100;
        temp.push_back(val);
        temp1.push_back(val);
    }
    assert(temp == temp1);
    std::cout << "Testing ft::vector iterator insert(iterator position, const "
                 "value_type& val)"
              << std::endl;
    for (size_t i = 0; i < 5; i++) {
        ft_vec.push_back(std::rand() % 100);
    }
    std::cout << "size: " << ft_vec.size() << " Capacity :" << ft_vec.capacity()
              << std::endl;
    print_vector(ft_vec);
    iterator it_val = ft_vec.insert(ft_vec.begin() + 6, 420);
    ft_vec.push_back(120);
    ft_vec.insert(ft_vec.end(), 19);
    std::cout << "Last element is: " << *(--ft_vec.end()) << std::endl;
    std::cout << "size: " << ft_vec.size() << " Capacity :" << ft_vec.capacity()
              << std::endl;
    std::cout << "-------" << std::endl;
    ft::vector<int> nums;
    for (int i = 0; i < 5; i++) {
        nums.push_back(i);
    }
    nums.insert(nums.begin() + 2, 5, 149);
    print_vector(nums);
    return 0;
}
