#if !defined(__UTILS_H__)
#define __UTILS_H__

#include "iterator.hpp"

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

template <bool B, class T = void>
struct enable_if;

template <class T>
struct enable_if<true, T> {
    typedef T type;
};

}  // namespace ft

#endif  // __UTILS_H__
