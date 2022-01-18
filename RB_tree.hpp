#if !defined(__RB_TREE_H__)
#define __RB_TREE_H__

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
        left, right, parent = u_nullptr;
        this->color = RED;
    }
};

template <class T>
class RBTree {
   public:
    typedef T value_type;
    typedef Node<T> node_type;

   private:
    Node<T> *_root;

   protected:
    void rotateLeft(node_type *&, node_type *&);
    void rotateRight(node_type *&, node_type *&);
    void fixViolation(node_type *&, node_type *&);

   public:
    RBTree() : _root(u_nullptr) {}
    RBTree(node_type *p) : _root(p) {}

    void insert(value_type const &val);
};

}  // namespace ft

#endif  // __RB_TREE_H__
