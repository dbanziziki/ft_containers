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

    map_iterator() : _current(u_nullptr), _root(u_nullptr) {}

    map_iterator(Node* p, Node* root) : _current(p), _root(root) {}

    map_iterator(const map_iterator& x)
        : _current(x._current), _root(x._root) {}

   private:
    Node* _current;
    Node* _root;

   public:
    pointer operator->() const { return &(operator*()); }

    reference operator*() const { return _current->item; }

    map_iterator& operator=(const map_iterator& rhs) {
        _current = rhs._current;
        _root = rhs._root;
        return *this;
    }

    operator map_iterator<const T>() const {
        return map_iterator<const T>(
            reinterpret_cast<ft::node<const T>*>(_current),
            reinterpret_cast<ft::node<const T>*>(_root));
    }

    map_iterator& operator++() {
        Node* n = _current;
        if (n->right != u_nullptr) {
            _current = ft::minValueNode(n->right);
            return *this;
        }
        Node* p = n->parent;
        while (p != u_nullptr && n == p->right) {
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
        Node* node = _current;
        if (node == u_nullptr) {
            _current = _root;
            if (_current == u_nullptr)
                return *this;  // TODO: when the tree os empty
            _current = ft::maxValueNode(_root);
            return *this;
        }
        _current = _findPredecessor(_root, u_nullptr);
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

    bool operator==(const map_iterator& other) {
        return _current == other._current;
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
