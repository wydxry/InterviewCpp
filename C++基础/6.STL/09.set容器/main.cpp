#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

void printSet(set<int> &s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    set<int> s;
    s.insert(10);
    s.insert(40);
    s.insert(40);
    s.insert(30);
    s.insert(12);
    s.insert(5);

    printSet(s);

    cout << "size : " << s.size() << endl;
}

// 查找，统计
void test02()
{
    set<int> s;
    s.insert(10);
    s.insert(40);
    s.insert(40);
    s.insert(30);
    s.insert(12);
    s.insert(40);
    s.insert(5);

    set<int>::iterator pos = s.find(300);
    if (pos != s.end())
    {
        cout << "找到了元素：" << *pos << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }

    // 对于set来说，count的返回值要么是0，要么是1
    int num = s.count(40);
    cout << "40的元素的个数为：" << num << endl;

    // lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
    set<int>::iterator ret = s.lower_bound(30);
    if (ret != s.end())
    {
        cout << "找到了lower_bound的值为：" << *ret << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }

    // upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
    ret = s.upper_bound(30);
    if (ret != s.end())
    {
        cout << "找到了upper_bound的值为：" << *ret << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }

    // equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
    pair<set<int>::iterator, set<int>::iterator> ret2 = s.equal_range(30);
    if (ret2.first != s.end())
    {
        cout << "找到了lower_bound的值为：" << *ret2.first << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }

    if (ret2.second != s.end())
    {
        cout << "找到了upper_bound的值为：" << *ret2.second << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }
}

// 对组的创建
void test03()
{
    pair<string, int> p1("Tom", 18);
    cout << "姓名：" << p1.first << endl;
    cout << "年龄：" << p1.second << endl;

    pair<string, int> p2 = make_pair("Jerry", 20);
    cout << "姓名：" << p2.first << endl;
    cout << "年龄：" << p2.second << endl;
}

class myCompare
{
public:
    bool operator()(int v1, int v2) const
    {
        return v1 > v2;
    }
};

void test04()
{

    // 通过仿函数，改变set容器的排序规则
    set<int, myCompare> s;

    s.insert(10);
    s.insert(30);
    s.insert(40);
    s.insert(20);
    s.insert(50);

    for (set<int, myCompare>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // set<int>::iterator it = s.begin();
    // it = it + 1;
    // sort()
}

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

class myComparePerson
{
public:
    bool operator()(const Person &p1, const Person &p2) const
    {
        return p1.m_Age > p2.m_Age;
    }
};

void test05()
{
    set<Person, myComparePerson> s;

    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 50);
    Person p4("ddd", 30);
    Person p5("eee", 15);

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);
    s.insert(p5);

    for (set<Person, myComparePerson>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << "姓名：" << (*it).m_Name << " 年龄：" << (*it).m_Age << endl;
    }
}

// set容器
int main()
{
    test01();
    cout << "============================" << endl;
    test02();
    cout << "============================" << endl;
    test03();
    cout << "============================" << endl;
    test04();
    cout << "============================" << endl;
    test05();
    return 0;
}