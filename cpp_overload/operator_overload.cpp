//运算符重载

#include <iostream>

using namespace std;

class Box
{
    public:

        Box(double len)
        {
            this->length = len;
        }

        Box(void)
        {
            length = 0;
        }

        double getLength(void) const
        {
            return length;
        }

        void setLength(double len) 
        {
            length = len;
        }


        //类成员函数运算符重载
        Box operator+(const Box& b)
        {
            Box ret;
            ret.length = this->length + b.length;
            return ret;
        }
    
    private:
        double length;
};

//非成员函数运算符重载
Box operator-(const Box& a, const Box& b)
{
    Box ret;
    ret.setLength(a.getLength() - b.getLength()); 
    return ret;
}

int main()
{
    Box box1(10);
    Box box2(20);
    Box box3;

    box3 = box1 + box2;
    cout << "box1 + box2 = " << box3.getLength() << endl;

    box3 = box1 - box2;
    cout << "box1 - box2 = " << box3.getLength() << endl;


    system("pause");

    return 0;

}