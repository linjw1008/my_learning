//多态

#include <iostream>

using namespace std;

class Shape
{
    protected:
        int width, height;
    public:
        Shape(int a = 0, int b = 0)
        {
            width = a;
            height = b;
        }
        //虚函数
        virtual int area()
        {
            cout << "Parent class area = " << width*height << endl;
            return 0;
        }
};

class Rectangle: public Shape
{
    public:
        Rectangle(int a = 0, int b = 0): Shape(a, b){}
        int area()
        {
            cout << "Rectangle class area = " << width*height << endl;
            return 0;
        }
};

class Triangle: public Shape
{
    public:
        Triangle(int a = 0, int b = 0): Shape(a, b){}
        int area()
        {
            cout << "Triangle class area = " << 0.5*width*height << endl;
            return 0;
        }
};

int main(void)
{
    Shape *shape;
    Rectangle rec(10, 7);
    Triangle tri(10, 5);

    shape = &rec;
    shape->area();

    shape = &tri;
    shape->area();

    system("pause");

    return 0;
}