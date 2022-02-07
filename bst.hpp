#if !defined(__BST_H__)
#define __BST_H__

#include <cmath>
#include <limits>
#include <memory>

#include "bst_iterator.hpp"
#include "stack.hpp"
#include "utils.hpp"

namespace ft {
template <class T, class Compare, class Alloc = std::allocator<T>,
          class Node = ft::node<T> >
class BST {
   public:
    typedef T value_type;
    typedef Alloc allocator_type;
    typedef typename value_type::first_type key_type;
    typedef typename value_type::second_type mapped_type;
    typedef ft::node<T> *node_ptr;
    typedef Compare compare_type;
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename ft::map_iterator<value_type> iterator;
    typedef typename ft::map_iterator<const value_type> const_iterator;
    typedef typename allocator_type::template rebind<Node>::other
        node_allocator_type;
    typedef std::ptrdiff_t difference_type;
    typedef size_t size_type;

    BST(const allocator_type &allocator = allocator_type())
        : _root(u_nullptr),
          _first(u_nullptr),
          _size(0),
          _node_alloc(allocator) {}

    ~BST() {}

   public:
    size_t size() const { return _size; }

    size_type max_size() const {
        return std::numeric_limits<difference_type>::max() /
               (sizeof(Node) / 2 ?: 1);
    }

    ft::pair<iterator, bool> insert(const value_type &value) {
        node_ptr newNode = _new_node(value);
        if (_root == u_nullptr) {
            _root = newNode;
            _first = newNode;
            _size++;
            return ft::make_pair(iterator(_first, _root), true);
        }
        node_ptr x = _root;
        node_ptr y = u_nullptr;

        while (x != u_nullptr) {
            y = x;
            if (_comp(value.first, x->item->first)) {
                x = x->left;
            } else if (_comp(x->item->first, value.first)) {
                x = x->right;
            } else {
                _free_node(newNode);
                return ft::make_pair(iterator(x, _root), false);
            }
        }

        if (_comp(value.first, y->item->first)) {
            if (_comp(value.first, _first->item->first)) _first = newNode;
            y->left = newNode;
            newNode->parent = y;
            _size++;
            return ft::make_pair(iterator(newNode, _root), true);
        } else {
            y->right = newNode;
            newNode->parent = y;
            _size++;
            return ft::make_pair(iterator(newNode, _root), true);
        }
        return ft::make_pair(iterator(newNode, _root), true);
    }

    node_ptr deleteNode(node_ptr node, const key_type &value) {
        if (node == u_nullptr) return node;
        if (value < node->item->first)
            node->left = deleteNode(node->left, value);
        else if (value > node->item->first)
            node->right = deleteNode(node->right, value);
        else {
            if (node->left == u_nullptr && node->right == u_nullptr) {
                if (node == _first) _first = _findSuccessor(_first);
                if (node == _root) _root = u_nullptr;
                _free_node(node);
                return u_nullptr;
            } else if (node->left == u_nullptr) {
                node_ptr temp = node->right;
                if (node == _root && node == _first) {
                    _root = temp;
                    _first = temp;
                } else if (node == _first) {
                    _first = _findSuccessor(_first);
                }
                temp->parent = node->parent;
                _free_node(node);
                return temp;
            } else if (node->right == u_nullptr) {
                node_ptr temp = node->left;
                if (node == _root) {
                    _root = temp;
                }
                temp->parent = node->parent;
                _free_node(node);
                return temp;
            }
            node_ptr temp = minValueNode(node->right);
            _value_allocator.destroy(node->item);
            _value_allocator.deallocate(node->item, 1);
            node->item = _value_allocator.allocate(1);
            _value_allocator.construct(node->item, *(temp->item));
            node->right = deleteNode(node->right, temp->item->first);
        }
        return node;
    }

    node_ptr findKey(node_ptr node, const key_type &k) const {
        if (node == u_nullptr) return u_nullptr;
        if (node->item->first == k) return node;

        if (node->item->first < k) return findKey(node->right, k);
        return findKey(node->left, k);
    }

   public:
    node_ptr minValueNode(node_ptr node) {
        node_ptr current = node;
        while (current && current->left != u_nullptr) current = current->left;
        return current;
    }

    /* getters */
    node_ptr getRoot() const { return _root; }
    node_ptr getTail() const { return _first; }

    /* setters */
    void setSize(size_type n) { _size = n; }
    void setRoot(node_ptr new_root) { _root = new_root; }
    void setFirst(node_ptr p) { _first = p; }

    void inorder(node_ptr node) {
        if (node != u_nullptr) {
            inorder(node->left);

            std::cout << node->item->first << " " << node->item->second
                      << std::endl;
            inorder(node->right);
        }
    }

    iterator begin() { return iterator(_first, _root); }

    const_iterator begin() const { return iterator(_first, _root); }

    iterator end() { return iterator(u_nullptr, _root); }

    const_iterator end() const { return iterator(u_nullptr, _root); }

