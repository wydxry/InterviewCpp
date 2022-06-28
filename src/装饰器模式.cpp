#include <string>
#include <iostream>

//基础组件接口定义了可以被装饰器修改的操作
class Component
{
public:
    virtual ~Component() {}
    virtual std::string Operation() const = 0;
};

//具体组件提供了操作的默认实现。这些类在程序中可能会有几个变体
class ConcreteComponent : public Component
{
public:
    std::string Operation() const override
    {
        return "ConcreteComponent";
    }
};

//装饰器基类和其他组件遵循相同的接口。这个类的主要目的是为所有的具体装饰器定义封装接口。
//封装的默认实现代码中可能会包含一个保存被封装组件的成员变量，并且负责对齐进行初始化
class Decorator : public Component
{

protected:
    Component *component_;

public:
    Decorator(Component *component) : component_(component)
    {
    }

    //装饰器会将所有的工作分派给被封装的组件
    std::string Operation() const override
    {
        return this->component_->Operation();
    }
};

//具体装饰器必须在被封装对象上调用方法，不过也可以自行在结果中添加一些内容。
class ConcreteDecoratorA : public Decorator
{

    //装饰器可以调用父类的是实现，来替代直接调用组件方法。
public:
    ConcreteDecoratorA(Component *component) : Decorator(component)
    {
    }
    std::string Operation() const override
    {
        return "ConcreteDecoratorA(" + Decorator::Operation() + ")";
    }
};

//装饰器可以在调用封装的组件对象的方法前后执行自己的方法
class ConcreteDecoratorB : public Decorator
{
public:
    ConcreteDecoratorB(Component *component) : Decorator(component)
    {
    }

    std::string Operation() const override
    {
        return "ConcreteDecoratorB(" + Decorator::Operation() + ")";
    }
};

//客户端代码可以使用组件接口来操作所有的具体对象。这种方式可以使客户端和具体的实现类脱耦
void ClientCode(Component *component)
{
    // ...
    std::cout << "RESULT: " << component->Operation();
    // ...
}

int main()
{

    Component *simple = new ConcreteComponent;
    std::cout << "Client: I've got a simple component:\n";
    ClientCode(simple);
    std::cout << "\n\n";

    Component *decorator1 = new ConcreteDecoratorA(simple);
    Component *decorator2 = new ConcreteDecoratorB(decorator1);
    std::cout << "Client: Now I've got a decorated component:\n";
    ClientCode(decorator2);
    std::cout << "\n";

    delete simple;
    delete decorator1;
    delete decorator2;

    return 0;
}

