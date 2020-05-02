#include <iostream>

using namespace std;

//单例模式
//饿汉模式
//线程安全，因为已经提前创建好了实例，

class Singleton
{
private:
    Singleton()
    {
        cout << "init singleton" << endl;
    }
    //禁止使用拷贝构造函数
    Singleton(Singleton&) = delete;
    //禁止使用赋值操作
    Singleton& operator= (const Singleton&) = delete;
    static Singleton* instance_ptr;
public:
    ~Singleton()
    {
        cout << "destroy" << endl;
    }

    static Singleton* get_instance()
    {
        return instance_ptr;
    }
};

//先创建好实例！！！！！！
//静态成员变量只能在类外赋初值
Singleton* Singleton::instance_ptr = new Singleton();

int main()
{
    //只能获取同一个实例
    Singleton* instance = Singleton::get_instance();
    Singleton* instance1 = Singleton::get_instance();

    if (instance1 == instance)
        cout << "the same instance" << endl;

    delete instance;
    delete instance1;

    return 0;
}