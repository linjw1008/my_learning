
#include <iostream>
using namespace std;

//模板函数需在头文件中定义，且声明为inline
template <typename T>
inline void fun1(T& input)
{
    cout << input << endl;
}