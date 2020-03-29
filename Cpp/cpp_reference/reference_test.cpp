//C++引用

#include <iostream>

using namespace std;

int main(void)
{
    int i;
    double d;

    int& refi = i;
    double& refd = d;

    i = 100;
    cout << "Value of i: " << i << endl;
    cout << "Value of refi(i's reference): " << refi << endl;

    d = 100.1;
    cout << "Value of d: " << d << endl;
    cout << "Value of refd(d's reference): " << refd << endl;

    d = 120.3;
    cout << "Value of d: " << d << endl;
    cout << "Value of refd(d's reference): " << refd << endl;

    system("pause");

    return 0;
}