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
    typedef typename ft::map_iterator<node_type> iterator;

    BST(const node_allocator_type& node_alloc = node_allocator_type())
        : _root(NULL), _tail(NULL), _node_alloc(node_alloc) {}
    ~BST() {
        _node_alloc.destroy(_root);
        _node_alloc.deallocate(_root, 1);
    }

   private:

   public:
    ft::pair<iterator, bool> insert(const value_type& value) {
        pointer newNode = _node_alloc.allocate(1);
        _node_alloc.construct(newNode, ft::make_pair(value.first, value.second));
        if (_root == NULL) {
            _root = newNode;
            return ft::make_pair(iterator(_root), true);
        }
        pointer x = _root;
        pointer y = NULL;

        while (x != NULL) {
            y = x;
            if (value.first < x->item.first) {
                x = x->left;
            } else if (value.first == x->item.first) {
                return ft::make_pair(iterator(x), false);
            }
            else {
                x = x->right;
            }
        }

        if (value.first < y->item.first) {
            y->left = newNode;
            _tail = y->left;
            return ft::make_pair(iterator(y->left), true);
        }
        else {
            y->right = newNode;
            _tail = y->right;
            return ft::make_pair(iterator(y->right), true);
        }
        return ft::make_pair(iterator(y), true);
    }

    pointer deleteNode(const value_type& value){
        if (_root == NULL) return _root;

        if (value.first < _root->item.first)
            _root->left = deleteNode(_root->left, value);
        else if (value.first > _root->item.first) 
            _root->right = deleteNode(_root->right, value);
        else {
            if (_root->left == NULL) {
                pointer temp = _root->right;
                _node_alloc.destroy(_root);
                _node_alloc.deallocate(_root, 1);
                return temp;
            }
            else if (_root->right == NULL) {
                pointer temp = _root->left;
                _node_alloc.destroy(_root);
                _node_alloc.deallocate(_root, 1);
                return temp;
            }
        }
    }

    pointer getHead() const { return _root; }
    pointer getTail() const { return _tail; }

    void inorder(pointer node) {
        if (node != NULL) {
            inorder(node->left);

            std::cout << node->item.first << " " << node->item.second
                      << std::endl;
            inorder(node->right);
        }
    }

    iterator begin() { return _root; }

    iterator end() { return _tail; }

   public:
    reference operator*() const { return *_root; }

    pointer operator->() { return &(operator*()); }

   private:
    pointer _root;
    pointer _tail;
    node_allocator_type _node_alloc;
};

}  // namespace ft

#endif  // __BST_H__
