#include <vector>
#include <iostream>
#include <numeric>
#include <limits>

using namespace std;

namespace std
{
    template <class T>
    class my_allocator
    {
    public:
        typedef size_t      size_type;
        typedef ptrdiff_t   differenct_type;
        typedef T*          pointer;
        typedef const T*    const_pointer;
        typedef T&          reference;
        typedef const T&    const_reference;
        typedef T           value_type;

        //用于为其他类型配置空间
        template <class U>
        struct rebind
        {
            typedef my_allocator<U> other;
        };
        
        //返回某个值的地址
        pointer address(reference value) const
        {
            return &value;
        }

        const_pointer address(const_reference value) const
        {
            return &value;
        }

        //构造函数与析构函数
        my_allocator() throw()
        {
        }

        my_allocator(const my_allocator&) throw()
        {
        }

        template <class U>
            my_allocator(const my_allocator<U>&) throw()
        {
        }

        ~my_allocator() throw()
        {
        }

        //返回最大可配置的空间
        size_type max_size() const throw()
        {
            return numeric_limits<size_t>::max();
        }

        pointer allocate(size_type num, allocator<void>::const_pointer hint = 0)
        {
            //调用全局的operator new分配内存
            return (pointer) (::operator new (num * sizeof(T)));
        }

        void construct(pointer p, const T& value)
        {
            //调用placement new，用于在已经分配好内存的地址构造对象
            new ((void*)p)T(value);
        }

        void destory(pointer p)
        {
            ((T*)p)->~T();
        }

        void deallocate(pointer p, size_type num)
        {
            ::operator delete ((void *) p);
        }
    };

    //比较两个配置器是否使用了相同的内存模型
    //相同
    template<class T1, class T2>
    bool operator== (const my_allocator<T1>&, const my_allocator<T2>&) throw()
    {
        return true;
    }

    template<class T1, class T2>
    bool operator!= (const my_allocator<T1>&, const my_allocator<T2>&) throw()
    {
        return true;
    }    
}

int main()
{
    vector<int, my_allocator<int>> v1;
    vector<float, my_allocator<float>> v2;

    v1.resize(10, 1);

    for (int i = 0; i < v1.size(); ++i)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    if (v1.get_allocator() == v2.get_allocator())
        cout << "v1 allocator == v2 allocator" << endl;
        cout << flush;

    int i = 1;
    cout << i++ << i-- << endl;
}