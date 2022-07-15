#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

void test01()
{
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 5);
    }
    vector<int> vt;
    vt.resize(min(v1.size(), v2.size()));

    // 交集
    vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vt.begin());

    for_each(vt.begin(), itEnd, [](int val)
             { cout << val << " "; });
    cout << endl;
}

void test02()
{
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 5);
    }
    vector<int> vt;
    vt.resize(v1.size() + v2.size());

    // 并集
    vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vt.begin());

    for_each(vt.begin(), itEnd, [](int val)
             { cout << val << " "; });
    cout << endl;
}

void test03()
{
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 5);
    }
    vector<int> vt;
    vt.resize(max(v1.size(), v2.size()));

    // v1 和 v2差集
    vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vt.begin());

    for_each(vt.begin(), itEnd, [](int val)
             { cout << val << " "; });
    cout << endl;

    vector<int> vt1;
    vt1.resize(max(v1.size(), v2.size()));

    // v2 和 v1差集
    vector<int>::iterator itEnd1 = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vt1.begin());
    for_each(vt1.begin(), itEnd1, [](int val)
             { cout << val << " "; });
    cout << endl;
}

// 常见的集合算法
int main()
{
    test01();
    cout << "============================" << endl;
    test02();
    cout << "============================" << endl;
    test03();
    return 0;
}
