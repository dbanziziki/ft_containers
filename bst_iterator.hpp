#if !defined(__BAST_ITERATOR_H__)
#define __BAST_ITERATOR_H__

#include "utils.hpp"

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

    map_iterator() : _current(NULL), _root(NULL) {}

    map_iterator(pointer p, pointer last) : _current(p), _root(last) {}

   private:
    pointer _current;
    pointer _root;

   public:
    pair_pointer operator->() { return &(operator*()); }
    pair_reference operator*() const { return _current->item; }
    map_iterator& operator++() {
        pointer n = _current;

        if (n->right != NULL) {
            _current = ft::minValueNode(n->right);
            return *this;
        }
        pointer p = n->parent;
        while (p != NULL && n == p->right) {
            n = p;
            p = p->parent;
        }
        _current = p;
        return *this;
    }

    map_iterator operator++(int) {
        map_iterator temp = *this;
        ++(*this);
        return temp;
    }

    map_iterator& operator--() {
        pointer node = _current;
        if (node == NULL) {
            _current = _root;
            if (_current == NULL) return *this;  // TODO: when the tree os empty
            _current = ft::maxValueNode(_root);
            return *this;
        }
        _current = _findPredecessor(_root, NULL);
        return *this;
    }

    map_iterator operator--(int) {
        map_iterator temp = *this;
        --(*this);
        return temp;
    }

    bool operator!=(const map_iterator& other) {
        return _current != other._current;
    }

    pointer getPointer() const { return _current; }

   private:
    pointer _findPredecessor(pointer node, pointer prec) {
        if (node == NULL) {
            return prec;
        }
        if (node->item.first == _current->item.first) {
            if (node->left != NULL) return ft::maxValueNode(node->left);
        } else if (_current->item.first < node->item.first) {
            return _findPredecessor(node->left, prec);
        } else {
            prec = node;
            return _findPredecessor(node->right, prec);
        }
        return prec;
    }
};

}  // namespace ft

#endif  // __BAST_ITERATOR_H__
