#include <iostream>
using namespace std;

class foo
{
private:
    int pos;

public:
    foo(int x) : pos(x) {}
    foo(const foo &A) : pos(A.pos) {}
    void show() { cout << pos << endl; }
};

int main()
{
    foo A = foo(9);
    // foo A = {9};等价于上式
    foo B = foo(A);
    A.show();
    B.show();
    // 数组的初始化.
    foo C[3] = {{1}, {2}, {3}};
    for (int i = 0; i < 3; i++)
        C[i].show();

    return 0;
}