#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    vector<int> v;
    cout << "初始容量：" << v.capacity() << endl;

    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
        cout << v.capacity() << endl; // v.capacity()获取容器的容量
    }
}

void test02()
{
    vector<int> v;           // 默认构造
    vector<int> v1(10, 100); // 10 个100
    printVector(v1);

    vector<int> v2(v1.begin(), v1.end());
    printVector(v2);

    vector<int> v3(v2);
    printVector(v3);
}

void test03()
{
    int arr[] = {2, 3, 4, 1, 9};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(int));

    vector<int> v1 = v;
    printVector(v1);

    vector<int> v2;
    v2.assign(v1.begin() + 1, v1.end());
    printVector(v2);

    vector<int> v3(10, 100);

    // v2 和 v3的内容进行互换
    v3.swap(v2);
    printVector(v2);
    printVector(v3);
}

void test04()
{
    int arr[] = {2, 3, 4, 1, 9};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
    if (v.empty())
    {
        cout << "v为空" << endl;
    }
    else
    {
        cout << "v不为空" << endl;
        cout << "size = " << v.size() << endl;
    }

    printVector(v);

    // v.resize(3);
    // v.resize(7);
    v.resize(7, 100);

    printVector(v);

    cout << v.at(2) << endl;
    cout << v[2] << endl;

    cout << "第一个元素为：" << v.front() << endl;
    cout << "最后一个元素为：" << v.back() << endl;
}

void test05()
{
    int arr[] = {2, 3, 4, 1, 9};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(int));

    v.insert(v.begin(), 100);     // 100 2 3 4 1 9
    v.insert(v.begin(), 2, 1000); // 1000 1000 100 2 3 4 1 9
    printVector(v);

    v.push_back(33); // 1000 1000 100 2 3 4 1 9 33
    printVector(v);

    v.pop_back();
    printVector(v); // 1000 1000 100 2 3 4 1 9

    v.erase(v.begin());
    printVector(v); // 1000 100 2 3 4 1 9

    v.clear();
    printVector(v);
}

int main()
{
    test01();
    test02();
    test03();
    test04();
    test05();
    return 0;
}