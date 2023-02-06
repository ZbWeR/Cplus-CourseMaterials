#include <iostream>
using namespace std;

int id = 0;
class foo
{
public:
    // 方法一:
    static foo &CreatFoo()
    {
        static foo instance;
        return instance;
    }
    // 方法二: 借助静态成员变量 *vip
    static foo *CreateFoo2()
    {
        if (vip == nullptr)
            vip = new foo();
        else
            cout << "only one\n";
        return vip;
    }
    void show() { cout << pos << endl; }

private:
    int pos;
    static foo *vip;
    foo() : pos(++id) {}
    ~foo() {}
    foo(const foo &);
};
foo *foo::vip = nullptr;

int main()
{
    foo &A = foo::CreatFoo();
    A.show();
    foo &B = foo::CreatFoo();
    B.show();
    // foo *C = foo::CreateFoo2();C->show();
    // foo *D = foo::CreateFoo2();D->show();
    return 0;
}