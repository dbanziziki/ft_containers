#if !defined(__MAP_H__)
#define __MAP_H__

#include <iostream>

#include "bst.hpp"

namespace ft {

template <class Key, class T, class Compare = less<Key>,
          class Alloc = std::allocator<ft::pair<const Key, T> > >
class map {
   public:
    typedef Key key_type;
    typedef T mapped_type;
    typedef ft::pair<key_type, mapped_type> value_type;
    typedef Compare key_compare;
    typedef Alloc allocator_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;
    typedef typename ft::BST<value_type, key_compare>::iterator iterator;
    typedef typename ft::BST<const value_type, key_compare>::const_iterator
        const_iterator;
    typedef typename ft::BST<value_type, key_compare>::pointer tree_pointer;
    typedef size_t size_type;

    class value_compare : public binary_function<value_type, value_type, bool> {
       protected:
        Compare comp;
        value_compare(Compare c) : comp(c) {}

       public:
        bool operator()(const value_type& x, const value_type& y) const {
            return comp(x.first, y.first);
        }
    };

   private:
    ft::BST<value_type, key_compare> _tree;
    allocator_type _alloc;
    Compare _comp;

   public:
    explicit map(const key_compare& comp = key_compare(),
                 const allocator_type& alloc = allocator_type())
        : _tree(), _alloc(alloc), _comp(comp) {}

    template <class InputIterator>
    map(InputIterator first, InputIterator last,
        const key_compare& comp = key_compare(),
        const allocator_type& alloc = allocator_type())
        : _tree(), _alloc(alloc), _comp(comp) {
        this->insert(first, last);
    }

    map(const map& x) {
        this->~map();
        _tree = x._tree;
        _alloc = x._alloc;
        _comp = x._comp;
    }
    ~map() {}

    /* Modifiers */

    ft::pair<iterator, bool> insert(const value_type& val) {
        return _tree.insert(val);
    }

    iterator insert(iterator position, const value_type& val) {
        (void)position;
        return _tree.insert(val).first;
    }

    template <class InputIterator>
    void insert(InputIterator first, InputIterator last) {
        size_type n = ft::difference(first, last);
        while (n--) this->insert(*(first++));
    }

    void erase(iterator position) { this->erase((*position).first); }

    size_type erase(const key_type& k) {
        // if the node does not exist return 0
        _tree.deleteNode(_tree.getHead(), k);
        return 1;
    }

    void erase(iterator first, iterator last) {
        size_type n = ft::difference(first, last);
        std::cout << "n: " << n << std::endl;
        while (first != last) {
            this->erase(first++);
            std::cout << "Erasing" << std::endl;
        };
    }
    /* Element access */

    mapped_type& operator[](const key_type k) {
        tree_pointer res = _tree.findKey(_tree.getHead(), k);
        return res->item.second;
    }

    /* Iterators */

    iterator begin() { return _tree.begin(); }
    iterator end() { return _tree.end(); }

    /* Capacity */

    size_t size() const { return _tree.size(); }

    bool empty() const { return _tree.empty(); }
};

}  // namespace ft

#endif  // __MAP_H__
