#include <iostream>
#include <string>
using namespace std;

// void * (无类型指针)
int main()
{

    // int num = 10;
    // void num = 10;	// 注意：不允许使用void定义普通变量。

    // void *p;

    int num = 100;
    int *p = &num;
    p = &num;

    // 对于void*指针变量，不要解除引用操作
    // cout << *p << endl;

    // 如果想要通过指针变量p获取num的值，需要进行强制类型转换
    int *p_num = (int *)p;
    cout << *p_num << endl;

    // 1.void* 可以保存任意类型的地址。（万能指针）。
    // 2.主要作为函数的参数

    return 0;
}