//友元类

#include <iostream>

using namespace std;

class Box
{
    friend class BoxFriend;
private:
    double width;
public:
    Box(double w) : width(w) {};
};

class BoxFriend
{
private:
    double width;
public:
    void printWidth()
    {
        cout << "The width is: " << width << endl;
    }
    BoxFriend(Box b) : width(b.width) {};
};

int main(void)
{
    Box b1(234.333);
    BoxFriend b2(b1);
    
    b2.printWidth();

    system("pause");

    return 0;
}