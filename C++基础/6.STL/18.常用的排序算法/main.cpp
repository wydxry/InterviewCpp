#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <ctime>
using namespace std;

void test01()
{
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 1);
    }
    vector<int> vt; // 目标容器
    vt.resize(v1.size() + v2.size());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vt.begin());

    // lambda表达式 [](){} 匿名函数
    for_each(vt.begin(), vt.end(), [](int val)
             { cout << val << " "; });
    cout << endl;
}

void test02()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    sort(v.begin(), v.end(), greater<int>());

    for_each(v.begin(), v.end(), [](int val)
             { cout << val << " "; });
    cout << endl;
}

void test03()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), [](int val)
             { cout << val << " "; });
    cout << endl;
}

void test04()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    v.push_back(100);
    v.push_back(50);
    cout << "反转前遍历的结果：" << endl;
    for_each(v.begin(), v.end(), [](int val)
             { cout << val << " "; });
    cout << endl;

    reverse(v.begin(), v.end());
    cout << "反转后遍历的结果：" << endl;
    for_each(v.begin(), v.end(), [](int val)
             { cout << val << " "; });
    cout << endl;
}

// 常用的排序算法
int main()
{
    // 随机数种子
    srand((unsigned int)time(NULL));
    test01();
    cout << "============================" << endl;
    test02();
    cout << "============================" << endl;
    test03();
    cout << "============================" << endl;
    test04();
    return 0;
}
