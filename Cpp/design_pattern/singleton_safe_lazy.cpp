#include <iostream>
#include <memory>
#include <mutex>

using namespace std;

//单例模式
//线程安全、内存安全的懒汉式
//用到智能指针、锁

class Singleton
{
public:
    ~Singleton()
    {
        cout << "destructor called!" << endl;
    }
    Singleton(Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static shared_ptr<Singleton> get_instance()
    {
        if (m_instance_ptr == NULL)
        {
            lock_guard<std::mutex> lk(m_mutex);
            if (m_instance_ptr == NULL)
            {
                m_instance_ptr = shared_ptr<Singleton>(new Singleton);
            }
        }

        return m_instance_ptr;
    }

private:
    Singleton()
    {
        cout << "constructor called!" << endl;
    }

    //智能指针
    static shared_ptr<Singleton> m_instance_ptr;
    //锁
    static std::mutex m_mutex;
};

shared_ptr<Singleton> Singleton::m_instance_ptr = NULL;
std::mutex Singleton::m_mutex = NULL;


int main()
{
    //只能获取一个实例
    shared_ptr<Singleton> instance = Singleton::get_instance();
    shared_ptr<Singleton> instance1 = Singleton::get_instance();

    return 0;
}