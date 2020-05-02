#include <iostream>

using namespace std;

//抽象工厂模式

class Car
{
public:
    virtual void createCar(void) = 0;
};

//奔驰
class BenzCar : public Car
{
public:
    BenzCar()
    {
        cout << "Benz: init" << endl;
    }

    virtual void createCar()
    {
        cout << "Benz: create" << endl;
    }
};

//宝马
class BmwCar : public Car
{
public:
    BmwCar()
    {
        cout << "Bmw: init" << endl;
    }

    virtual void createCar()
    {
        cout << "Bmw: create" << endl;
    }
};

//高配车
class HighCar
{
public:
    virtual void createCar() = 0;
};

//高配奔驰
class HighBenzCar : public HighCar
{
public:
    HighBenzCar()
    {
        cout << "HighBenz: init" << endl;
    }

    virtual void createCar()
    {
        cout << "HighBenz: create" << endl;
    }
};

//高配宝马
class HighBmwCar : public HighCar
{
public:
    HighBmwCar()
    {
        cout << "HighBmw: init" << endl;
    }

    virtual void createCar()
    {
        cout << "HighBmw: create" << endl;
    }
};

//车厂
class Factory
{
public:
    virtual Car* createCar() = 0;
    virtual HighCar* createHighCar() = 0;
};

//奔驰车厂
class BenzFactory : public Factory
{
public:
    virtual Car* createCar()
    {
        return new BenzCar();
    }
    virtual HighCar* createHighCar()
    {
        return new HighBenzCar();
    }
};

//宝马车厂
class BmwFactory : public Factory
{
public:
    virtual Car* createCar()
    {
        return new BmwCar();
    }
    virtual HighCar* createHighCar()
    {
        return new HighBmwCar();
    }
};

int main()
{
    //奔驰工厂
    Factory* factory = new BenzFactory();
    //低配车
    Car* benz = factory->createCar();
    //高配车
    HighCar* highBenz = factory->createHighCar();

    delete factory, benz, highBenz;

    return 0;
}