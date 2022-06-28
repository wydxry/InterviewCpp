#include <iostream>
#include <list>
#include <string>
using namespace std;

//观察者
class Observer
{
public:
    Observer() {}
    virtual ~Observer() {}
    virtual void Update() {}
};

//博客
class Blog
{
public:
    Blog() {}
    virtual ~Blog() {}
    void Attach(Observer *observer)
    {
        //添加观察者
        m_observers.push_back(observer);
    }
    void Remove(Observer *observer)
    {
        //移除观察者
        m_observers.remove(observer);
    }

    //通知观察者
    void Notify()
    {
        list<Observer *>::iterator iter = m_observers.begin();
        for (; iter != m_observers.end(); iter++)
        {
            (*iter)->Update();
        }
    }

    //设置状态
    virtual void SetStatus(string s)
    {
        m_status = s;
    }

    //获得状态
    virtual string GetStatus()
    {
        return m_status;
    }

private:
    //观察者链表
    list<Observer *> m_observers;

protected:
    //状态
    string m_status;
};

//具体博客类
class BlogCSDN : public Blog
{
private:
    string m_name; //博主名称
public:
    BlogCSDN(string name) : m_name(name) {}
    ~BlogCSDN() {}

    //具体设置状态信息
    void SetStatus(string s)
    {
        m_status = "CSDN通知 : " + m_name + s;
    }
    string GetStatus()
    {
        return m_status;
    }
};

//具体观察者
class ObserverBlog : public Observer
{
private:
    string m_name; //观察者名称
    Blog *m_blog;  //观察的博客，当然以链表形式更好，就可以观察多个博客
public:
    ObserverBlog(string name, Blog *blog) : m_name(name), m_blog(blog) {}
    ~ObserverBlog() {}
    void Update() //获得更新状态
    {
        string status = m_blog->GetStatus();
        cout << m_name << "-------" << status << endl;
    }
};

int main()
{
    Blog *blog = new BlogCSDN("wydxry");
    Observer *observer = new ObserverBlog("Celees", blog);

    blog->Attach(observer);
    blog->SetStatus("发表设计模式C++实现（15）——观察者模式");
    blog->Notify();

    delete blog;
    delete observer;

    return 0;
}