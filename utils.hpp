#if !defined(__UTILS_H__)
#define __UTILS_H__

#include "iterator.hpp"

struct nullptr_t {
   public:
    template <class T>
    inline operator T*() const {
        return 0;
    }

    template <class C, class T>
    inline operator T C::*() const {
        return 0;
    }

   private:
    void operator&() const;
};

static nullptr_t u_nullptr = {};

namespace ft {

template <class T>
struct node {
    typedef T value_type;
    value_type* item;
    typedef T& reference;
    typedef T* pointer;
    bool _i;
    struct node<T>* right;
    struct node<T>* left;
    struct node<T>* parent;

    node(value_type* item) {
        this->item = item;
        right = u_nullptr;
        left = u_nullptr;
        parent = u_nullptr;
    }
};

template <typename T>
node<T>* minValueNode(node<T>* current) {
    node<T>* root = current;
    while (root && root->left != u_nullptr) root = root->left;
    return root;
}

template <typename T>
node<T>* maxValueNode(node<T>* current) {
    node<T>* root = current;
    while (root && root->right != u_nullptr) root = root->right;
    return root;
}

template <class Arg1, class Arg2, class Result>
struct binary_function {
    typedef Arg1 first_argument_type;
    typedef Arg2 second_argument_type;
    typedef Result result_type;
};

template <class T>
struct less : binary_function<T, T, bool> {
    bool operator()(const T& x, const T& y) const { return x < y; }
};

template <class T1, class T2>
class pair {
   public:
    typedef T1 first_type;
    typedef T2 second_type;

    pair() : first(), second() {}

    template <class U, class V>
    pair(const pair<U, V>& pr) : first(pr.first), second(pr.second) {}

    pair(const first_type& a, const second_type& b) : first(a), second(b) {}

    pair& operator=(const pair& pr) {
        if (this != &pr) {
            first = pr.first;
            second = pr.second;
        }
        return *this;
    }

   public:
    first_type first;
    second_type second;
};

template <class T1, class T2>
pair<T1, T2> make_pair(T1 x, T2 y) {
    return (pair<T1, T2>(x, y));
}

/*
    pair relational operators
*/

template <class T1, class T2>
bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
    return lhs.first == rhs.first && lhs.second == rhs.second;
}

template <class T1, class T2>
bool operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
    return !(lhs == rhs);
}

template <class T1, class T2>
bool operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
    return lhs.first < rhs.first ||
           (!(rhs.first < lhs.first) && lhs.second < rhs.second);
}

template <class T1, class T2>
bool operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
    return !(rhs < lhs);
}

template <class T1, class T2>
bool operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
    return rhs < lhs;
}

template <class T1, class T2>
bool operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
    return !(lhs < rhs);
}

template <class InputIterator>
typename ft::iterator_traits<InputIterator>::difference_type difference(
    InputIterator first, InputIterator last) {
    typedef typename ft::iterator_traits<InputIterator>::difference_type
        difference_type;
    difference_type diff = 0;
    for (; first != last; ++first) {
        diff++;
    }
    return diff;
}

struct false_type {
    static const bool value = false;
};

struct true_type {
    static const bool value = true;
};

template <bool B, class T = void>
struct enable_if;

template <class T>
struct enable_if<true, T> {
    typedef T type;
};

template <class T>
struct is_integral : public false_type {};

template <>
struct is_integral<bool> : public true_type {};

template <>
struct is_integral<char> : public true_type {};

// template <>
// struct is_integral<char16_t> : public true_type {};

// template <>
// struct is_integral<char32_t> : public true_type {};

template <>
struct is_integral<wchar_t> : public true_type {};

template <>
struct is_integral<short> : public true_type {};

template <>
struct is_integral<int> : public true_type {};

template <>
struct is_integral<long int> : public true_type {};

template <>
struct is_integral<long long int> : public true_type {};

template <>
struct is_integral<unsigned char> : public true_type {};

template <>
struct is_integral<unsigned short int> : public true_type {};

template <>
struct is_integral<unsigned long int> : public true_type {};

template <>
struct is_integral<unsigned long long int> : public true_type {};

}  // namespace ft

#endif  // __UTILS_H__
