//友元函数

#include <iostream>

using namespace std;

class Box
{
    double width;
public:
    friend void printWidth(Box box);
    Box(double w): width(w) {};
};

void printWidth(Box box)
{
    cout << "The width of box is: " << box.width << endl;
}

int main(void)
{
    Box b1(239.33);

    printWidth(b1);

    system("pause");

    return 0;
}