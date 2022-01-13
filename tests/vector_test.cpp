#include "vector.hpp"

#include <criterion/criterion.h>

#include <string>
#include <vector>
typedef std::vector<int>::iterator std_it;
typedef ft::vector<int>::iterator it;

std::vector<int> vec;
ft::vector<int> dummy;

void setup_ft_random(void) {
    std::srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        dummy.push_back(std::rand() % 100);
    }
}

void setup_ft_seed(void) {
    for (int i = 0; i < 5; i++) {
        dummy.push_back(i);
    }
}

void setup_std(void) {
    std::srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        vec.push_back(std::rand() % 100);
    }
}

Test(constructor, default_constructor) {
    ft::vector<int> v;

    cr_assert(v.size() == 0);
}

Test(constructor, fill_constructor) {
    ft::vector<int> v(9, 42);

    cr_assert(v.size() == 9);
    for (int i = 0; i < v.size(); i++) {
        cr_assert(v[i] == 42);
    }
}

Test(constructor, range_constructor, .init = setup_std) {
    ft::vector<int> v(vec.begin(), vec.end());

    cr_assert(v.size() == vec.size());
    for (int i = 0; i < vec.size(); i++) {
        cr_assert(v[i] == vec[i]);
    }
}

Test(constructor, coy_constructor, .init = setup_ft_random) {
    ft::vector<int> v(dummy);

    cr_assert(v.size() == dummy.size());

    for (int i = 0; i < dummy.size(); i++) {
        cr_assert(v[i] == dummy[i]);
    }
}

Test(opertors, index_operator, .init = setup_ft_seed) {
    cr_assert(dummy[0] == 0);
    cr_assert(dummy[1] == 1);
    cr_assert(dummy[2] == 2);
    cr_assert(dummy[3] == 3);
    cr_assert(dummy[4] == 4);
}

Test(operators, assign_operator, .init = setup_ft_seed) {
    ft::vector<int> v;

    v = dummy;

    cr_assert(v.size() == dummy.size());
    for (int i = 0; i < dummy.size(); i++) {
        std::cout << "assigned: " << v[i] << "\n";
        std::cout << "base: " << dummy[i] << "\n";
        // cr_assert(v[i] == dummy[i]);
    }
}