#include <iostream>

using namespace std;


class test
{
private:
    /* data */
public:
    test(/* args */)
    {
        cout << "run before main!" << endl;
    }
    ~test()
    {
        
    }
};

test t;

int main()
{
    cout << "run in main!" << endl;

    return 0;
}