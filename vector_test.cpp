#include "vector.hpp"

#include <vector>

void test_copy_constructor() {
    std::cout << "Testing vector(const vector &x)" << std::endl;
    ft::vector<int> ft_vec;

    for (int i = 0; i < 5; i++) {
        int value = std::rand() % 100;
        ft_vec.push_back(value);
    }
    ft::vector<int> ft_copy(ft_vec);
    assert(ft_vec.size() == ft_copy.size());
    assert(ft_vec.capacity() == ft_copy.capacity());
    for (size_t i = 0; i < ft_vec.size(); i++) {
        assert(ft_vec[i] == ft_copy[i]);
    }
    std::cout << "[OK]" << std::endl;
}

void test_fill_constructor() {
    std::cout << "Testing explicit vector(size_type n, const value_type &val = "
                 "value_type(), const allocator_type &alloc = allocator_type())"
              << std::endl;
    ft::vector<std::string> ft_vec(5, "19");
    std::vector<std::string> std_vec(5, "19");
    assert(ft_vec.size() == std_vec.size());
    assert(ft_vec.capacity() == std_vec.capacity());
    for (size_t i = 0; i < ft_vec.size(); i++) {
        assert(ft_vec[i] == std_vec[i]);
    }
    std::cout << "[OK]" << std::endl;
}

void test_range_constructor() {
    typedef std::vector<int>::iterator iterator;
    std::cout << "Testing vector(InputIterator first, InputIterator last, "
                 "const allocator_type &alloc = allocator_type())"
              << std::endl;
    std::vector<int> std_vec;
    for (int i = 0; i < 5; i++) {
        std_vec.push_back(std::rand() % 100);
    }
    iterator begin = std_vec.begin();
    iterator end = std_vec.end();
    ft::vector<int> ft_vec(begin, end);
    assert(ft_vec.size() == std_vec.size());
    for (size_t i = 0; i < std_vec.size(); i++) {
        assert(ft_vec[i] == std_vec[i]);
    }
    std::cout << "[OK]" << std::endl;
}

void test_resize() {
    std::cout
        << "Testing void resize(size_type n, value_type val = value_type())"
        << std::endl;
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    for (int i = 0; i < 5; i++) {
        int value = std::rand() % 100;
        ft_vec.push_back(value);
        std_vec.push_back(value);
    }
    assert(ft_vec.size() == std_vec.size());
    ft_vec.resize(3);
    std_vec.resize(3);
    assert(ft_vec.size() == std_vec.size());
    for (size_t i = 0; i < std_vec.size(); i++) {
        assert(ft_vec[i] == std_vec[i]);
    }
    ft_vec.resize(10, 42);
    std_vec.resize(10, 42);
    assert(ft_vec.size() == std_vec.size());
    for (size_t i = 0; i < std_vec.size(); i++) {
        assert(ft_vec[i] == std_vec[i]);
    }
    std::cout << "[OK]" << std::endl;
}

void test_reserve() {
    std::cout << "Testing void reserve(size_type new_cap)" << std::endl;
    ft::vector<int> ft_vec;
    std::vector<int> std_vec;
    assert(ft_vec.capacity() == std_vec.capacity());
    ft_vec.reserve(5);
    std_vec.reserve(5);
    assert(ft_vec.capacity() == std_vec.capacity());
    for (size_t i = 0; i < 5; i++) {
        int value = std::rand() % 100;
        ft_vec.push_back(value);
        std_vec.push_back(value);
    }
    for (size_t i = 0; i < ft_vec.size(); i++) {
        assert(ft_vec[i] == std_vec[i]);
    }
    std::cout << "[OK]" << std::endl;
}

void test_at() {
    std::cout << "Testing reference at(size_type n)" << std::endl;
    ft::vector<int> ft_vec;

    ft_vec.push_back(49);
    ft_vec.push_back(620);
    ft_vec.push_back(19);
    ft_vec.push_back(42);
    assert(ft_vec.at(2) == 19);
    assert(ft_vec.at(0) == 49);
    assert(ft_vec.at(1) != 49);
    std::cout << "[OK]" << std::endl;
}

