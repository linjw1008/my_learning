#include <queue>
#include <iostream>
#include "my_priority_queue.h"

using namespace std;

int main()
{
    priority_queue<float, vector<float>, greater<float>> q;
    my_priority_queue<float, vector<float>, greater<float>> my_q;

    q.push(1.1);
    q.push(2.2);
    q.push(3.3);
    q.push(4.4);

    cout << q.top() << " ";
    q.pop();

    q.push(5.5);
    q.push(6.6);
    q.push(7.7);

    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;

    my_q.push(1.1);
    my_q.push(2.2);
    my_q.push(3.3);
    my_q.push(4.4);

    cout << my_q.top() << " ";
    my_q.pop();

    my_q.push(5.5);
    my_q.push(6.6);
    my_q.push(7.7);

    while (!my_q.empty())
    {
        cout << my_q.top() << " ";
        my_q.pop();
    }
}
