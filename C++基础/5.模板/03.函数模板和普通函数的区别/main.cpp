#include <iostream>
using namespace std;

/*
    函数模板不允许自动类型转化
    普通函数能够自动进行类型转化
*/

// 函数模板
template <class T>
T myPlus(T a, T b)
{
    return a + b;
}

// 普通函数
int myPlus2(int a, int b)
{
    return a + b;
}

void test1()
{
    int a = 10;
    int b = 20;
    char c = 'c';

    // myPlus(a, c); // 函数模板 用自动类型推导的时候，不会发生隐式类型转换
    cout << myPlus<int>(a, c) << endl;
    cout << myPlus2(a, c) << endl;

    cout << myPlus(a, b) << endl;
    cout << myPlus2(a, b) << endl;
}

// 函数模板和普通函数的区别
int main()
{
    test1();
    return 0;
}