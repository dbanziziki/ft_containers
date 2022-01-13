#if !defined(__BAST_ITERATOR_H__)
#define __BAST_ITERATOR_H__

#include "utils.hpp"

namespace ft {
template <class T>
class map_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T> {
   public:
    typedef ft::node<T> Node;
    typedef ft::iterator<ft::bidirectional_iterator_tag, T> iterator_type;
    typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type
        value_type;
    typedef typename ft::iterator<ft::bidirectional_iterator_tag,
                                  T>::iterator_category iterator_category;
    typedef typename ft::iterator<ft::bidirectional_iterator_tag,
                                  T>::difference_type difference_type;
    typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer
        pointer;

    typedef
        typename ft::iterator<ft::bidirectional_iterator_tag, const T>::pointer
            const_pointer;
    typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference
        reference;
    typedef typename ft::iterator<ft::bidirectional_iterator_tag,
                                  const T>::reference const_reference;

    map_iterator() : _current(u_nullptr) {}

    map_iterator(Node* p) : _current(p) {}

    map_iterator(const map_iterator& x) : _current(x._current) {}

   private:
    Node* _current;

   public:
    pointer operator->() const { return &(operator*()); }

    reference operator*() const { return _current->item; }

    map_iterator& operator=(const map_iterator& other) {
        _current = other._current;
        return *this;
    }

    operator map_iterator<const T>() const {
        return map_iterator<const T>(_current);
    }

    map_iterator& operator++() {
        Node* node = _current;

        if (node->right) {
            _current = ft::minValueNode(node->right);
            return *this;
        }
        while (node->parent) {
            if (node->parent->left == node) {
                _current = node->parent;
                return *this;
            }
            node = node->parent;
        }
        _current = node;
        return *this;
    }

    map_iterator operator++(int) {
        map_iterator temp = *this;
        ++(*this);
        return temp;
    }

    map_iterator& operator--() {
        Node* node = _current;

        if (node->left) {
            _current = ft::maxValueNode(node->left);
            return *this;
        }
        while (node->parent) {
            if (node->parent->right == node) {
                _current = node->parent;
                return *this;
            }
            node = node->parent;
        }
        _current = node;
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

    Node* base() const { return _current; }

   private:
    Node* _findPredecessor(Node* node, Node* prec) {
        if (node == u_nullptr) {
            return prec;
        }
        if (node->item.first == _current->item.first) {
            if (node->left != u_nullptr) return ft::maxValueNode(node->left);
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
