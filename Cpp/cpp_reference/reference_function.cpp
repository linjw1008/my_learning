//引用作为参数

#include <iostream>
using namespace std;

double vals[] = {10.1, 12.4, 100.1, 53.4};

double& value(int i);
void swap(int& x, int& y);

int main(void)
{
    int a = 100;
    int b = 120;

    cout << "The value of a(before swap): " << a << endl;
    cout << "The value of b(before swap): " << b << endl;

    swap(a, b);

    cout << "The value of a(after swap): " << a << endl;
    cout << "The value of b(after swap): " << b << endl;

    cout << "The values before changed: " << endl;
    for(int i = 0; i < sizeof(vals) / sizeof(double); i++)
        cout << "vals[" << i << "] = " << vals[i] << endl;

    value(1) = 20.55;
    value(3) = 54.77;

    cout << "The values after changed: " << endl;
    for(int i = 0; i < sizeof(vals) / sizeof(double); i++)
        cout << "vals[" << i << "] = " << vals[i] << endl;

    system("pause");

    return 0;
}

void swap(int& x, int& y)
{
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}

double& value(int i)
{
    return vals[i];
}