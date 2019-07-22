//函数重载

#include <iostream>

using namespace std;

class printData
{
    public:
        void print(int i)
        {
            cout << "整数为： " << i << endl;
        }

        void print(double i)
        {
            cout << "浮点数为： " << i << endl;
        }

        void print(char i[])
        {
            cout << "字符串为： " << i << endl;
        }
};

int main()
{
    printData pd;

    pd.print(5);
    pd.print(544.3654);
    pd.print((char*)("linjw"));

    system("pause");
}