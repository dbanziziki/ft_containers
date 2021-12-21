#if !defined(__BAST_ITERATOR_H__)
#define __BAST_ITERATOR_H__

#include "iterator.hpp"

namespace ft {
template <class T>
class map_iterator : public ft::Iterator<ft::bidirectional_iterator_tag, T> {
   public:
    typedef ft::Iterator<ft::bidirectional_iterator_tag, T> iterator_type;
    typedef typename ft::Iterator<ft::bidirectional_iterator_tag, T>::value_type
        value_type;
    typedef typename ft::Iterator<ft::bidirectional_iterator_tag,
                                  T>::iterator_category iterator_category;
    typedef typename ft::Iterator<ft::bidirectional_iterator_tag,
                                  T>::difference_type difference_type;
    typedef typename ft::Iterator<ft::bidirectional_iterator_tag, T>::pointer
        pointer;
    typedef typename ft::Iterator<ft::bidirectional_iterator_tag, T>::reference
        reference;

    map_iterator() : _current(NULL) {}

    map_iterator(pointer p) : _current(p) {}

   private:
    pointer _current;

   public:
    pointer operator->() { return &(operator*()); }
    reference operator*() const { return *(_current); }

    map_iterator &operator++() { return *this; }
};

}  // namespace ft

#endif  // __BAST_ITERATOR_H__
