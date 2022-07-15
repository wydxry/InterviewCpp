#include <iostream>
#include <vector>
using namespace std;

// 构造
void test01()
{
    string str1;
    string str2 = str1;
    // string str2(str1);
    string str3 = "abcd";
    // string str3("abcd");
    string str4(5, 'a');

    cout << "str3 = " << str3 << endl;
    cout << "str4 = " << str4 << endl;

    // 赋值
    string str5;
    str5.assign("abcdefghi", 6);
    cout << "str5 = " << str5 << endl; // abcdef

    // string& assign(const string & s, int start, int n);//将s从start开始n个字符赋值给字符串
    string str6;
    str6.assign(str5, 1, 3); // bcd
    cout << "str6 = " << str6 << endl;
}

/*
char& operator[](int n);//通过[]方式取字符
char& at(int n);//通过at方法获取字符
*/
void test02()
{
    string str = "hello world";

    // for (int i = 0; i < str.size(); i++) {
    //	// cout << str[i] << endl;
    //	cout << str.at(i) << endl;
    // }

    // [] 和 at 区别：[]访问越界，程序直接终止，at访问越界，抛出异常 out_of_range
    // cout << str[100] << endl;
    try
    {
        cout << str.at(100) << endl;
    }
    catch (out_of_range e)
    {
        cout << e.what() << endl;
    }
}

void test03()
{
    string s1 = "hello";
    s1 += " world";
    cout << s1 << endl;

    string s2 = "nihao";
    s1.append(s2);
    cout << s1 << endl;

    s1.append(3, 'a');
    cout << s1 << endl;

    s1.append(s2, 2, 3);
    cout << s1 << endl;
}

void test04()
{

    string str = "abcdefghde";

    int pos = str.find("de", 4); // 参数2 代表起始查找的位置，默认0
    // find是从左往右查找，rfind是从右往左查找
    if (pos == -1)
    {
        cout << "未找到子串" << endl;
    }
    else
    {
        cout << "找到了子串，位置：" << pos << endl;
    }

    // 替换
    str.replace(1, 3, "1111");
    cout << str << endl;
}

void test05()
{

    string str1 = "abcde";
    string str2 = "Abcdef";
    int ret = str1.compare(str2);

    if (ret == 0)
    {
        cout << "str1 == str2" << endl;
    }
    else if (ret == 1)
    {
        cout << "str1 > str2" << endl;
    }
    else if (ret == -1)
    {
        cout << "str1 < str2" << endl;
    }
}

// string substr(int pos = 0, int n = npos) const;//返回由pos开始的n个字符组成的字符串
void test06()
{

    string str = "abcdefg";
    string subStr = str.substr(2, 3);
    cout << subStr << endl;

    string email = "wydxry@163.com";

    // 获取@的索引
    int pos = email.find("@"); // pos = 7

    string userName = email.substr(0, pos);
    cout << userName << endl;
}

// 提升
void test07()
{
    string str = "test";
    vector<string> v;

    int pos = -1;
    int start = 0;
    while (true)
    {
        pos = str.find(".", start);
        if (pos == -1)
        {
            string subStr = str.substr(start, str.size() - start);
            v.push_back(subStr);
            break;
        }

        string subStr = str.substr(start, pos - start);
        v.push_back(subStr);
        start = pos + 1;
    }

    for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
}

void test08()
{
    // 插入
    string str = "hello";
    str.insert(2, "22");
    cout << str << endl; // he22llo

    // 删除
    str.erase(2, 2);
    cout << "===" << str << "===" << endl;
}

void dowork(const char *str)
{
}
void dowork1(string str)
{ // string str = "hello";
}

// string 和 c-style 字符串转换
void test09()
{
    const char *str = "hello";
    // const char * 转换成string
    string str2(str); // string str2 = string(str);
    string str3 = "hello";

    // string 转 const char *
    const char *s = str2.c_str();

    // dowork(str2);
    dowork(str2.c_str());

    dowork1(str);
}

// 大小写转换
void test10()
{
    string str = "abcDEfG";
    for (int i = 0; i < str.size(); i++)
    {
        // str[i] = toupper(str[i]);
        str[i] = tolower(str[i]);
    }
    cout << str << endl;
}

// 字符串重新分配内存后，再使用原来的引用可能会发生错误
void test11()
{

    string s = "abcdefg";
    char &a = s[2];
    char &b = s[3];
    a = '1';
    b = '2';
    cout << s << endl;
    cout << (int *)s.c_str() << endl;

    s = "pppppppppppppppppppp";

    // a 和 b 不能再使用了
    // a = '1';
    // b = '2';
    cout << s << endl;
    cout << (int *)s.c_str() << endl;
}

int main()
{
    test01();
    test02();
    test03();
    test04();
    test05();
    test06();
    test07();
    test08();
    test09();
    test10();
    test11();
    return 0;
}