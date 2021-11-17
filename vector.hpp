#if !defined(__VECTOR_H__)
#define __VECTOR_H__

#include <cstddef>
#include <memory>

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
    // pointer _capacity;
    size_t _size;
    size_t _capacity;
    allocator_type _alloc;

   public:
    explicit Vector(const allocator_type &alloc = allocator_type())
        : _ptr(nullptr), _end(nullptr), _size(0), _capacity(0), _alloc(alloc) {}
    explicit Vector(size_type n, const value_type &val = value_type(),
                    const allocator_type &alloc = allocator_type())
        : _size(n), _capacity(n), _alloc(alloc) {
        this->_ptr = this->_alloc.allocate(n);
        this->_end = this->_ptr + n;
        while (n--) _ptr[n] = val;
    }
    ~Vector() {
        this->destroy();
        _alloc.deallocate(_ptr, this->_capacity);
    }

    size_t size() const { return _size; }
    size_type capacity() const { return this->_capacity; }
    void destroy() {
        size_t temp = _size;
        while (temp--) this->_alloc.destroy(_ptr + temp);
    }

    void push_back(const value_type &val) {
        if (_size >= _capacity) {
            _realloc(_capacity + _capacity / 2);
        }
        _ptr[_size] = val;
        _size++;
        _end++;
    }

    T &operator[](int index) {
        if (index >= _size) {
            // TODO
            exit(0);
        }
        return _ptr[index];
    }

    T &operator[](int index) const {
        if (index >= _size) {
            // TODO
            exit(0);
        }
        return _ptr[index];
    }

   private:
    void _realloc(size_t newCapacity) {
        pointer new_ptr = this->_alloc.allocate(newCapacity);

        // if (newCapacity < _size) _size = newCapacity; do it elsewhere
        for (size_t i = 0; i < _size; i++) new_ptr[i] = _ptr[i];
        // this->destroy();
        _alloc.deallocate(_ptr, _size);
        _ptr = new_ptr;
        _capacity = newCapacity;
    }
};
}  // namespace ft

#endif  // __VECTOR_H__