void test_front() {
    std::cout << "Testing reference front()" << std::endl;
    ft::vector<int> ft_vec;
    std::vector<int> std_vec;
    for (int i = 0; i < 5; i++) {
        int value = std::rand() % 100;
        ft_vec.push_back(value);
        std_vec.push_back(value);
    }
    assert(ft_vec.front() == std_vec.front());
    std::cout << "[OK]" << std::endl;
}

void test_back() {
    std::cout << "Testing reference back()" << std::endl;
    ft::vector<int> ft_vec;
    std::vector<int> std_vec;
    for (int i = 0; i < 5; i++) {
        int value = std::rand() % 100;
        ft_vec.push_back(value);
        std_vec.push_back(value);
    }
    assert(ft_vec.back() == std_vec.back());
    std::cout << "[OK]" << std::endl;
}

void test_assign() {
    std::cout << "Testing void assign(size_type n, const value_type &val)"
              << std::endl;
    ft::vector<int> ft_vec;
    std::vector<int> std_vec;
    ft_vec.assign(5, 42);
    std_vec.assign(5, 42);
    assert(ft_vec.size() == std_vec.size());
    assert(ft_vec.capacity() == std_vec.capacity());
    for (size_t i = 0; i < ft_vec.size(); i++) {
        assert(ft_vec[i] == std_vec[i]);
    }
    std::cout << "[OK]" << std::endl;
    std::cout << "Testing void assign(InputIterator first, InputIterator last)"
              << std::endl;
    typedef std::vector<int>::iterator iterator;

    ft::vector<int> ft_vec1;
    iterator begin = std_vec.begin();
    iterator end = std_vec.end();
    ft_vec1.assign(begin, end);
    assert(ft_vec1.size() == std_vec.size());
    for (size_t i = 0; i < std_vec.size(); i++) {
        assert(ft_vec1[i] == std_vec[i]);
    }
    std::cout << "[OK]" << std::endl;
}

void test_push_back() {
    std::cout << "Testing void push_back(const value_type &val)" << std::endl;

    ft::vector<int> ft_vec;
    ft_vec.push_back(4);
    assert(ft_vec[0] == 4);
    assert(ft_vec.size() == 1);
    for (int i = 1; i <= 5; i++) {
        int value = std::rand() % 100;
        ft_vec.push_back(value);
        assert(ft_vec[i] == value);
    }
    assert(ft_vec.size() == 6);
    std::cout << "[OK]" << std::endl;
}

void test_pop_back() {
    std::cout << "Testing void pop_back()" << std::endl;
    ft::vector<int> ft_vec;
    ft_vec.push_back(78);
    ft_vec.push_back(19);
    ft_vec.push_back(42);
    ft_vec.pop_back();
    assert(ft_vec.size() == 2);
    assert(ft_vec.back() == 19);
    ft_vec.pop_back();
    ft_vec.pop_back();
    assert(ft_vec.size() == 0);
    std::cout << "[OK]" << std::endl;
}

void test_insert() {
    std::cout
        << "Testing iterator insert(iterator position, const value_type &val)"
        << std::endl;
    ft::vector<int> ft_vec(10, 42);
    typedef ft::vector<int>::iterator iterator;
    iterator begin = ft_vec.begin();
    ft_vec.insert(begin, 19);
    std::cout << *begin << std::endl;
    assert(*begin == 19);  // TODO: broken
    std::cout << "[OK]" << std::endl;
}

int main() {
    std::srand(std::time(NULL));
    test_copy_constructor();

    test_fill_constructor();

    test_range_constructor();

    test_resize();

    test_reserve();

    test_at();

    test_front();

    test_back();

    test_assign();

    test_push_back();

    test_pop_back();

    test_insert();

    system("leaks test");
    return 0;
}
