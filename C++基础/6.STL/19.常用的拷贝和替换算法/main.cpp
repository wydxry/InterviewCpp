#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
using namespace std;

void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int> v1;
    v1.resize(v.size());

    copy(v.begin(), v.end(), v1.begin());
    for_each(v1.begin(), v1.end(), [](int val)
             { cout << val << " "; });
    cout << endl;

    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

class RepalceIf
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};

void test02()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    // 将容器中的3替换成300
    replace(v.begin(), v.end(), 3, 300);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // 将所有大于5的值，替换成2000
    replace_if(v.begin(), v.end(), RepalceIf(), 2000);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void test03()
{

    vector<int> v;
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
        v1.push_back(i + 10);
    }

    cout << "交换前数据：" << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    swap(v, v1);

    cout << "交换后数据：" << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    test01();
    cout << "============================" << endl;
    test02();
    cout << "============================" << endl;
    test03();
    cout << "============================" << endl;
    return 0;
}