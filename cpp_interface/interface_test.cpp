//C++的接口通过抽象类实现
//抽象类：如果类中至少有一个函数被声明为纯虚函数，则为抽象类

#include <iostream>

using namespace std;

//基类
class Shape
{
public:
    virtual int getArea() = 0;
    void setWidth(int w) 
    {
        width = w;
    }
    void setHeight(int h)
    {
        height = h;
    }
    //Shape(int w, int h): width(w), height(h) {};
protected:
    int width;
    int height;
};

//派生类
class Rectangle: public Shape
{
public:
    int getArea()
    {
        return height*width;
    }
};

class Triangle: public Shape
{
public:
    int getArea()
    {
        return height*width/2;
    }
};

int main()
{
    Rectangle rec;
    Triangle tri;

    rec.setHeight(10);
    rec.setWidth(20);
    tri.setHeight(10);
    tri.setWidth(20);

    cout << "Area of rec: " << rec.getArea() << endl;
    cout << "Area of tri: " << tri.getArea() << endl;

    system("pause");
    return 0;
}