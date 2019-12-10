#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string a("123");
    string s(a);
    string b("123");

    cout << a << endl;
    cout << s << endl;
    cout << b << endl;
    
    a.assign(s, 2, 2);
    cout << a << endl;

    a.assign("123456789");
    char& tmp = a[2];
    a.assign("123456789");
    tmp = '0';
    cout << a << endl;

    string::iterator it_a_begin = a.begin();
    string::iterator it_a_end = a.end();
    s.assign(it_a_begin, it_a_end--);
    cout << s << endl;
    a.erase(0, a.size() - 1);
    cout << a << endl;

    cout << "The npos is: " << string::npos << endl;

    string A("123456789");
    string B("abcdefghijk");
    A.insert(A.begin(), B.begin(), B.begin() + 2);
    cout << A << endl;

    system("pause");

    return 0;
}