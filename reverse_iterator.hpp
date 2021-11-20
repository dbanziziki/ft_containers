#if !defined(__REVERSE_ITERATOR_H__)
#define __REVERSE_ITERATOR_H__

#include "iterator.hpp"

namespace ft
{
template <class Iterator>
class reverse_iterator {
    public:
        typedef Iterator iterator_type;
        typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
        typedef typename ft::iterator_traits<Iterator>::value_type        value_type;
        typedef typename ft::iterator_traits<Iterator>::difference_type   difference_type;
        typedef typename ft::iterator_traits<Iterator>::pointer pointer;
        typedef typename ft::iterator_traits<Iterator>::reference reference;
    
    private:
    
    public:
        iterator_type _current;
        reverse_iterator() : _current() {}

        explicit reverse_iterator(iterator_type it) : _current(it) {}

        template<class Iter>
        reverse_iterator(const reverse_iterator<Iter>& rev_it) : _current(rev_it.base()) {}

        iterator_type base() const { return _current; }

        reference operator*() const {
            iterator_type temp = _current;
            return *(--temp);
        }

        reverse_iterator &operator++() {
            _current--;
            return *this;
        }
        reverse_iterator operator++(int) {
            reverse_iterator temp = *this;
            --_current;
            return temp;
        }
        
        reverse_iterator &operator--() {
            _current++;
            return *this;
        }
        reverse_iterator operator--(int) {
            reverse_iterator temp = *this;
            --_current;
            return temp;
        }
};

template <class Iterator>
bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
    return (lhs.base() != rhs.base());
}

template <class Iterator>
bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
    return (lhs.base() == rhs.base());
}

    
} // namespace ft



#endif  // __REVERSE_ITERATOR_H__
