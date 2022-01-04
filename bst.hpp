#include <cstddef>
#if !defined(__BST_H__)
#define __BST_H__

#include "bst_iterator.hpp"
#include "utils.hpp"

namespace ft {
template <class T, class Compare = ft::less<T>, class Node = ft::node<T>,
          class Node_alloc = std::allocator<Node> >
class BST {
   public:
    typedef T value_type;
    typedef typename value_type::first_type key_type;
    typedef typename value_type::second_type mapped_type;
    typedef Node node_type;
    typedef Node_alloc node_allocator_type;
    typedef Compare compare_type;  // to compare the pairs
    typedef typename node_allocator_type::pointer pointer;
    typedef typename node_allocator_type::const_pointer const_pointer;
    typedef typename node_allocator_type::reference reference;
    typedef typename node_allocator_type::const_reference const_reference;
    typedef typename ft::map_iterator<node_type> iterator;

    BST(const node_allocator_type& node_alloc = node_allocator_type())
        : _root(NULL), _tail(NULL), _size(0), _node_alloc(node_alloc) {}
    ~BST() {
        _node_alloc.destroy(_root);
        _node_alloc.deallocate(_root, 1);
    }

   private:
   public:
    size_t size() const { return _size; }
    ft::pair<iterator, bool> insert(const value_type& value) {
        pointer newNode = _node_alloc.allocate(1);
        _node_alloc.construct(newNode, Node(value));
        if (_root == NULL) {
            _root = newNode;
            _tail = newNode;
            _size++;
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
            } else {
                x = x->right;
            }
        }

        if (value.first < y->item.first) {
            y->left = newNode;
            newNode->parent = y;
            _tail = y->left;
            _size++;
            return ft::make_pair(iterator(y->left), true);
        } else {
            y->right = newNode;
            newNode->parent = y;
            _size++;
            return ft::make_pair(iterator(y->right), true);
        }
        return ft::make_pair(iterator(y), true);
    }

    pointer deleteNode(pointer node, const value_type& value) {
        if (node == NULL) return node;
        if (value.first < node->item.first)
            node->left = deleteNode(node->left, value);
        else if (value.first > node->item.first)
            node->right = deleteNode(node->right, value);
        else {
            if (node->left == NULL && node->right == NULL)
                return NULL;
            else if (node->left == NULL) {
                pointer temp = node->right;
                _node_alloc.destroy(node);
                _node_alloc.deallocate(node, 1);
                return temp;
            } else if (node->right == NULL) {
                pointer temp = node->left;
                _node_alloc.destroy(node);
                _node_alloc.deallocate(node, 1);
                return temp;
            }
            pointer temp = _minValueNode(node->right);
            node->item = temp->item;
            node->right = deleteNode(node->right, temp->item);
        }
        return node;
    }

    pointer findKey(pointer node, const key_type& k) {
        if (node == NULL) {
            ft::pair<iterator, bool> inserted =
                insert(ft::make_pair(k, mapped_type()));
            return inserted.first.getPointer();
        }
        if (node->item.first == k) return node;

        if (node->item.first < k) return findKey(node->right, k);
        return findKey(node->left, k);
    }

   private:
    pointer _minValueNode(pointer node) {
        pointer current = node;
        while (current && current->left != NULL) current = current->left;
        return current;
    }

   public:
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
    size_t _size;
    compare_type _comp;
    node_allocator_type _node_alloc;
};

}  // namespace ft

#endif  // __BST_H__
