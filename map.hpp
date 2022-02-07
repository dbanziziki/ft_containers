#if !defined(__MAP_H__)
#define __MAP_H__

#include <cstdio>
#include <iostream>

#include "bst.hpp"
#include "reverse_iterator.hpp"

namespace ft {

template <class Key, class T, class Compare = less<Key>,
          class Alloc = std::allocator<ft::pair<const Key, T> > >
class map {
   public:
    typedef Key key_type;
    typedef T mapped_type;
    typedef ft::pair<const key_type, mapped_type> value_type;
    typedef const value_type const_value_type;
    typedef Compare key_compare;
    typedef Alloc allocator_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;
    typedef typename ft::BST<value_type, key_compare>::iterator iterator;
    typedef typename ft::BST<value_type, key_compare>::const_iterator
        const_iterator;
    typedef typename ft::BST<value_type, key_compare>::node_ptr tree_pointer;
    typedef typename ft::reverse_iterator<iterator> reverse_iterator;
    typedef
        typename ft::iterator_traits<iterator>::difference_type difference_type;
    typedef typename ft::reverse_iterator<const_iterator>
        const_reverse_iterator;
    typedef ft::BST<value_type, key_compare> tree_type;
    typedef size_t size_type;

    class value_compare : public binary_function<value_type, value_type, bool> {
       public:
        Compare comp;
        value_compare(Compare c) : comp(c) {}

       public:
        bool operator()(const value_type& x, const value_type& y) const {
            return comp(x.first, y.first);
        }
    };

   private:
    /* Actual data structure storing the map elements */
    ft::BST<value_type, key_compare> _tree;
    allocator_type _alloc;
    Compare _comp;

   public:
    /**
     * @brief Constructs an empty container, with no elements.
     *
     * @param comp Binary predicate that, taking two element keys as argument,
     * returns true if the first argument goes before the second argument in the
     * strict weak ordering it defines, and false otherwise.
     * @param alloc Allocator object.
     */
    explicit map(const key_compare& comp = key_compare(),
                 const allocator_type& alloc = allocator_type())
        : _tree(), _alloc(alloc), _comp(comp) {}

    /**
     * @brief Constructs a container with as many elements as the range
     * [first,last), with each element constructed from its corresponding
     * element in that range.
     *
     * @tparam InputIterator
     * @param [first, last) Input iterators to the initial and final positions
     * in a range. The range used is [first,last), which includes all the
     * elements between first and last, including the element pointed by first
     * but not the element pointed by last.
     * @param comp Binary predicate that, taking two element keys as argument,
     * returns true if the first argument goes before the second argument in the
     * strict weak ordering it defines, and false otherwise.
     * @param alloc Allocator object.
     */
    template <class InputIterator>
    map(InputIterator first, InputIterator last,
        const key_compare& comp = key_compare(),
        const allocator_type& alloc = allocator_type())
        : _tree(), _alloc(alloc), _comp(comp) {
        this->insert(first, last);
    }

    /**
     * @brief Constructs a container with a copy of each of the elements in x.
     *
     * @param x Another map object of the same type (with the same class
     * template arguments Key, T, Compare and Alloc), whose contents are either
     * copied or acquired.
     */
    map(const map& x) : _tree(), _alloc(x._alloc), _comp(x._comp) {
        tree_pointer dest = u_nullptr;
        dest = _tree.copy(x._tree.getRoot(), dest);
        _tree.setRoot(dest);
        _tree.setSize(x.size());
        _tree.setFirst(_tree.minValueNode(dest));
    }

    /**
     * @brief Destroy the map object
     *
     */
    ~map() { _tree.clear(); }

    /**
     * @brief Assigns new contents to the container, replacing its current
     * content.
     *
     * @param x A map object of the same type (i.e., with the same template
     * parameters, key, T, Compare and Alloc).
     * @return *this.
     */

    map& operator=(const map& x) {
        if (&x == this) return *this;
        this->clear();
        _alloc = x._alloc;
        _comp = x._comp;
        tree_pointer dest = u_nullptr;
        dest = _tree.copy(x._tree.getRoot(), dest);
        _tree.setRoot(dest);
        _tree.setSize(x.size());
        _tree.setFirst(ft::minValueNode(dest));
        return *this;
    }

    /* Modifiers */

    /**
     * @brief Extends the container by inserting new elements, effectively
     * increasing the container size by the number of elements inserted.
     *
     * @param val Value to be copied to (or moved as) the inserted element.
     * @return return a pair, with its member pair::first set to an iterator
     * pointing to either the newly inserted element or to the element with an
     * equivalent key in the map. The pair::second element in the pair is set to
     * true if a new element was inserted or false if an equivalent key already
     * existed.
     */
    ft::pair<iterator, bool> insert(const value_type& val) {
        return _tree.insert(val);
    }

