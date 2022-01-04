#if !defined(__BAST_ITERATOR_H__)
#define __BAST_ITERATOR_H__

#include "iterator.hpp"

namespace ft {
template <class T>
class map_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T> {
   public:
    typedef ft::iterator<ft::bidirectional_iterator_tag, T> iterator_type;
    typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type
        value_type;
    typedef typename value_type::value_type pair_type;
    typedef pair_type* pair_pointer;
    typedef pair_type& pair_reference;
    typedef typename ft::iterator<ft::bidirectional_iterator_tag,
                                  T>::iterator_category iterator_category;
    typedef typename ft::iterator<ft::bidirectional_iterator_tag,
                                  T>::difference_type difference_type;
    typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer
        pointer;
    typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference
        reference;

    map_iterator() : _current(NULL) {}

    map_iterator(pointer p) : _current(p) {}

   private:
    pointer _current;

   public:
    pair_pointer operator->() { return &(operator*()); }
    pair_reference operator*() const { return _current->item; }

    map_iterator& operator++() {
        pointer temp = _current;
    }
};

}  // namespace ft

#endif  // __BAST_ITERATOR_H__
