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
    /**
     * @brief Constructs a stack container adaptor object.
     *
     * @param ctnr container_type is the type of the underlying container type
     */
    explicit stack(const container_type ctnr = container_type()) : c(ctnr) {}

    /**
     * @brief Inserts a new element at the top of the stack, above its current
     * top element. The content of this new element is initialized to a copy of
     * val. This member function effectively calls the member function push_back
     * of the underlying container object.
     *
     * @param val Value to which the inserted element is initialized.
     */
    void push(const value_type &val) { c.push_back(val); }

    /**
     * @brief Returns whether the stack is empty: i.e. whether its size is zero.
     *
     * @return true if the underlying container's size is 0, false otherwise.
     */
    bool empty() const { return c.empty(); }

    /**
     * @brief Returns a reference to the top element in the stack. Since stacks
     * are last-in first-out containers, the top element is the last element
     * inserted into the stack.
     * This member function effectively calls member back of the underlying
     * container object.
     *
     * @return value_type&
     */
    value_type &top() { return c.back(); }

    const value_type &top() const { return c.back(); }

    /**
     * @brief Removes the element on top of the stack, effectively reducing its
     * size by one.
     * This member function effectively calls the member function pop_back of
     * the underlying container object.
     *
     */
    void pop() { c.pop_back(); }

    /**
     * @brief Returns the number of elements in the stack.
     *
     * @return The number of elements in the underlying container.
     */
    size_type size() const { return c.size(); }

   private:
    container_type c;

   public:
    friend bool operator==(const stack &lhs, const stack &rhs) {
        return lhs.c == rhs.c;
    }

    friend bool operator!=(const stack &lhs, const stack &rhs) {
        return lhs.c != rhs.c;
    }

    friend bool operator<=(const stack &lhs, const stack &rhs) {
        return lhs.c <= rhs.c;
    }

    friend bool operator>=(const stack &lhs, const stack &rhs) {
        return lhs.c >= rhs.c;
    }

    friend bool operator>(const stack &lhs, const stack &rhs) {
        return lhs.c > rhs.c;
    }

    friend bool operator<(const stack &lhs, const stack &rhs) {
        return lhs.c < rhs.c;
    }
};

}  // namespace ft

#endif
