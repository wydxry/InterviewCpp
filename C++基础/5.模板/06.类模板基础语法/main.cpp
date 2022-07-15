#include <iostream>
#include <string>
using namespace std;

// 模板中，可以使用默认参数
template <class NAMETYPE, class AGETYPE = int>
class Person
{
public:
    Person(NAMETYPE name, AGETYPE age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson()
    {
        cout << "姓名：" << this->m_Name << " 年龄：" << this->m_Age << endl;
    }

    NAMETYPE m_Name;
    AGETYPE m_Age;
};

int main()
{

    // Person p1("Tom", 20);	// 使用类模板不能自动类型推导，只能显示指定类型
    Person<string, int> p1("Tom", 20);
    p1.showPerson();

    return 0;
}