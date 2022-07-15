#include <iostream>
using namespace std;

class Person
{

    friend ostream &operator<<(ostream &out, Person &p);

public:
    Person(int a, int b)
    {
        this->m_A = a;
        this->m_B = b;
    }

private:
    int m_A;
    int m_B;
};

ostream &operator<<(ostream &out, Person &p)
{
    out << "m_A : " << p.m_A << " , m_B : " << p.m_B;
    return out;
}

int main()
{

    Person p(10, 20);
    // operator<<(cout, p);
    cout << p << endl; 

    return 0;
}