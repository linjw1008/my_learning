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


        //类成员函数运算符重载 +
        Box operator+(const Box& b)
        {
            Box ret;
            ret.length = this->length + b.length;
            return ret;
        }

        //类成员函数运算符重载 <
        bool operator<(const Box& b)
        {
            return this->length < b.length;
        }

        //类成员函数运算符重载 -- 前缀递减  先计算
        Box operator--(void)
        {
            this->length--;
            return *this;
        }

        //类成员函数运算符重载 -- 后缀递减  先返回值
        Box operator--(int)
        {
            Box ret = *this;
            this->length--;
            return ret;
        }

        //类成员函数运算符重载 -
        Box operator-(void)
        {
            this->length = -(this->length);
            return *this;
        }
    
        //类成员函数运算符重载 =
        void operator=(const Box& b)
        {
            this->length = b.getLength();
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

    cout << "box1 = " << box1.getLength() << endl;
    cout << "box2 = " << box2.getLength() << endl;

    box3 = box1 + box2;
    cout << "box1 + box2 = " << box3.getLength() << endl;

    box3 = box1 - box2;
    cout << "box1 - box2 = " << box3.getLength() << endl;

    cout << "box1 < box2 ? " << (box1<box2) << endl;

    cout << "--box1 = " << (--box1).getLength() << endl;

    cout << "box1-- = " << (box1--).getLength() << endl;

    cout << "-box1 = " << (-box1).getLength() << endl;

    box2 = box1;
    cout << "box2 = box1 " << "box2 = " << box2.getLength() << endl;

    system("pause");

    return 0;

}