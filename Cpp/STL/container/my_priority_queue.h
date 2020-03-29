#ifndef _MY_PRIORITY_QUEUE_H_
#define _MY_PRIORITY_QUEUE_H_

#include <vector>
#include <algorithm>

namespace std
{
    template<class T, class Container = vector<T>, class Compare = less<typename Container::value_type>>
    class my_priority_queue
    {
    public:
        typedef typename Container::value_type value_type;
        typedef typename Container::size_type size_type;
        typedef Container container_type;
    
    protected:
        Compare comp;
        Container con;
    
    public:
        explicit my_priority_queue(const Compare& cmp = Compare(), const Container& c = Container())
        : comp(cmp), con(c)
        {
            make_heap(con.begin(), con.end(), comp);
        }

        void push(const value_type& x)
        {
            con.push_back(x);
            push_heap(con.begin(), con.end(), comp);
        }

        void pop()
        {
            pop_heap(con.begin(), con.end(), comp);
            con.pop_back();
        }

        bool empty() const
        {
            return con.empty();
        }

        size_type size() const
        {
            return con.size();
        }

        const value_type& top() const
        {
            return con.front();
        }
    };

}
#endif