#if !defined(__ITERATOR_H__)
#define __ITERATOR_H__

#include <cstddef>
#include <iostream>

namespace ft {

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

template <class Category, class T, class Distance = std::ptrdiff_t,
          class Pointer = T*, class Reference = T&>
struct iterator {
    typedef Category iterator_category;
    typedef T value_type;
    typedef Distance diffrence_type;
    typedef Pointer pointer;
    typedef Reference reference;
};

template <class Iter>
struct iterator_traits {
    typedef typename Iter::diffrence_type diffrence_type;
    typedef typename Iter::value_type value_type;
    typedef typename Iter::pointer pointer;
    typedef typename Iter::reference reference;
    typedef typename Iter::iterator_category iterator_category;
};

template <class T>
struct iterator_traits<T*> {
}

template <class T>
struct iterator_traits<const T*>;

}  // namespace ft

#endif  // __ITERATOR_H__
