/*
 * arrays不是标准的容器，但是可以当做STL容器使用
 * 方法1：把指针当做迭代器使用
 * 方法2：外包装一层接口
 * 本程序采用方法2，将arrays当做STL容器使用
 *
 */


#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

template<class T, size_t thesize>
class carray
{
private:
    T v[thesize];

public:
    typedef T           value_type;
    typedef T*          iterator;
    typedef const T*    const_iterator;
    typedef T&          reference;
    typedef const T&    const_reference;
    typedef size_t      size_type;
    typedef ptrdiff_t   difference_type;

    iterator        begin() {return v;}
    const_iterator  begin() const {return v;}
    iterator        end()   {return v + thesize;}
    const_iterator  end() const {return v + thesize;}

    reference       operator[](size_type i) {return v[i];}
    const_reference operator[](size_type i) const {return v[i];}

    size_type       size() const {return thesize;}
    size_type       max_size() const {return thesize;}

    T*              as_array() {return v;}
};

int main()
{
    carray<int, 10> array;

    for (size_t i = 0; i < array.size(); ++i)
    {
        array[i] = i;
    }

    copy(array.begin(), array.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //把指针当做迭代器使用
    reverse(array.begin(), array.end());

    copy(array.begin(), array.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}