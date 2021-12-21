#ifndef __STACK_H__
#define __STACK_H__

#include "vector.hpp"

namespace ft {
template <class T, class Container = vector<T> >
class stack {
   public:
    typedef T value_type;
    typedef Container container_type;
    typedef size_t size_type;

   public:
    explicit stack(const container_type ctnr = container_type()) : _ctn() {}

    void push(const value_type &val) { _ctn.push_back(val); }

    bool empty() const { return _ctn.empty(); }

    value_type &top() { return _ctn.back(); }
    const value_type &top() const { return _ctn.back(); }
    void pop() { _ctn.pop_back(); }

    size_type size() { return _ctn.size(); }

   private:
    container_type _ctn;

    friend bool operator==(const stack<T, Container> &lhs,
                           const stack<T, Container> &rhs) {
        return lhs._ctn == rhs._ctn;
    }

    friend bool operator!=(const stack<T, Container> &lhs,
                           stack<T, const Container> &rhs) {
        return lhs._ctn != rhs._ctn;
    }

    friend bool operator<=(const stack<T, Container> &lhs,
                           const stack<T, Container> &rhs) {
        return lhs._ctn <= rhs._ctn;
    }

    friend bool operator>=(const stack<T, Container> &lhs,
                           const stack<T, const Container> &rhs) {
        return lhs._ctn >= rhs._ctn;
    }

    friend bool operator>(const stack<T, Container> &lhs,
                          const stack<T, Container> &rhs) {
        return lhs._ctn > rhs._ctn;
    }

    friend bool operator<(const stack<T, Container> &lhs,
                          const stack<T, Container> &rhs) {
        return lhs._ctn < rhs._ctn;
    }
};

}  // namespace ft

#endif
