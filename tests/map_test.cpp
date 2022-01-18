#include "map.hpp"

#include <criterion/criterion.h>

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "test_utils.hpp"

typedef ft::map<int, std::string>::reverse_iterator reverse_iterator;
typedef ft::map<int, std::string>::iterator iterator;
typedef ft::map<int, std::string> ft_map;
typedef std::map<int, std::string> std_map;

std::vector<ft::pair<int, std::string> > v;
ft_map dummy;

void setup(void) {
    v.push_back(ft::make_pair(19, "School"));
    v.push_back(ft::make_pair(42, "Network"));
}

void setup_dummy(void) {
    dummy[41] = "Hello";
    dummy[42] = "world!";
}

Test(constructor, default_constructor) {
    ft_map m;

    cr_assert(m.size() == 0);
}

Test(constructor, range_constructor, .init = setup) {
    ft_map m(v.begin(), v.end());

    cr_assert(m.size() == v.size());
}

Test(constructor, copy_constructor, .init = setup_dummy) {
    ft_map m(dummy);

    cr_assert(m.size() == dummy.size());
}

Test(Operators, assign_operator, .init = setup_dummy) {
    ft_map m;

    m[4] = "Hello";
    m = dummy;

    cr_assert(m.size() == dummy.size());
}
