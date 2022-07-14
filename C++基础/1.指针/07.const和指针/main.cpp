#include <iostream>
using namespace std;

// const 和 指针
int main()
{
    int num = 100;

    const int a = 10;
    const int *ptr = &a;

    // 指针指向的数据是一个常量，常量的指针
    // 第一种情况：const在*的左边 修饰的是*  (*p1只读的， p1可读可写)
    const int *p1 = &num;
    // *p1 = 20;
    int data = 20;
    p1 = &data;
    cout << *p1 << endl;

    // 指针变量p2是一个常量，指针(类型)常量（int类型常量），常指针
    // 第二种情况：const在*的右边 修饰的是p2,  (*p2可读可写  p2只读)
    int *const p2 = &num;
    *p2 = 200;
    cout << *p2 << endl;
    // p2 = &data;

    // 第三种情况：const在*的左右两边  既修饰* 也修饰指针变量(*p3只读   p3只读)
    const int *const p3 = &num;
    // *p3 = 10;
    // p3 = &data;

    return 0;
}