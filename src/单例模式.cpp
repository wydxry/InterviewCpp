#include <iostream>
using namespace std;

class A
{
    public:
        static A *getInstace()
        {
            return a;
        }

    private:
        A()
        {
            a = new A;
        }
        static A *a;
};

A *A::a = NULL;

//懒汉式:对象的创建在第一次调用getInstance函数时创建
//懒汉式是线程不安全的
class SingletonLazy
{
    public:
        static SingletonLazy *getInstance()
        {
            if (pSingleton == NULL)
            {
                pSingleton = new SingletonLazy;
            }
            return pSingleton;
        }

    private:
        SingletonLazy() {}
        static SingletonLazy *pSingleton;
};

//在类外面进行初始化
SingletonLazy *SingletonLazy::pSingleton = NULL;

//饿汉式:对象在程序执行时优先创建
//饿汉式是线程安全的
class SingletonHungry
{
    public:
        static SingletonHungry *getInstance()
        {
            return pSingleton;
        }

        static void freeSpace()
        {
            if (pSingleton != NULL)
            {
                delete pSingleton;
            }
        }

    private:
        SingletonHungry() {}
        static SingletonHungry *pSingleton;
};

//以下语句将会在main函数运行前执行
SingletonHungry *SingletonHungry::pSingleton = new SingletonHungry;

int main()
{
    SingletonLazy *p1 = SingletonLazy::getInstance();
    SingletonLazy *p2 = SingletonLazy::getInstance();
    if (p1 == p2)
    {
        cout << "单例模式" << endl;
    }
    else
    {
        cout << "不是单例模式" << endl;
    }

    SingletonHungry *p3 = SingletonHungry::getInstance();
    SingletonHungry *p4 = SingletonHungry::getInstance();
    if (p3 == p4)
    {
        cout << "单例模式" << endl;
    }
    else
    {
        cout << "不是单例模式" << endl;
    }
}
