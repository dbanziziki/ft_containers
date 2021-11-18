#if !defined(__RANDOM_ACCESS_ITERATOR_H__)
#define __RANDOM_ACCESS_ITERATOR_H__

#include "iterator.hpp"

namespace ft {

template <class T>
class random_accses_iterator
    : public ft::Iterator<random_access_iterator_tag, T> {
    typedef ft::Iterator<ft::random_access_iterator_tag, T> iterator_type;
    typedef typename ft::iterator_traits<
        ft::Iterator<ft::random_access_iterator_tag, T> >::iterator_category
        iterator_category;
    typedef typename ft::iterator_traits<
        ft::Iterator<ft::random_access_iterator_tag, T> >::value_type
        value_type;
    typedef typename ft::iterator_traits<
        ft::Iterator<ft::random_access_iterator_tag, T> >::diffrence_type
        diffrence_type;
    typedef typename ft::iterator_traits<
        ft::Iterator<ft::random_access_iterator_tag, T> >::pointer pointer;
    typedef typename ft::iterator_traits<
        ft::Iterator<ft::random_access_iterator_tag, T> >::reference reference;

   private:
    pointer _ptr;

    random_accses_iterator() : _ptr(nullptr) {}
    random_accses_iterator(iterator_type it) {}
    random_accses_iterator(const random_accses_iterator<T>& ra_it)
        : _ptr(ra_it._ptr) {}

    random_accses_iterator& operator++() {
        _ptr++;
        return *this;
    }

    random_accses_iterator& operator++(int) {
        random_accses_iterator it = *this;
        ++(*this);
        return it;
    }
    random_accses_iterator& operator--() {
        _ptr--;
        return *this;
    }

    random_accses_iterator& operator--(int) {
        random_accses_iterator it = *this;
        --(*this);
        return it;
    }

    reference operator[](int index) { return _ptr[index]; }
    pointer operator->() { return _ptr; }
    pointer operator*() { return *_ptr; }
    bool operator==(const random_accses_iterator& other) {
        return _ptr == other._ptr;
    }

    bool operator!=(const random_accses_iterator& other) {
        return !(*this == other);
    }
};
}  // namespace ft

#endif  // __RANDOM_ACCESS_ITERATOR_H__
