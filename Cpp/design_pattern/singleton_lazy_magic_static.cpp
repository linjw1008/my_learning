#include <iostream>

using namespace std;

/*
懒汉模式
最推荐的懒汉模式——基于局部静态变量

利用magic static特性
如果当变量在初始化的时候，并发同时进入声明语句，并发线程将会阻塞等待初始化结束。
这样保证了并发线程在获取静态局部变量的时候一定是初始化过的，所以具有线程安全性。
*/

class Singleton
{
public:
    ~Singleton()
    {
        cout << "destructor called!" << endl;
    }

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    static Singleton& get_instance()
    {
        //具有线程安全性
        static Singleton instance;
        return instance;
    }
private:
    Singleton()
    {
        cout << "constructor called!"<< endl;
    }
};

int main()
{
    //需要使用引用
    Singleton& instance1 = Singleton::get_instance();
    Singleton& instance2 = Singleton::get_instance();
    Singleton& instance3 = Singleton::get_instance();

    return 0;
}