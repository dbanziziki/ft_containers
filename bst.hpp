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
    typedef Compare compare_type;
    typedef typename node_allocator_type::pointer pointer;
    typedef typename node_allocator_type::const_pointer const_pointer;
    typedef typename node_allocator_type::reference reference;
    typedef typename node_allocator_type::const_reference const_reference;
    typedef typename ft::map_iterator<value_type> iterator;
    typedef typename ft::map_iterator<const value_type> const_iterator;
    typedef size_t size_type;

    BST(const node_allocator_type& node_alloc = node_allocator_type())
        : _root(u_nullptr),
          _first(u_nullptr),
          _size(0),
          _node_alloc(node_alloc) {}

    ~BST() {}

   public:
    size_t size() const { return _size; }

    pointer insert(pointer root, const value_type& value) {
        if (root == u_nullptr) {
            pointer new_node = _new_node(value);
            if (new_node->item.first < _first->item.first) _first = new_node;
            _last = new_node;
            return new_node;
        }
        if (value.first < root->item.first)
            root->left = insert(root->left, value);
        else
            root->right = insert(root->right, value);
        return root;
    }

    // TODO: when the key already exist
    ft::pair<iterator, bool> insert(const value_type& value) {
        if (_root == u_nullptr) {
            _root = _new_node(value);
            _first = _root;
            _size += 1;
            return ft::make_pair(iterator(_root, u_nullptr), true);
        }
        insert(_root, value);
        _size += 1;
        return ft::make_pair(iterator(_last, u_nullptr), true);
    }

    pointer deleteNode(pointer node, const key_type& value) {
        if (node == u_nullptr) return node;
        if (value < node->item.first)
            node->left = deleteNode(node->left, value);
        else if (value > node->item.first)
            node->right = deleteNode(node->right, value);
        else {
            if (node->left == u_nullptr && node->right == u_nullptr) {
                if (node == _first) _first = _findSuccessor(_first);
                _node_alloc.destroy(node);
                _node_alloc.deallocate(node, 1);
                if (node == _root) _root = u_nullptr;
                return u_nullptr;
            } else if (node->left == u_nullptr) {
                pointer temp = node->right;
                if (node == _root && node == _first) {
                    _root = temp;
                    _first = temp;
                } else if (node == _first) {
                    _first = _findSuccessor(_first);
                }
                temp->parent = node->parent;
                _node_alloc.destroy(node);
                _node_alloc.deallocate(node, 1);
                return temp;
            } else if (node->right == u_nullptr) {
                pointer temp = node->left;
                if (node == _root) {
                    _root = temp;
                }
                temp->parent = node->parent;
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

    pointer findKey(pointer node, const key_type& k) const {
        if (node == u_nullptr) return u_nullptr;
        if (node->item.first == k) return node;

        if (node->item.first < k) return findKey(node->right, k);
        return findKey(node->left, k);
    }

   public:
    void setSize(size_type n) { _size = n; }
    pointer minValueNode(pointer node) {
        pointer current = node;
        while (current && current->left != u_nullptr) current = current->left;
        return current;
    }
    pointer getRoot() const { return _root; }
    pointer getTail() const { return _first; }
    void setRoot(pointer new_root) {
        _root = new_root;
    }

    void inorder(pointer node) {
        if (node != u_nullptr) {
            inorder(node->left);

            std::cout << node->item.first << " " << node->item.second
                      << std::endl;
            inorder(node->right);
        }
    }

    iterator begin() { return iterator(_first, _root); }

    const_iterator begin() const { return iterator(_first, _root); }

    iterator end() { return iterator(u_nullptr, _root); }

    const_iterator end() const { return iterator(u_nullptr, _root); }

    bool empty() const { return _root == u_nullptr; }

    reference operator*() const { return *_root; }

    pointer operator->() { return &(operator*()); }

    BST& operator=(const BST& other) {
        this->~BST();
        _root = other._root;
        _first = other._first;
        _size = other._size;
        _comp = other._comp;
        _node_alloc = other._node_alloc;
        return *this;
    }

    pointer _copy(pointer root, pointer dest) {
        if (root == u_nullptr) return u_nullptr;
        dest = _new_node(root->item);

        dest->left = _copy(root->left, dest->left);
        dest->right = _copy(root->right, dest->right);
        return dest;
    }

   private:
    pointer _new_node(value_type const& value) {
        pointer new_node = _node_alloc.allocate(1);
        _node_alloc.construct(new_node, Node(value));
        return new_node;
    }
    pointer _findSuccessor(pointer node) {
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
    pointer _first;
    pointer _last;
    size_t _size;
    compare_type _comp;
    node_allocator_type _node_alloc;
};

}  // namespace ft

#endif  // __BST_H__
