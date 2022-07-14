#include <iostream>
using namespace std;

// #pragma pack(show) // 默认的对齐模数是8
#pragma pack(1)

/*
    内存对齐的规则：
        1.第一个成员必须是从0位置开始偏移
        2.下面的成员从   成员的大小和对齐模数相比 取小的整数倍的的地方
        3.最后要对结构体整体进行对齐：成员中最大的那一个和对齐模数相比 取小的整数倍
*/
typedef struct _STUDENT
{
    int a;    // 0 ~ 3
    char b;   // 4 ~ 7
    double c; // 8 ~ 15
    float d;  // 16 ~ 23
} Student;

typedef struct _STUDENT2
{
    char a;    // 0 ~ 7
    Student b; // 8 ~ 31
    double c;  // 32 ~ 39
} Student2;

int main()
{
    cout << sizeof(Student) << endl;

    cout << sizeof(Student2) << endl;

    return 0;
}