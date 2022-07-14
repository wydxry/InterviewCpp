#include <iostream>
using namespace std;

// 二级指针	（一个指针变量保存的是另外一个指针变量的地址值）
int main()
{

    int num = 10;
    int *p = &num;

    // 定义一个二级指针
    int **q = &p;

    cout << num << endl;
    cout << p << endl;
    cout << q << endl;

    cout << *p << endl;
    cout << *q << endl;

    cout << **q << endl;

    return 0;
}