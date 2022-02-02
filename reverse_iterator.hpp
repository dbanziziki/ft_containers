#if !defined(__REVERSE_ITERATOR_H__)
#define __REVERSE_ITERATOR_H__

#include "iterator.hpp"

namespace ft {
template <class Iterator>
class reverse_iterator {
   public:
    typedef Iterator iterator_type;
    typedef typename ft::iterator_traits<Iterator>::iterator_category
        iterator_category;
    typedef typename ft::iterator_traits<Iterator>::value_type value_type;
    typedef
        typename ft::iterator_traits<Iterator>::difference_type difference_type;
    typedef typename ft::iterator_traits<Iterator>::pointer pointer;
    typedef typename ft::iterator_traits<Iterator>::reference reference;

   private:
    iterator_type _current;

   public:
    reverse_iterator() : _current() {}

    explicit reverse_iterator(iterator_type it) : _current(it) {}

    template <class Iter>
    reverse_iterator(const reverse_iterator<Iter>& rev_it)
        : _current(rev_it.base()) {}

    iterator_type base() const { return _current; }

    reference operator[](difference_type n) const { return base()[-1 - n]; }

    reverse_iterator& operator++() {
        _current--;
        return *this;
    }
    reverse_iterator operator++(int) {
        reverse_iterator temp = *this;
        --_current;
        return temp;
    }

    reverse_iterator& operator--() {
        _current++;
        return *this;
    }
    reverse_iterator operator--(int) {
        reverse_iterator temp = *this;
        ++_current;
        return temp;
    }

    reverse_iterator operator+(difference_type n) const {
        return reverse_iterator(_current - n);
    }

    reverse_iterator operator-(difference_type n) const {
        return reverse_iterator(_current + n);
    }

    reverse_iterator operator-=(difference_type n) {
        _current += n;
        return *this;
    }

    reverse_iterator operator+=(difference_type n) {
        _current -= n;
        return *this;
    }

    reference operator*() const {
        iterator_type temp = _current;
        --temp;
        return *temp;
    }

    pointer operator->() const { return &(operator*()); }
};

template <class Iterator>
reverse_iterator<Iterator> operator+(
    typename reverse_iterator<Iterator>::difference_type n,
    const reverse_iterator<Iterator>& rev_it) {
    return rev_it + n;
}

template <class Iterator1, class Iterator2>
typename reverse_iterator<Iterator1>::difference_type operator-(
    const reverse_iterator<Iterator1>& lhs,
    const reverse_iterator<Iterator2>& rhs) {
    return (rhs.base() - lhs.base());
}

/*relational operators*/

template <class Iterator1, class Iterator2>
bool operator!=(const reverse_iterator<Iterator1>& lhs,
                const reverse_iterator<Iterator2>& rhs) {
    return (lhs.base() != rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator==(const reverse_iterator<Iterator1>& lhs,
                const reverse_iterator<Iterator2>& rhs) {
    return (lhs.base() == rhs.base());
}

template <class Iterator1, class Iterator2>
bool operator<(const reverse_iterator<Iterator1>& lhs,
               const reverse_iterator<Iterator2>& rhs) {
    return lhs.base() > rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator<=(const reverse_iterator<Iterator1>& lhs,
                const reverse_iterator<Iterator2>& rhs) {
    return lhs.base() >= rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator>(const reverse_iterator<Iterator1>& lhs,
               const reverse_iterator<Iterator2>& rhs) {
    return lhs.base() < rhs.base();
}

template <class Iterator1, class Iterator2>
bool operator>=(const reverse_iterator<Iterator1>& lhs,
                const reverse_iterator<Iterator2>& rhs) {
    return lhs.base() <= rhs.base();
}

}  // namespace ft

#endif  // __REVERSE_ITERATOR_H__
