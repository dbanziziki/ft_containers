#if !defined(__BST_H__)
#define __BST_H__

#include "bst_iterator.hpp"
#include "utils.hpp"

namespace ft {
template <class T, class Compare = ft::less<T>, class Node = ft::node<T>,
          class Type_alloc = std::allocator<T>,
          class Node_alloc = std::allocator<Node> >
class BST {
   public:
    typedef T value_type;
    typedef Node node_type;
    typedef Type_alloc value_type_allocator;
    typedef Node_alloc node_allocator_type;
    typedef Compare compare_type;  // to compare the pairs
    typedef typename node_allocator_type::pointer pointer;
    typedef typename node_allocator_type::const_pointer const_pointer;
    typedef typename node_allocator_type::reference reference;
    typedef typename node_allocator_type::const_reference const_reference;
    typedef typename ft::map_iterator<value_type> iterator;

    BST(const node_allocator_type& node_alloc = node_allocator_type())
        : _head(NULL), _tail(NULL) {}
    ~BST() {}

   private:
    pointer _insertKey(pointer node, const value_type& value) {
        if (node == NULL) {
            _head = _node_alloc.allocate(1);
            _node_alloc.construct(_head,
                                  ft::make_pair(value.first, value.second));
            _tail = _head;
            return _head;
        }
        if (value < node->item)
            node->left = _insertKey(node->left, value);
        else
            node->right = _insertKey(node->right, value);
        return node;
    }

   public:
    pointer insert(const value_type& value) {
        _head = _insertKey(_head, value);
        return _head;
    }

    void inorder(pointer node) {
        if (node != NULL) {
            inorder(node->left);

            std::cout << node->item.first << " " << node->item.second
                      << std::endl;
            inorder(node->right);
        }
    }

    iterator begin() { return &(_head->item); }

    iterator end() { return &(_tail->item); }

   public:
    reference operator*() const { return *_head; }

    pointer operator->() { return &(operator*()); }

   private:
    pointer _head;
    pointer _tail;
    node_allocator_type _node_alloc;
};

}  // namespace ft

#endif  // __BST_H__
