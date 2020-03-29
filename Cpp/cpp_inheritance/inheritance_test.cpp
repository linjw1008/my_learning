//类继承

#include <iostream>

using namespace std;

//基类
class Shape
{
protected:
    double height;
    double width;

public:
    void setHeight(double h)
    {
        height = h;
    }
    void setWidth(double w)
    {
        width = w;
    }    
    
    Shape(double h, double w): height(h), width(w)
    {
        cout << "Box constructer called." << endl;
    }

    //必须提供默认构造函数
    Shape(){}
};

//基类
class PaintCost
{
public:
    double getCost(double area)
    {
        return area * 70;
    }
};

//派生类
class Rectangle: public Shape, public PaintCost
{
public:
    double getArea()
    {
        return height*width;
    }
    Rectangle(double h, double w);
	Rectangle() {};
};

Rectangle::Rectangle(double h, double w)
{
    setHeight(h);
    setWidth(w);
}

int main(void)
{
    Rectangle rec(102.3, 443.6);

    cout << "The area is: " << rec.getArea() << endl;

    cout << "The paint cost is: " << rec.getCost(rec.getArea()) << endl;

    system("pause");

    return 0;
}

