#include <iostream>
#include <ctime>
using namespace std;

/*
    函数指针
        函数的地址就是存储其机器语言代码的内存的开始地址。
        函数名其实就是函数的地址。
*/

int getSum(int a, int b)
{
    int sum = a + b;
    for (int i = 0; i < 10000000; i++)
    {
        sum += i;
    }
    return sum;
}

int getSum1(int a, int b)
{
    int sum = a + b;
    for (int i = 0; i < 1000000000; i++)
    {
        sum += i;
    }
    return sum;
}

// 定义一个函数，计算求和函数的运行时间
void estimate(int (*pf)(int, int))
{
    // 获取开始的时间
    clock_t start = clock();
    // 调用求和的函数
    (*pf)(4, 5);
    // 获取结束的时间
    clock_t end = clock();
    // 计算时间差值
    cout << end - start << endl;
}

int getSum(int, int);

int main()
{

    cout << getSum << endl;
    int (*pf)(int, int) = getSum;

    int num = 10;
    int *p = &num;

    cout << pf << endl;
    int sum = (*pf)(1, 2);
    cout << sum << endl;

    sum = pf(3, 4);
    cout << sum << endl;

    // estimate(getSum);
    // estimate(getSum1);

    return 0;
}