#ifndef _MY_STACK_H_
#define _MY_STACK_H_

#include <deque>
#include <algorithm>
#include <utility>

template <class T, class Container = std::deque<T>>
class my_stack
{
typedef typename Container::value_type value_type;
typedef typename Container::size_type size_type;
typedef Container container_type;
protected:
    Container con;
public:
    explicit my_stack(const Container & stack = Container())
    {
        copy(stack.begin(), stack.end(), con.begin());
    }

    size_type size() const
    {
        return con.size();
    }

    bool empty() const
    {
        return con.empty();
    }

    void push(const T& elem)
    {
        con.push_back(elem);
    }

    void pop()
    {
        con.pop_back();
    }

    value_type& top()
    {
        return con.back();
    }
    
    const value_type& top() const
    {
        return con.back();
    }

    bool operator==(const my_stack<T, Container>& b)
    {
        return this->con == b.con;
    }

    bool operator<(const my_stack<T, Container>& b)
    {
        return this->con < b.con;
    }
};

#endif