#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    // 声明指针变量
	char* ch_ptr;
	short* s_ptr;
	int* i_ptr;
	double* d_ptr;

    cout << sizeof(ch_ptr) << endl;
	cout << sizeof(s_ptr) << endl;
	cout << sizeof(i_ptr) << endl;
	cout << sizeof(d_ptr) << endl;

	// 指针变量的初始化
	int num = 50;
	int* p = &num;

	cout << p << endl;
	cout << &num << endl;
    cout << *p << endl;

    return 0;
}
