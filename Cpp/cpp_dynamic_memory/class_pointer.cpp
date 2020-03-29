//指向类的指针

#include <iostream>

using namespace std;

class Box
{
public:
    Box(double l = 0, double w = 0, double h = 0):length(l), width(w), height(h)
    {
        cout << "Box's constructor called. " << endl;
    }
    double getVolume()
    {
        return length*width*height;
    }
	Box* getPointer()
	{
		return this;
	}

private:
    double length;
    double width;
    double height;
};


int main(void)
{
    Box b1(3.2, 2.5, 6.9);
    Box b2(5.2, 4.5, 6.9);

    Box* pbox;

    pbox = &b1;
    cout << "The volume of b1 is " << pbox->getVolume() << endl;
	cout << "The address of b1 is " << pbox->getPointer() << endl;

    pbox = &b2;
    cout << "The volume of b2 is " << pbox->getVolume() << endl;
	cout << "The address of b2 is " << pbox->getPointer() << endl;

    system("pause");
    return 0;
}