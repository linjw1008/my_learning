#include <iostream>

using namespace std;

//单例模式
//懒汉式
//存在问题：
//1.线程不安全：两个线程同时getinstance，生成两个实例
//2.内存泄漏：没有delete实例

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
        if (instance_ptr == NULL)
            instance_ptr = new Singleton();
        return instance_ptr;
    }

    void use() const
    {
        cout << "use" << endl;
    }
};

//静态成员变量只能在类外赋初值
Singleton* Singleton::instance_ptr = NULL;

int main()
{
    //只能获取一个实例
    Singleton* instance = Singleton::get_instance();
    Singleton* instance1 = Singleton::get_instance();

    delete instance;
    
    return 0;
}