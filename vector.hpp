#if !defined(__VECTOR_H__)
#define __VECTOR_H__

#include <cstddef>
#include <memory>

#include "iterator.hpp"

namespace ft {
template <class T, class Alloc = std::allocator<T> >
class Vector {
   private:
    typedef T value_type;
    typedef T const const_value_type;
    typedef Alloc allocator_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;
    typedef size_t size_type;

    pointer _ptr;
    pointer _end;
    pointer _end_capacty;
    size_t _size;
    size_t _capacity;
    allocator_type _alloc;

   public:
    explicit Vector(const allocator_type &alloc = allocator_type())
        : _ptr(nullptr),
          _end_capacty(nullptr),
          _end(nullptr),
          _size(0),
          _capacity(0),
          _alloc(alloc) {}
    explicit Vector(size_type n, const value_type &val = value_type(),
                    const allocator_type &alloc = allocator_type())
        : _size(n), _capacity(n), _alloc(alloc) {
        this->_ptr = this->_alloc.allocate(n);
        this->_end = this->_ptr;
        this->_end_capacty = this->_ptr + n;
        while (n--) {
            this->_alloc.construct(this->_end++, val);
        }
    }

    Vector(const Vector &x) : _alloc(x._alloc) {
        /*size_type n = x.size();
        this->_ptr = this->_alloc.allocate(x.capacity());
        this->_end = this->_ptr;
        this->_size = n;
        this->_capacity = x.capacity();
        this->_end_capacty = x._ptr + n;
        pointer src = x._ptr;
        while (n--) this->_alloc.construct(_end++, *src++);*/
    }

    ~Vector() {
        clear();
        _alloc.deallocate(_ptr, capacity());
    }

    /* Element access */

    /**
     * @brief Returns a reference to the element at position n in the vector
     * container.
     *
     * @param n Position of an element in the container.
     * @return reference The element at the specified position in the vector.
     */
    reference operator[](size_type index) {
        if (index >= _size) {
            // TODO
            exit(0);
        }
        return _ptr[index];
    }

    /**
     * @brief Returns a reference to the element at position n in the vector
     * container.
     *
     * @param n Position of an element in the container.
     * @return reference The element at the specified position in the vector.
     */
    reference operator[](size_type index) const {
        if (index >= _size) {
            // TODO
            exit(0);
        }
        return _ptr[index];
    }

    /**
     * @brief Returns a reference to the element at position n in the vector.
     *
     * @param n Position of an element in the container.
     * @return The element at the specified position in the container.
     */
    reference at(size_type n) {
        if (n >= _size) {
            throw std::out_of_range("ft::vector");
        }
        return _ptr[n];
    }

    /**
     * @brief Returns a reference to the element at position n in the vector.
     *
     * @param n Position of an element in the container.
     * @return The element at the specified position in the container.
     */
    const_reference at(size_type n) const {
        if (n >= _size) {
            throw std::out_of_range("ft::vector");
        }
    }

    /**
     * @brief Returns a reference to the first element in the vector.
     *
     * @return A reference to the first element in the vector container.
     */
    reference front() { return *_ptr; }

    /**
     * @brief Returns a reference to the first element in the vector.
     *
     * @return A reference to the first element in the vector container.
     */
    const_reference front() const { return *_ptr; }

    /**
     * @brief Returns a reference to the last element in the vector.
     *
     * @return A reference to the last element in the vector.
     */
    reference back() { return (*(_end - 1)); }

    /**
     * @brief Returns a reference to the last element in the vector.
     *
     * @return A reference to the last element in the vector.
     */
    const_reference back() const { return (*(_end - 1)); }

    /* Capacity */

    /**
     * @brief Returns the number of elements in the vector.
     *
     * @return The number of elements in the container.
     */
    size_type size() const { return _size; }

    /**
     * @brief Returns the size of the storage space currently allocated for the
     * vector, expressed in terms of elements.
     *
     * @return The size of the currently allocated storage capacity in the
     * vector, measured in terms of the number elements it can hold.
     */
    size_type capacity() const { return this->_capacity; }

    /**
     * @brief Returns the maximum number of elements that the vector can hold.
     *
     * @return The maximum number of elements a vector container can hold as
     * content.
     */
    size_type max_size() const { return _alloc.max_size(); }

