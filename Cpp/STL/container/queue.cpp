#include <queue>
#include <iostream>

using namespace std;

int main()
{
    queue<string> q;

    q.push("These ");
    q.push("are ");
    q.push("some ");

    cout << q.front() << endl;
    q.pop();

    q.push("good ");
    q.push("emamples.");

    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
}