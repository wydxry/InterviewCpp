#include <iostream>
#include <string>
using namespace std;

// 类模板中的成员函数并不是一开始创建，而是在使用的时候才生成,在替换T后生成
template <class T>
class testClass
{
public:
    T obj;
    void func()
    {
        obj.show();
    }
    
};

class Person1
{
public:
    void show()
    {
        cout << "Person1 show()" << endl;
    }
};

class Person2
{
public:
    void show()
    {
        cout << "Person2 show()" << endl;
    }
};

int main()
{

    // testClass<Person1> tc;
    testClass<Person2> tc;
    tc.func();

    return 0;
}