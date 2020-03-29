#include <stack>
#include "my_stack.h"
#include <iostream>

using namespace std;

int main()
{
    stack<int> s;
    my_stack<int> my_s;
    my_stack<int> my_s1;

    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    s.pop();
    s.top() = 77;
    s.push(4);
    s.push(5);
    s.pop();
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    my_s1.push(1);
    my_s1.push(2);
    my_s1.push(3);
    my_s.push(1);
    my_s.push(2);
    my_s.push(3);
    cout << my_s.top() << endl;
    my_s.pop();
    my_s.top() = 77;
    my_s.push(4);
    my_s.push(5);
    my_s.pop();
    while (!my_s.empty())
    {
        cout << my_s.top() << " ";
        my_s.pop();
    }
    cout << endl;

    if (my_s == my_s1) cout << "my_s == my_s1" << endl;
    else cout << "my_s != my_s1" << endl;
}