    /**
     * @brief Returns whether the vector is empty (i.e. whether its size is 0).
     *
     * @return true if the container size is 0, false otherwise.
     */
    bool empty() const { return size() == 0; }

    /**
     * @brief Resizes the container so that it contains n elements.
     *
     * @param n New container size, expressed in number of elements.
     * @param val Object whose content is copied to the added elements in case
     * that n is greater than the current container size. If not specified, the
     * default constructor is used instead.
     */
    void resize(size_type n, value_type val = value_type()) {
        size_type prev_size = size();
        if (n < _size) {
            size_type i = _size - n;
            while (i--) pop_back();
        } else if (n > _size && n <= _capacity) {
            size_type i = n - _size;
            while (i--) push_back(val);
        } else if (n > _capacity) {
            reserve(n);
            while (prev_size < n) {
                push_back(val);
                prev_size++;
            }
        }
    }

    /**
     * @brief Requests that the vector capacity be at least enough to contain n
     * elements.
     *
     * @param new_cap Minimum capacity for the vector.
     */
    void reserve(size_type new_cap) {
        if (new_cap <= capacity()) return;
        pointer new_ptr = this->_alloc.allocate(new_cap);
        pointer prev_ptr = _ptr;
        _end = new_ptr;
        size_type i = size();
        while (i--) {
            this->_alloc.construct(_end++, *prev_ptr);
            prev_ptr++;
        }
        clear();
        _alloc.deallocate(_ptr, capacity());
        _ptr = new_ptr;
        _capacity = new_cap;
    }

    /* Modifiers */

    /**
     * @brief Assigns new contents to the vector, replacing its current
     * contents, and modifying its size accordingly.
     *
     * @param n New size for the container.
     * @param val Value to fill the container with. Each of the n elements in
     * the container will be initialized to a copy of this value.
     */
    void assign(size_type n, const value_type &val) {
        this->~Vector();
        _ptr = _alloc.allocate(n);
        _end = _ptr;
        _end_capacty = _ptr + n;
        _size = n;
        _capacity = n;
        while (n--) _alloc.construct(_end++, val);
    }

    /**
     * @brief Exchanges the content of the container by the content of x, which
     * is another vector object of the same type. Sizes may differ.
     *
     * @param x Another vector container of the same type (i.e., instantiated
     * with the same template parameters, T and Alloc) whose content is swapped
     * with that of this container.
     */
    void swap(Vector &x) {
        if (this == &x) return;

        pointer x_ptr = x._ptr;
        pointer x_end = x._end;
        pointer x_end_capacity = x._end_capacty;
        size_type x_size = x.size();
        size_type x_capacity = x.capacity();

        x._ptr = this->_ptr;
        x._end = this->_end;
        x._end_capacty = this->_end_capacty;
        x._capacity = this->_capacity;
        x._size = this->_size;

        this->_size = x_size;
        this->_capacity = x_capacity;
        this->_ptr = x_ptr;
        this->_end = x_end;
        this->_end_capacty = x_end_capacity;
    }

    /**
     * @brief Adds a new element at the end of the vector, after its current
     * last element. The content of val is copied (or moved) to the new element.
     *
     * @param val value to be copied (or moved) to the new element.
     */
    void push_back(const value_type &val) {
        if (_size >= _capacity) {
            size_type new_cap =
                _capacity == 0 ? 2 : (_capacity + (_capacity / 2));
            reserve(new_cap);
        }
        _alloc.construct(_end++, val);
        _size += 1;
    }

    /**
     * @brief Removes the last element in the vector, effectively reducing the
     * container size by one.
     *
     */
    void pop_back() {
        if (_size == 0) return;
        _alloc.destroy(--_end);
        _size--;
    }

    /**
     * @brief Removes all elements from the vector (which are destroyed),
     * leaving the container with a size of 0.
     *
     */
    void clear() {
        pointer temp = this->_ptr;
        size_type i = 0;
        while (i < _size) {
            _alloc.destroy(temp);
            temp++;
            i++;
        }
    }

    /* Allocator */
    allocator_type get_allocator() const { return _alloc; }

   private:
};
}  // namespace ft

#endif  // __VECTOR_H__
