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
    ~map() {}

    ft::pair<iterator, bool> insert(const value_type& val) {
        return _tree.insert(val);
    }
};

}  // namespace ft

#endif  // __MAP_H__
