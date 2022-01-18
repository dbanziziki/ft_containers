#include "vector.hpp"

#include <criterion/criterion.h>

#include <iostream>
#include <string>
#include <vector>

typedef std::vector<int>::iterator std_it;
typedef ft::vector<int>::iterator iterator;
typedef ft::vector<int>::const_iterator const_iterator;
typedef ft::vector<int>::reverse_iterator reverse_iterator;
typedef ft::vector<int>::const_reverse_iterator const_reverse_iterator;

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

void setup_both(void) {
    for (int i = 0; i < 10; i++) {
        dummy.push_back(i);
        vec.push_back(i);
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

Test(Element_access, index_operator, .init = setup_ft_seed) {
    cr_assert(dummy[0] == 0);
    cr_assert(dummy[1] == 1);
    cr_assert(dummy[2] == 2);
    cr_assert(dummy[3] == 3);
    cr_assert(dummy[4] == 4);
}

Test(Element_access, assign_operator, .init = setup_ft_random) {
    ft::vector<int> v;

    v = dummy;

    cr_assert(v.size() == dummy.size());
    for (int i = 0; i < dummy.size(); i++) {
        cr_assert(v[i] == dummy[i]);
    }
}

Test(Element_access, at, .init = setup_ft_seed) {
    cr_assert(dummy.at(2) == dummy[2]);
    cr_expect(dummy.at(4) == 4, "Should be 4");
}

Test(Element_access, front, .init = setup_ft_seed) {
    cr_assert(dummy.front() == 0);
}

Test(Element_access, back, .init = setup_ft_seed) {
    cr_assert(dummy.back() == 4);
}

Test(Capacity, size, .init = setup_ft_random) {
    cr_assert(dummy.size() == 5);
    dummy.push_back(5);
    cr_expect(dummy.size() == 6, "size should be 6");
    dummy.push_back(5);
    dummy.push_back(5);
    cr_expect(dummy.size() == 8, "size should be 8");
    dummy.pop_back();
    cr_expect(dummy.size() == 7);
}

Test(Capacity, empty, .init = setup_ft_random) {
    cr_expect(dummy.empty() == false, "should return false");
    dummy.clear();
    cr_expect(dummy.empty() == true, "should return true");
}

Test(Capacity, resize, .init = setup_ft_random) {
    dummy.resize(3, 0);
    cr_expect(dummy.size() == 3);
    dummy.resize(10, 19);
    cr_expect(dummy.size() == 10, "size should be 10");
    for (int i = 3; i < 10; i++) {
        cr_assert(dummy[i] == 19);
    }
}

Test(Capacity, reserve, .init = setup_ft_seed) {
    ft::vector<int> v;

    v.reserve(5);
    cr_expect(v.capacity() == 5, "Capacity should be 5");
    cr_expect(v.empty() == true, "vec should be empty");
    dummy.reserve(10);
    cr_expect(dummy.capacity() == 10, "Capacity should 10");
    for (int i = 0; i < 5; i++) {
        cr_assert(dummy[i] == i);
    }
}

Test(Modifiers, assign, .init = setup_ft_random) {
    cr_assert(dummy.size() == 5);

    dummy.assign(10, 42);
    cr_expect(dummy.size() == 10, "Size should be 10");
    for (int i = 0; i < 10; i++) {
        cr_assert(dummy[i] == 42);
    }
    dummy.assign(2, 19);
    cr_expect(dummy.size() == 2, "Size should be 2");
    for (int i = 0; i < dummy.size(); i++) {
        cr_assert(dummy[i] == 19);
    }
}

Test(Modifiers, swap, .init = setup_ft_seed) {
    ft::vector<int> sw(4, 123);

    sw.swap(dummy);

    cr_assert(dummy.size() == 4);
    cr_assert(sw.size() == 5);
    for (int i = 0; i < dummy.size(); i++) {
        cr_assert(dummy[i] == 123);
    }
    for (int i = 0; i < sw.size(); ++i) {
        cr_assert(sw[i] == i);
    }
}

Test(Modifiers, push_back) {
    cr_assert(dummy.size() == 0);
    dummy.push_back(12);
    cr_assert(dummy.size() == 1);
    for (int i = 0; i < 45; i++) {
        dummy.push_back(21);
    }
    cr_expect(dummy.size() == 46, "Size should be 46");
}

Test(Modifiers, pop_back, .init = setup_ft_random) {
    cr_assert(dummy.size() == 5);
    dummy.pop_back();
    cr_assert(dummy.size() == 4);
    for (int i = 0; i < 4; i++) {
        dummy.pop_back();
    }
    cr_expect(dummy.size() == 0, "Should be empty");
}

Test(Modifiers, insert_one, .init = setup_ft_seed) {
    /* iterator insert(iterator position, const value_type &val) */
    cr_assert(dummy.size() == 5);
    iterator it = dummy.insert(dummy.begin(), 42);
    cr_expect(dummy.size() == 6, "size should be 6");
    cr_expect(*it == 42, "should be 42");
    cr_expect(dummy[0] == 42, "should be 42");
    cr_assert(dummy[1] == 0);
    it = dummy.insert(dummy.begin() + 4, 420);
    cr_expect(dummy.size() == 7, "size should be 7");
    // [42, 0, 1, 2, 3, 4, 5]
    cr_expect(*it == 420, "should be 420");
    cr_expect(dummy[4] == 420, "should be 420");
}

Test(Modifiers, insert_n_vals, .init = setup_ft_seed) {
    /* void insert(iterator position, size_type n, const value_type &val) */

    cr_assert(dummy.size() == 5);
    dummy.insert(dummy.begin(), 5, 42);
    cr_expect(dummy.size() == 10);
    for (int i = 0; i < 5; i++) {
        cr_assert(dummy[i] == 42);
    }

    dummy.insert(dummy.begin() + 2, 2, 79);
    cr_expect(dummy.size() == 12, "size should be 12");
    for (int i = 2; i < 4; i++) {
        cr_assert(dummy[i] == 79);
    }
}

Test(Modifiers, insert_range_at_pos, .init = setup_ft_seed) {
    ft::vector<int> v(4, 49);

    dummy.insert(dummy.begin(), v.begin(), v.end());
    cr_expect(dummy.size() == 9, "size should be 9");
    for (int i = 0; i < 4; i++) {
        cr_assert(dummy[i] == 49);
    }
    v.assign(4, 12);
    dummy.insert(dummy.begin() + 7, v.begin(), v.end());
    cr_expect(dummy.size() == 13);
    for (int i = 7; i < 11; i++) {
        cr_assert(dummy[i] == 12);
    }
}

Test(Modifiers, erase_one, .init = setup_ft_seed) {
    cr_assert(dummy.size() == 5);

    dummy.erase(dummy.begin());
    cr_assert(dummy.size() == 4);
    iterator it = dummy.begin();
    cr_assert(*it == 1);
    //[1, 2, 3, 4]
    dummy.erase(dummy.begin() + 2);
    cr_assert(dummy.size() == 3);
    cr_assert(dummy[0] == 1);
    cr_assert(dummy[1] == 2);
    cr_assert(dummy[2] == 4);
}

Test(Modifiers, erase_range, .init = setup_both) {
    cr_assert(dummy.size() == vec.size());
    iterator it = dummy.erase(dummy.begin() + 2, dummy.end() - 3);
    std_it sit = vec.erase(vec.begin() + 2, vec.end() - 3);
    cr_assert(*it == *sit);
    cr_assert(dummy.size() == vec.size());
    for (int i = 0; i < dummy.size(); ++i) {
        cr_assert(dummy[i] == vec[i]);
    }
    it = dummy.erase(dummy.begin() + 2, dummy.end());
    sit = vec.erase(vec.begin() + 2, vec.end());
    cr_assert(*it == *sit);
}

Test(Modifiers, clear, .init = setup_ft_random) {
    cr_assert(dummy.size() == 5);
    dummy.clear();
    cr_expect(dummy.size() == 0, "Size should be 0");
}

Test(Iterators, begin_end, .init = setup_ft_seed) {
    iterator it = dummy.begin();

    cr_assert(*it == 0);
    int i = 0;

    for (; it != dummy.end(); ++it) {
        cr_assert(*it == i);
        i++;
    }
}

Test(Iterators, const_begin_end, .init = setup_ft_seed) {
    const_iterator it = dummy.begin();

    cr_assert(*it == 0);
    int i = 0;

    for (; it != dummy.end(); ++it) {
        cr_assert(*it == i);
        i++;
    }
}

Test(Reverse_iterators, rbegin_rend, .init = setup_ft_seed) {
    reverse_iterator rit = dummy.rbegin();

    cr_assert(*rit == 4);
    int i = 4;
    for (; rit != dummy.rend(); ++rit) {
        cr_assert(*rit == i);
        i--;
    }
}

Test(Reverse_iterators, const_rbegin_rend, .init = setup_ft_seed) {
    const_reverse_iterator crit = dummy.rbegin();
    const_reverse_iterator crend = dummy.rend();
    cr_assert(*crit == 4);
    int i = 4;
    for (; crit != dummy.rend();
         ++crit) {  // Error when directly using dummy.rend()
                    // not taking the right overload?
        cr_assert(*crit == i);
        i--;
    }
}