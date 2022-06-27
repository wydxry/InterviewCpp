#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class A
{
public:
    A(int i)
    {
        cout << "构造函数"<< endl;
        cout << i << endl;
    }
    ~A() {}
    A(const A &a)
    {
        cout << "拷贝构造" << endl;
    }

public:
    string str;
};

int main()
{
    vector<A> vec;
    vec.reserve(10);
    for (int i = 0; i < 10; i++)
    {
        vec.push_back(i); //调用了10次构造函数和10次拷贝构造函数
        // vec.emplace_back(i); //调用了10次构造函数一次拷贝构造函数都没有调用过
    }
}