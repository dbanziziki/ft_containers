#ifndef __STACK_H__
#define __STACK_H__

#include "vector.hpp"

namespace ft {
template <class T, class Container = ft::vector<T> >
class stack {
   public:
    typedef T value_type;
    typedef Container container_type;
    typedef size_t size_type;

   public:
    explicit stack(const container_type ctnr = container_type()) : c(ctnr) {}

    void push(const value_type &val) { c.push_back(val); }

    bool empty() const { return c.empty(); }

    value_type &top() { return c.back(); }

    const value_type &top() const { return c.back(); }

    void pop() { c.pop_back(); }

    size_type size() const { return c.size(); }

   protected:
    container_type c;

   public:
    friend bool operator==(const stack<T, Container> &lhs,
                           const stack<T, Container> &rhs) {
        return lhs.c == rhs.c;
    }

    friend bool operator!=(const stack<T, Container> &lhs,
                           stack<T, const Container> &rhs) {
        return lhs.c != rhs.c;
    }

    friend bool operator<=(const stack<T, Container> &lhs,
                           const stack<T, Container> &rhs) {
        return lhs.c <= rhs.c;
    }

    friend bool operator>=(const stack<T, Container> &lhs,
                           const stack<T, const Container> &rhs) {
        return lhs.c >= rhs.c;
    }

    friend bool operator>(const stack<T, Container> &lhs,
                          const stack<T, Container> &rhs) {
        return lhs.c > rhs.c;
    }

    friend bool operator<(const stack<T, Container> &lhs,
                          const stack<T, Container> &rhs) {
        return lhs.c < rhs.c;
    }
};

}  // namespace ft

#endif
