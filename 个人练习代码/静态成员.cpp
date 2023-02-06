#include <iostream>
using namespace std;

class foo
{
private: // 变量在类的内部定义
    static char name[30];
    int pos;

public: //
    foo() {}
    foo(int x) : pos(x) {}
    // 报错: 静态成员函数不能访问非静态成员变量
    // static void show() { cout << name << " " << pos < endl; }
    static void show() { cout << name << endl; }
};
// 变量在类的外部声明
char foo::name[30] = "Class foo";
int main()
{
    foo A(2333); // name 属于foo这个类,而不是属于A这个对象.
    A.show();
    foo::show(); // 可以直接通过类名加运算符调用函数,而不用创建一个对象
    return 0;
}