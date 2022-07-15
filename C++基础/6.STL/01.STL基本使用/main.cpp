#include <iostream>
#include <vector>    // 单端数组
#include <algorithm> // 标准算法头文件
using namespace std;

void myPrint(int val)
{
    cout << val << endl;
}

void test01()
{
    vector<int> v; // 创建了一个vector容器

    // 插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    // 第一种遍历方式
    // 利用迭代器遍历容器中的数据
    // v.begin() 起始迭代器 指向容器中的第一个元素
    vector<int>::iterator itBegin = v.begin();
    // v.end() 结束迭代器	指向容器中最后一个元素的下一个位置
    vector<int>::iterator itEnd = v.end();

    /*while (itBegin != itEnd) {
        cout << *itBegin << endl;
        itBegin++;
    }*/

    // 第二种方式
    // for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    //	cout << *it << endl;
    //}

    // 第三种方式
    for_each(v.begin(), v.end(), myPrint);
}

// 自定义数据类型
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

void test02()
{
    vector<Person> v;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "姓名：" << (*it).m_Name << " 年龄：" << it->m_Age << endl;
    }
}

void test03()
{
    vector<Person*> v;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);

    for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "姓名：" << (*it)->m_Name << " 年龄：" << (*it)->m_Age << endl;
    }
}

// 容器的嵌套
void test04()
{
    vector<vector<int>> v;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;

    for (int i = 0; i < 5; i++)
    {
        v1.push_back(i + 1);
        v2.push_back(i + 10);
        v3.push_back(i + 100);
    }

    // 将小容器插入到大容器中
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    // 遍历
    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        // *it  vector<int>
        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
        {
            cout << *vit << " ";
        }
        cout << endl;
    }
}

int main()
{
    test01();
    cout << "================" << endl;
    test02();
    cout << "================" << endl;
    test03();
    cout << "================" << endl;
    test04();

    return 0;
}