    /**
     * @brief Extends the container by inserting new elements, effectively
     * increasing the container size by the number of elements inserted.
     *
     * @param position Hint for the position where the element can be inserted.
     * @param val Value to be copied to (or moved as) the inserted element.
     * @return return an iterator pointing to either the newly inserted element
     * or to the element that already had an equivalent key in the map.
     */
    iterator insert(iterator position, const value_type& val) {
        (void)position;
        return _tree.insert(val).first;
    }

    /**
     * @brief Extends the container by inserting new elements, effectively
     * increasing the container size by the number of elements inserted.
     * @tparam The function template argument InputIterator shall be an input
     * iterator type that points to elements of a type from which value_type
     * objects can be constructed.
     * @param [first, last) Iterators specifying a range of elements. Copies of
     * the elements in the range [first,last) are inserted in the container.
     */
    template <class InputIterator>
    void insert(InputIterator first, InputIterator last,
                typename ft::enable_if<!ft::is_integral<InputIterator>::value,
                                       InputIterator>::type* = u_nullptr) {
        for (; first != last; ++first) {
            insert(*(first));
        }
    }

    /**
     * @brief Removes from the map container a single element.
     *
     * @param position Iterator pointing to a single element to be removed from
     * the map. This shall point to a valid and dereferenceable element.
     */
    void erase(iterator position) { this->erase((*position).first); }

    /**
     * @brief Removes from the map container a single element.
     *
     * @param k Key of the element to be removed from the map.
     * @return returns the number of elements erased.
     */
    size_type erase(const key_type& k) {
        if (!_tree.findKey(_tree.getRoot(), k)) return 0;
        _tree.deleteNode(_tree.getRoot(), k);
        _tree.setSize(_tree.size() - 1);
        return 1;
    }

    /**
     * @brief Removes from the map container a range of elements ([first,last)).
     *
     * @param [first, last) Iterators specifying a range within the map
     * container to be removed: [first,last). i.e., the range includes all the
     * elements between first and last, including the element pointed by first
     * but not the one pointed by last.
     */
    void erase(iterator first, iterator last) {
        while (first != last) {
            this->erase(first++);
        }
    }

    /**
     * @brief Exchanges the content of the container by the content of x, which
     * is another map of the same type. Sizes may differ.
     *
     * @param x Another map container of the same type as this (i.e., with the
     * same template parameters, Key, T, Compare and Alloc) whose content is
     * swapped with that of this container.
     */
    void swap(map& x) { _tree.swap(x._tree); }

    /**
     * @brief Removes all elements from the map container (which are destroyed),
     * leaving the container with a size of 0.
     *
     */
    void clear() { _tree.clear(); }

    /* Element access */
    /**
     * @brief If k matches the key of an element in the container, the function
     * returns a reference to its mapped value.
     * If k does not match the key of any element in the container, the function
     * inserts a new element with that key and returns a reference to its mapped
     * value
     *
     * @param k Key value of the element whose mapped value is accessed.
     * @return A reference to the mapped value of the element with a key value
     * equivalent to k.
     */
    mapped_type& operator[](const key_type k) {
        tree_pointer res = _tree.findKey(_tree.getRoot(), k);
        if (res == u_nullptr) {
            return _tree.insert(ft::make_pair(k, mapped_type())).first->second;
        }
        return res->item->second;
    }

    /* Iterators */

    /**
     * @brief Returns an iterator referring to the first element in the map
     * container.
     *
     * @return An iterator to the first element in the container.
     */
    iterator begin() { return _tree.begin(); }

    const_iterator begin() const { return _tree.begin(); }

    /**
     * @brief An iterator to the first element in the container.
     *
     * @return An iterator to the past-the-end element in the container.
     */
    iterator end() { return _tree.end(); }

    const_iterator end() const { return _tree.end(); }

    /**
     * @brief Returns a reverse iterator pointing to the last element in the
     * container (i.e., its reverse beginning).
     *
     * @return A reverse iterator to the reverse beginning of the sequence
     * container.
     */
    reverse_iterator rbegin() { return reverse_iterator(this->end()); }

    const_reverse_iterator rbegin() const {
        return const_reverse_iterator(this->end());
    }

    /**
     * @brief Returns a reverse iterator pointing to the theoretical element
     * right before the first element in the map container (which is considered
     * its reverse end).
     *
     * @return A reverse iterator to the reverse end of the sequence container.
     */
    reverse_iterator rend() { return reverse_iterator(this->begin()); }

    const_reverse_iterator rend() const {
        return const_reverse_iterator(this->begin());
    }

    /* Capacity */

    /**
     * @brief Returns the number of elements in the map container.
     *
     * @return The number of elements in the container.
     */
    size_t size() const { return _tree.size(); }

    /**
     * @brief Returns whether the map container is empty (i.e. whether its size
     * is 0).
     *
     * @return true if the container size is 0, false otherwise.
     */
    bool empty() const { return _tree.empty(); }

    size_type max_size() const { return _tree.max_size(); }

    /* Observers */

    /**
     * @brief Returns a copy of the comparison object used by the container to
     * compare keys.
     *
     * @return The comparison object.
     */
    key_compare key_comp() const { return _comp; }

