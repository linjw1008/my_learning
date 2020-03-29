//内联函数

#include <iostream>

using namespace std;

inline int Max(int x, int y)
{
    return (x > y) ? x : y;
}

int main(void)
{

    cout << "Max(20, 10): " << Max(20, 10) << endl;
    cout << "Max(0, 10): " << Max(0, 10) << endl;
    cout << "Max(20, 210): " << Max(20, 210) << endl;
    
    system("pause");

    return 0;
}