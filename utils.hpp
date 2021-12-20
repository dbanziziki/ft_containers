#if !defined(__UTILS_H__)
#define __UTILS_H__

#include "iterator.hpp"
#include <uchar.h>

namespace ft {

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

template <>
struct is_integral<char16_t> : public true_type {};

template <>
struct is_integral<char32_t> : public true_type {};

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

//template <>
//struct is_integral<unsigned short int> : public true_type {};

template <>
struct is_integral<unsigned long int> : public true_type {};

template <>
struct is_integral<unsigned long long int> : public true_type {};

}  // namespace ft

#endif  // __UTILS_H__
