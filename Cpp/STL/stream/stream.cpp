#include <iostream>

using namespace std;

int main()
{
    char c;
/*
    while (cin.get(c))
    {
        cout.put(c);
    }
*/
    //若在eof之后继续读，则会置fail位，cin返回false
    while (cin >> c)
    {
        cout << c;
    }
}