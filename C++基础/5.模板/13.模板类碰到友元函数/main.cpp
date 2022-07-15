#include <iostream>
using namespace std;

// 友元函数类内实现
// template<class T1, class T2>
// class Person {
//
//	friend void printPerson(Person<T1, T2>& p) {
//		cout << "姓名：" << p.m_Name << " 年龄：" << p.m_Age << endl;
//	}
//
// public:
//	Person(T1 name, T2 age) {
//		this->m_Name = name;
//		this->m_Age = age;
//	}
//
// private:
//	T1 m_Name;
//	T2 m_Age;
//};

// 先让编译器看到Person类的声明
template <class T1, class T2>
class Person;

// 先让编译器看到函数模板 printPerson的存在
template <class T1, class T2>
void printPerson(Person<T1, T2> &p);

// 函数模板
template <class T1, class T2>
void printPerson2(Person<T1, T2> &p)
{
    cout << "姓名：" << p.m_Name << " 年龄：" << p.m_Age << endl;
}

// 友元函数类外实现
template <class T1, class T2>
class Person
{

    // friend void printPerson(Person<T1, T2>& p);是函数
    friend void printPerson<>(Person<T1, T2> &p); // 模板
    friend void printPerson2<>(Person<T1, T2> &p);

public:
    Person(T1 name, T2 age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

private:
    T1 m_Name;
    T2 m_Age;
};

// 函数模板
template <class T1, class T2>
void printPerson(Person<T1, T2> &p)
{
    cout << "姓名：" << p.m_Name << " 年龄：" << p.m_Age << endl;
}

// 类模板碰到友元函数的情况
int main()
{
    Person<string, int> p("Tom", 21);
    printPerson(p);
    printPerson2(p);
    
    return 0;
}