#if !defined(__RB_TREE_H__)
#define __RB_TREE_H__

#include <iostream>

#include "utils.hpp"

namespace ft {

enum Color { RED, BLACK };

template <class T>
struct Node {
    bool color;
    Node *left;
    Node *right;
    Node *parent;
    T value;

    Node(T value) {
        this->value = value;
        left = u_nullptr;
        right = u_nullptr;
        parent = u_nullptr;
        this->color = RED;
    }
};

template <class T, class Compare = ft::less<T>,
          class Alloc = std::allocator<Node<T> > >
class RBTree {
   public:
    typedef T value_type;
    typedef Node<T> *node_ptr;
    typedef Node<T> &node_ref;
    typedef Node<T> node_type;
    typedef Alloc node_alloc_type;

   private:
    Node<T> *_root;
    node_alloc_type _node_alloc;
    Compare _comp;

   private:
    void rotateLeft(node_ptr &, node_ptr &) {}
    void rotateRight(node_ptr &, node_ptr &);
    void fixViolation(node_ptr &, node_ptr &);

   public:
    RBTree(const node_alloc_type &alloc = node_alloc_type(),
           const Compare &comp = Compare())
        : _root(u_nullptr), _node_alloc(alloc), _comp(comp) {}
    RBTree(node_ptr p, const node_alloc_type &alloc,
           const Compare &comp = Compare())
        : _root(p), _node_alloc(alloc), _comp(comp) {}

    /*RBTree(const RBTree &other)
        : _root(other._root),
          _node_alloc(other._node_alloc),
          _comp(other._comp) {}*/

    /* Modifiers */
    void BSTinsert(value_type const &val) {
        if (_root == u_nullptr) {
            _root = newNode(val);
            return;
        }
        BSTInsert_helper(_root, val);
    }

    /* Helpers */
    node_ptr getRoot() const { return _root; }

    node_ptr newNode(const value_type &value) {
        node_ptr new_node = _node_alloc.allocate(1);
        _node_alloc.construct(new_node, node_type(value));
        return new_node;
    }

    void inorder(node_ptr node) {
        if (node != u_nullptr) {
            inorder(node->left);
            std::cout << node->value.first << " " << node->value.second
                      << std::endl;
            inorder(node->right);
        }
    }

    node_ptr BSTInsert_helper(node_ptr root, value_type const &val) {
        if (root == u_nullptr) {
            return newNode(val);
        }
        if (_comp(val, root->value)) {
            root->left = BSTInsert_helper(root->left, val);
            root->left->parent = root;
        } else if (!_comp(val, root->value)) {
            root->right = BSTInsert_helper(root->right, val);
            root->right->parent = root;
        }
        return root;
    }

    void printHelper(node_ptr root, std::string indent, bool last) {
        if (root != u_nullptr) {
            std::cout << indent;
            if (last) {
                std::cout << "R----";
                indent += "   ";
            } else {
                std::cout << "L----";
                indent += "|  ";
            }

            std::string sColor = root->color ? "RED" : "BLACK";
            std::cout << root->value.first << "(" << sColor << ")" << std::endl;
            printHelper(root->left, indent, false);
            printHelper(root->right, indent, true);
        }
    }
};

}  // namespace ft

#endif  // __RB_TREE_H__
