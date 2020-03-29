#include <iostream>

using namespace std;

//auto ptr
template <typename T>
class AutoPtr
{
private:
    T* _ptr;

public:
    AutoPtr(T *ptr):_ptr(ptr)
    {

    }

    //拷贝构造函数
    //需要实现管理权的转移，因为autoptr每次只有一个指向空间
    AutoPtr(AutoPtr<int>& ap)
    {
        this->_ptr = ap._ptr;
        ap._ptr = NULL;
    }

    //等号重载
    AutoPtr<T>& operator=(AutoPtr<T>& ap)
    {
        if (this != &ap)
        {
            delete _ptr;
            _ptr = ap._ptr;
            ap._ptr = NULL;
        }

        return *this;
    }


    AutoPtr()
    {

    }

    ~AutoPtr()
    {
        if (_ptr != NULL)
        {
            delete _ptr;            
        }   
    }

    //解引用操作
    T& operator*()
    {
        return *_ptr;
    }
    //取成员
    T* operator->()
    {
        return _ptr;
    }
};

//shared ptr
template<typename T>
class SharedPtr
{
private:
    T* _ptr;
    int* _count;
public:
    SharedPtr(T* ptr):_ptr(ptr), _count(new int(1))
    {

    }

    SharedPtr(SharedPtr<T>& sp):_ptr(sp._ptr), _count(sp._count)
    {
        ++(*_count);
    }

    SharedPtr<T>& operator=(SharedPtr<T>& sp)
    {
        if (_ptr != sp._ptr)
        {
            //如果只有一个引用了，则先删除空间，因为不会影响到其他sp
            if (--(*_count) == 0)
            {
                delete _ptr;
                delete _count;
                _ptr = NULL;
                _count = NULL;
            }
            _ptr = sp._ptr;
            _count = sp._count;
            ++(*_count);
        }

        return *this;
    }

    ~SharedPtr()
    {
        if (*_count == 0)
        {
            delete _ptr;
            delete _count;
            _ptr = NULL;
            _count = NULL;
        }
    }

    T& operator*()
    {
        return *_ptr;
    }

    T* operator->()
    {
        return _ptr;
    }
};

//采用sharedptr的双向链表
template<typename T>
struct ListNode
{
    T _data;
    SharedPtr<ListNode<T>> _next;
    SharedPtr<ListNode<T>> _prev;

    ListNode(T data):_data(data), _next(NULL), _prev(NULL)
    {

    }
};

//weak ptr
template<typename T>
class WeakPtr
{
private:
    T* _ptr;
public:
    WeakPtr(SharedPtr<T> sp):_ptr(sp._ptr)
    {

    }

    WeakPtr(const WeakPtr<T>& wp):_ptr(wp._ptr)
    {

    }

    WeakPtr<T>& operator=(const WeakPtr<T>& wp)
    {
        if (this != &wp)
        {
            _ptr = wp._ptr;            /* code */
        }
        
        return *this;
    }

};


int main()
{
    AutoPtr<int> p(new int);
    *p = 100;

    cout << *p << endl;

    AutoPtr<int> q(p);

    //
    cout << *q << endl;

    SharedPtr<ListNode<int>> sp1(new ListNode<int>(10));
    SharedPtr<ListNode<int>> sp2(new ListNode<int>(20));
    //可能循环引用，导致内存泄漏
    sp1->_next = sp2;
    sp2->_prev = sp1;



    return 0;
}