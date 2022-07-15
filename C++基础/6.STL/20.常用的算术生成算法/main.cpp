#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;

void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    int sum = accumulate(v.begin(), v.end(), 1000);
    cout << sum << endl;
}

void test02()
{
    vector<int> v;
    v.resize(10);
    for_each(v.begin(), v.end(), [](int val)
             { cout << val << " "; });
    cout << endl;

    fill(v.begin(), v.end(), 100);
    for_each(v.begin(), v.end(), [](int val)
             { cout << val << " "; });
    cout << endl;
}

int main()
{
    test01();
    cout << "============================" << endl;
    test02();
    cout << "============================" << endl;
    return 0;
}