#include <iostream>
#include <vector>

typedef std::vector<int>::iterator iterator;

template <typename T>
void print_vec(std::vector<T> v) {
    iterator first = v.begin();
    iterator last = v.end();
    for (; first != last; ++first) {
        std::cout << *first << std::endl;
    }
}

int main(int argc, char const *argv[]) {
    std::vector<int> v;
    for (int i = 0; i < 5; i++) {
        v.push_back(i + 1);
    }
    std::cout << "before insert" << v.size() << std::endl;
    print_vec(v);
    std::cout << "---------" << std::endl;
    v.insert(v.begin(), 42);
    std::cout << "after insert" << v.size() << std::endl;
    print_vec(v);
    return 0;
}