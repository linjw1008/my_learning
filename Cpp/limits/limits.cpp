//c语言的预处理常数
#include <climits>
//#include <limits.h>
#include <float.h>
//#include <cfloat>
//c++极值类别
#include <limits>
#include <iostream>


using namespace std;

int main()
{
    numeric_limits<int> a;
    cout << a.min() << endl;
    cout << a.max() << endl;
    cout << a.digits10 << endl;

    return 0;
}