    bool empty() const { return _root == u_nullptr; }

    reference operator*() const { return *(_root->item); }

    pointer operator->() { return &(operator*()); }

    BST &operator=(const BST &other) {
        this->clear();
        node_ptr dest = u_nullptr;
        _comp = other._comp;
        _node_alloc = other._node_alloc;
        dest = this->copy(other.getRoot(), dest);
        this->setRoot(dest);
        this->setSize(other.size());
        this->setFirst(this->minValueNode(dest));
        return *this;
    }

    void deleteTree(node_ptr root) {
        if (root == u_nullptr) return;

        deleteTree(root->left);
        deleteTree(root->right);
        _node_alloc.destroy(root);
        _node_alloc.deallocate(root, 1);
    }

    void deleteTree() {
        if (_root == u_nullptr) return;

        deleteTree(_root->left);
        deleteTree(_root->right);
        _node_alloc.destroy(_root);
        _node_alloc.deallocate(_root, 1);
    }

    void clear() {
        if (_size == 0) return;
        node_ptr ptr;

        ft::vector<node_ptr> v;
        if (_size >= 2) {
            v.reserve(floor(2 * log2(_size)));
        }
        ft::stack<node_ptr> s(v);
        if (_root) s.push(_root);

        while (!(s.empty())) {
            ptr = s.top();
            s.pop();
            if (ptr->left) s.push(ptr->left);
            if (ptr->right) s.push(ptr->right);
            _free_node(ptr);
        }
        _root = u_nullptr;
        _first = u_nullptr;
        _size = 0;
    }

    void swap(BST &x) {
        node_ptr prev_root = _root;
        node_ptr prev_first = _first;
        size_t prev_size = _size;
        compare_type prev_comp = _comp;
        node_allocator_type prev_node_alloc = _node_alloc;

        _root = x._root;
        _first = x._first;
        _comp = x._comp;
        _node_alloc = x._node_alloc;
        _size = x._size;

        x._root = prev_root;
        x._first = prev_first;
        x._comp = prev_comp;
        x._node_alloc = prev_node_alloc;
        x._size = prev_size;
    }

    node_ptr copy(node_ptr root, node_ptr dest) {
        if (root == u_nullptr) return u_nullptr;
        dest = _new_node(*(root->item));
        dest->left = copy(root->left, dest->left);
        if (dest->left) dest->left->parent = dest;
        dest->right = copy(root->right, dest->right);
        if (dest->right) dest->right->parent = dest;
        return dest;
    }

    iterator lower_bound(const key_type &k) {
        node_ptr lb = _lower_bound_helper(_root, k);
        return iterator(lb, _root);
    }

    const_iterator lower_bound(const key_type &k) const {
        node_ptr lb = _lower_bound_helper(_root, k);
        return iterator(lb, _root);
    }

    iterator upper_bound(const key_type &k) {
        node_ptr ub = _upper_bound_helper(_root, k);
        return iterator(ub, _root);
    }

    const_iterator upper_bound(const key_type &k) const {
        node_ptr ub = _upper_bound_helper(_root, k);
        return iterator(ub, _root);
    }

   private:
    node_ptr _new_node(value_type const &value) {
        pointer value_ptr = _value_allocator.allocate(1);
        _value_allocator.construct(value_ptr, value);
        Node *node_ptr = _node_alloc.allocate(1);
        _node_alloc.construct(node_ptr, value_ptr);
        return node_ptr;
    }

    node_ptr _lower_bound_helper(node_ptr node, const key_type &k) const {
        if (node == u_nullptr) return node;

        if (_comp(k, node->item->first)) {
            node_ptr res = _lower_bound_helper(node->left, k);
            if (res) return res;
        } else if (_comp(node->item->first, k)) {
            return _lower_bound_helper(node->right, k);
        }
        return node;
    }

    node_ptr _upper_bound_helper(node_ptr node, const key_type &k) const {
        if (node == u_nullptr) return node;

        if (!_comp(k, node->item->first)) {
            return _upper_bound_helper(node->right, k);
        }
        node_ptr res = _upper_bound_helper(node->left, k);
        if (res) return res;
        return node;
    }

    void _free_node(node_ptr &node) {
        _value_allocator.destroy(node->item);
        _value_allocator.deallocate(node->item, 1);
        node->item = u_nullptr;
        _node_alloc.destroy(node);
        _node_alloc.deallocate(node, 1);
        node = u_nullptr;
    }

    node_ptr _findSuccessor(node_ptr node) {
        node_ptr n = node;
        if (n->right != u_nullptr) {
            return ft::minValueNode(n->right);
        }
        node_ptr p = n->parent;
        while (p != u_nullptr && n == p->right) {
            n = p;
            p = p->parent;
        }
        return p;
    }

   private:
    node_ptr _root;
    node_ptr _first;
    size_t _size;
    compare_type _comp;
    allocator_type _value_allocator;
    node_allocator_type _node_alloc;
};

}  // namespace ft

#endif  // __BST_H__
