//动态内存分配示例

#include <iostream>
using namespace std;

int main()
{
    double* pdouble = NULL;

    if(!(pdouble = new double))
    {
        cout << "Error: out of memory." << endl;
        exit(EXIT_FAILURE);
    }

    *pdouble = 1896.1896;
    cout << "The value of point pdouble is: " << *pdouble << endl;
    cout << "The address of *pdouble is: " << pdouble << endl;

    delete pdouble;

	system("pause");

    return 0;
}