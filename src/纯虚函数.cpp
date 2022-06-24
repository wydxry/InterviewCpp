#include <iostream>
using namespace std;

// 基类
class A {
public:
    A();
    virtual ~A();
    void f1() {
        cout << "A: f1()" << endl;
    }
    virtual void f2() {
        cout << "A: f2()" << endl;
    }
    virtual void f3()=0;
};

A::A() {
    cout << "A::A()" << endl;
}

A::~A() {
    cout << "A::~A()" << endl;
}

// 子类/派生类
class B: public A{
public:
    B();
    virtual ~B();
    void f1() {
        cout << "B: f1()" << endl;
    }
    virtual void f2() {
        cout << "B: f2()" << endl;
    }
    virtual void f3() {
        cout << "B: f3()" << endl;
    }
};

B::B() {
    cout << "B::B()" << endl;
}
B::~B() {
    cout << "B::~B()" << endl;
}

int main(int argc, char const *argv[])
{
    A *a = new B();
    a->f1();
    a->f2();
    a->f3();
    
    delete(a);

    return 0;
}
