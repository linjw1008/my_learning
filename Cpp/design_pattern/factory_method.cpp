#include <iostream>

//工厂方法模式

using namespace std;

enum CarType
{
    BENZ = 0,
    BMW = 1
};

//车
class Car
{
public:
    virtual void createCar() = 0;
};

//奔驰
class BenzCar : public Car
{
public:
    BenzCar()
    {
        cout << "BenzCar: init" << endl;
    }

    virtual void createCar()
    {
        cout << "BenzCar: createCar" << endl;
    }
};

//宝马
class BmwCar : public Car
{
public:
    BmwCar()
    {
        cout << "BmwCar: init" << endl;
    }

    virtual void createCar()
    {
        cout << "BmwCar: createCar" << endl;
    }
};

//把工厂类也进行抽象
//具体如何生成类由子类决定
//工厂
class CarFactory
{
public:
    virtual Car* createCar() = 0;
};

//奔驰车厂
class BenzFactory : public CarFactory
{
    virtual Car* createCar()
    {
        return new BenzCar();
    }
};

//宝马车厂
class BmwFactory : public CarFactory
{
    virtual Car* createCar()
    {
        return new BmwCar();
    }
};

int main()
{
    //由用户决定使用哪个具体的工厂
    //实例化一个奔驰工厂
    CarFactory* factory = new BenzFactory();
    //实例化一个Benz
    Car* benz = factory->createCar();
    //选择宝马工厂
    factory = new BmwFactory();
    //实例化一个Bmw
    Car* bmw = factory->createCar();

    delete benz;
    delete bmw;

    return 0;
}