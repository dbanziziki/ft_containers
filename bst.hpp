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
    typedef typename ft::map_iterator<const node_type> const_iterator;

    BST(const node_allocator_type& node_alloc = node_allocator_type())
        : _root(u_nullptr),
          _tail(u_nullptr),
          _size(0),
          _node_alloc(node_alloc) {}
    ~BST() {}

   public:
    size_t size() const { return _size; }
    ft::pair<iterator, bool> insert(const value_type& value) {
        pointer newNode = _node_alloc.allocate(1);
        _node_alloc.construct(newNode, Node(value));
        if (_root == u_nullptr) {
            _root = newNode;
            _tail = newNode;
            _size++;
            return ft::make_pair(iterator(_root, _tail), true);
        }
        pointer x = _root;
        pointer y = u_nullptr;

        while (x != u_nullptr) {
            y = x;
            if (value.first < x->item.first) {
                x = x->left;
            } else if (value.first == x->item.first) {
                return ft::make_pair(iterator(x, _tail), false);
            } else {
                x = x->right;
            }
        }

        if (value.first < y->item.first) {
            if (value.first < _tail->item.first) _tail = newNode;
            y->left = newNode;
            newNode->parent = y;
            _size++;
            return ft::make_pair(iterator(newNode, _tail), true);
        } else {
            y->right = newNode;
            newNode->parent = y;
            _size++;
            return ft::make_pair(iterator(newNode, _tail), true);
        }
        return ft::make_pair(iterator(newNode, _tail), true);
    }

    pointer deleteNode(pointer node, const key_type& value) {
        if (node == u_nullptr) return node;
        if (value < node->item.first)
            node->left = deleteNode(node->left, value);
        else if (value > node->item.first)
            node->right = deleteNode(node->right, value);
        else {
            if (node->left == u_nullptr && node->right == u_nullptr) {
                if (node == _tail) {
                    _tail = _findSuccessor(_tail);
                }
                _node_alloc.destroy(node);
                _node_alloc.deallocate(node, 1);
                return u_nullptr;
            } else if (node->left == u_nullptr) {
                pointer temp = node->right;
                if (node == _root && node == _tail) {
                    _root = temp;
                    _tail = temp;
                }
                _node_alloc.destroy(node);
                _node_alloc.deallocate(node, 1);
                return temp;
            } else if (node->right == u_nullptr) {
                pointer temp = node->left;
                if (node == _root) {
                    _root = temp;
                }
                _node_alloc.destroy(node);
                _node_alloc.deallocate(node, 1);
                return temp;
            }
            pointer temp = minValueNode(node->right);
            node->item = temp->item;
            node->right = deleteNode(node->right, temp->item.first);
        }
        return node;
    }

    pointer findKey(pointer node, const key_type& k) {
        if (node == u_nullptr) return u_nullptr;
        if (node->item.first == k) return node;

        if (node->item.first < k) return findKey(node->right, k);
        return findKey(node->left, k);
    }

   public:
    pointer minValueNode(pointer node) {
        pointer current = node;
        while (current && current->left != u_nullptr) current = current->left;
        return current;
    }
    pointer getRoot() const { return _root; }
    pointer getTail() const { return _tail; }

    void inorder(pointer node) {
        if (node != u_nullptr) {
            inorder(node->left);

            std::cout << node->item.first << " " << node->item.second
                      << std::endl;
            inorder(node->right);
        }
    }

    iterator begin() { return iterator(_tail, _root); }

    iterator end() { return iterator(u_nullptr, _root); }

    bool empty() const { return _root == u_nullptr; }

    reference operator*() const { return *_root; }

    pointer operator->() { return &(operator*()); }

    BST& operator=(const BST& other) {
        this->~BST();
        _root = other._root;
        _tail = other._tail;
        _size = other._size;
        _comp = other._comp;
        _node_alloc = other._node_alloc;
        return *this;
    }

    void deleteTree(pointer node) {
        if (node == u_nullptr) return;

        deleteTree(node->left);
        deleteTree(node->right);

        std::cout << "Deleting: " << node->item.first << " "
                  << node->item.second << std::endl;
        _node_alloc.destroy(node);
        _node_alloc.deallocate(node, 1);
        _size = 0;
    }

   private:
    pointer _findSuccessor(pointer node) {
        if (node->right == u_nullptr && node->left == u_nullptr) {
            return u_nullptr;
        }
        pointer n = node;
        if (n->right != u_nullptr) {
            return ft::minValueNode(n->right);
        }
        pointer p = n->parent;
        while (p != u_nullptr && n == p->right) {
            n = p;
            p = p->parent;
        }
        return p;
    }

   private:
    pointer _root;
    pointer _tail;
    size_t _size;
    compare_type _comp;
    node_allocator_type _node_alloc;
};

}  // namespace ft

#endif  // __BST_H__
