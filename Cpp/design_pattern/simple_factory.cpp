#include <iostream>

//简单工厂模式

using namespace std;

enum CarType
{
    BENZ = 0,
    BMW = 1
};

class Car
{
public:
    virtual void createCar() = 0;
};

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

//工厂
class CarFactory
{
public:
    Car* createCar(CarType type)
    {
        switch (type)
        {
        case BENZ:
            return new BenzCar();
            break;
        case BMW:
            return new BmwCar();
            break;
        default:
            return NULL;
            break;
        }
    }
};

int main()
{
    //实例化一个工厂模式
    CarFactory factory;
    //实例化一个Benz
    Car* benz = factory.createCar(BENZ);
    //实例化一个Bmw
    Car* bmw = factory.createCar(BMW);

    delete benz;
    delete bmw;

    return 0;
}