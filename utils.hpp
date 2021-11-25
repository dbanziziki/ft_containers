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

template <class InputIterator1, class InputIterator2>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                             InputIterator2 first2, InputIterator2 last2) {
    while (first1 != last1) {
        if (first2 == last2 || *first2 < *first1)
            return false;
        else if (*first1 < *first2)
            return true;
        ++first1;
        ++first2;
    }
    return (first2 != last2);
}

template <class InputIterator1, class InputIterator2, class Compare>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                             InputIterator2 first2, InputIterator2 last2,
                             Compare comp) {}
}  // namespace ft

#endif  // __UTILS_H__
