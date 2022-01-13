#if !defined(__RANDOM_ACCESS_ITERATOR_H__)
#define __RANDOM_ACCESS_ITERATOR_H__

#include "iterator.hpp"
#include "utils.hpp"

namespace ft {

template <class T>
class random_access_iterator
    : public ft::iterator<random_access_iterator_tag, T> {
   public:
    typedef ft::iterator<ft::random_access_iterator_tag, T> iterator_type;
    typedef typename ft::iterator<ft::random_access_iterator_tag,
                                  T>::iterator_category iterator_category;
    typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type
        value_type;
    typedef typename ft::iterator<ft::random_access_iterator_tag,
                                  T>::difference_type difference_type;
    typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer
        pointer;
    typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference
        reference;

   private:
    pointer _ptr;

   public:
    random_access_iterator() : _ptr(u_nullptr) {}
    random_access_iterator(pointer p) : _ptr(p) {}
    // random_accses_iterator(iterator_type it) {}
    random_access_iterator(const random_access_iterator<T>& ra_it)
        : _ptr(ra_it._ptr) {}

    ~random_access_iterator() {}

    iterator_type base() const {}

    operator random_access_iterator<const T>() const { return _ptr; }

    random_access_iterator& operator=(const random_access_iterator& it) {
        _ptr = it._ptr;
        return *this;
    }

    random_access_iterator& operator++() {
        _ptr++;
        return *this;
    }

    random_access_iterator operator++(int) {
        random_access_iterator it = *this;
        ++(*this);
        return it;
    }

    random_access_iterator& operator--() {
        _ptr--;
        return *this;
    }

    random_access_iterator operator--(int) {
        random_access_iterator it = *this;
        --(*this);
        return it;
    }

    reference operator[](int index) { return *(_ptr + index); }

    pointer operator->() { return &(operator*()); }

    reference operator*() const { return *_ptr; }

    bool operator==(const random_access_iterator& other) {
        return _ptr == other._ptr;
    }

    bool operator!=(const random_access_iterator& other) {
        return !(*this == other);
    }

    random_access_iterator operator+(difference_type n) const {
        return random_access_iterator(_ptr + n);
    }

    random_access_iterator operator-(difference_type n) const {
        return random_access_iterator(_ptr - n);
    }

    random_access_iterator& operator+=(difference_type n) {
        _ptr += n;
        return *this;
    }

    random_access_iterator& operator-=(difference_type n) {
        _ptr -= n;
        return *this;
    }

    /*bool operator>(const random_accses_iterator& rhs) {
        return _ptr > rhs._ptr;
    }

    bool operator<(const random_accses_iterator& rhs) {
        return _ptr < rhs._ptr;
    }

    bool operator<=(const random_accses_iterator& rhs) {
        return
    }*/
};
}  // namespace ft

#endif  // __RANDOM_ACCESS_ITERATOR_H__