    /**
     * @brief Returns a comparison object that can be used to compare two
     * elements to get whether the key of the first one goes before the second.
     *
     * @return The comparison object for element values.
     */
    value_compare value_comp() const { return (value_compare(_comp)); }

    /* Allocator */

    /**
     * @brief Returns a copy of the allocator object associated with the map.
     *
     * @return The allocator.
     */
    allocator_type get_allocator() const { return _alloc; }

    /* Operations */

    /**
     * @brief Searches the container for an element with a key equivalent to k
     * and returns an iterator to it if found, otherwise it returns an iterator
     * to map::end.
     *
     * @param k Key to be searched for.
     * @return An iterator to the element, if an element with specified key is
     * found, or map::end otherwise.
     */
    iterator find(const key_type& k) {
        tree_pointer res = _tree.findKey(_tree.getRoot(), k);
        if (!res) return end();
        return iterator(res, _tree.getRoot());
    }

    /**
     * @brief Searches the container for an element with a key equivalent to k
     * and returns an iterator to it if found, otherwise it returns an iterator
     * to map::end.
     *
     * @param k Key to be searched for.
     * @return A const iterator to the element, if an element with specified key
     * is found, or map::end otherwise.
     */
    const_iterator find(const key_type& k) const {
        tree_pointer res = _tree.findKey(_tree.getRoot(), k);
        if (!res) return end();
        return iterator(res, _tree.getRoot());
    }

    /**
     * @brief Searches the container for elements with a key equivalent to k and
     * returns the number of matches.
     *
     * @param k Key to search for.
     * @return 1 if the container contains an element whose key is equivalent to
     * k, or zero otherwise.
     */
    size_type count(const key_type& k) const {
        tree_pointer res = _tree.findKey(_tree.getRoot(), k);
        if (!res) return 0;
        return 1;
    }

    /**
     * @brief Returns an iterator pointing to the first element in the container
     * whose key is not considered to go before k (i.e., either it is equivalent
     * or goes after).
     *
     * @param k Key to search for.
     * @return An iterator to the the first element in the container whose key
     * is not considered to go before k, or map::end if all keys are considered
     * to go before k.
     */
    iterator lower_bound(const key_type& k) { return _tree.lower_bound(k); }

    const_iterator lower_bound(const key_type& k) const {
        return _tree.lower_bound(k);
    }

    /**
     * @brief Returns an iterator pointing to the first element in the container
     whose key is considered to go after k.
     *
     * @param k Key to search for.
     * @return An iterator to the the first element in the container whose key
     * is considered to go after k, or map::end if no keys are considered to go
     * after k.
     */
    iterator upper_bound(const key_type& k) { return _tree.upper_bound(k); }

    const_iterator upper_bound(const key_type& k) const {
        return _tree.upper_bound(k);
    }

    /**
     * @brief Returns the bounds of a range that includes all the elements in
     * the container which have a key equivalent to k.
     *
     * @param k Key to search for.
     * @return The function returns a pair, whose member pair::first is the
     * lower bound of the range (the same as lower_bound), and pair::second is
     * the upper bound (the same as upper_bound).
     */
    pair<const_iterator, const_iterator> equal_range(const key_type& k) const {
        return ft::make_pair(lower_bound(k), upper_bound(k));
    }

    pair<iterator, iterator> equal_range(const key_type& k) {
        return ft::make_pair(lower_bound(k), upper_bound(k));
    }
};

template <class Key, class T, class Compare, class Alloc>
bool operator==(const map<Key, T, Compare, Alloc>& lhs,
                const map<Key, T, Compare, Alloc>& rhs) {
    if (lhs.size() != rhs.size()) return false;
    return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <class Key, class T, class Compare, class Alloc>
bool operator!=(const map<Key, T, Compare, Alloc>& lhs,
                const map<Key, T, Compare, Alloc>& rhs) {
    return !(lhs == rhs);
}

template <class Key, class T, class Compare, class Alloc>
bool operator<(const map<Key, T, Compare, Alloc>& lhs,
               const map<Key, T, Compare, Alloc>& rhs) {
    return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                       rhs.end());
}

template <class Key, class T, class Compare, class Alloc>
bool operator<=(const map<Key, T, Compare, Alloc>& lhs,
                const map<Key, T, Compare, Alloc>& rhs) {
    return !(rhs < lhs);
}

template <class Key, class T, class Compare, class Alloc>
bool operator>(const map<Key, T, Compare, Alloc>& lhs,
               const map<Key, T, Compare, Alloc>& rhs) {
    return (rhs < lhs);
}

template <class Key, class T, class Compare, class Alloc>
bool operator>=(const map<Key, T, Compare, Alloc>& lhs,
                const map<Key, T, Compare, Alloc>& rhs) {
    return !(lhs < rhs);
}

template <class Key, class T, class Compare, class Alloc>
void swap(map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y) {
    x.swap(y);
}

}  // namespace ft

#endif  // __MAP_H__
