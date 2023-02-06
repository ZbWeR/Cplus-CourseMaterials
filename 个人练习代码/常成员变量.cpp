#include <iostream>
using namespace std;

class foo
{
private:
    const int x;
    // foo(int num) { x = num; } // error: x不允许修改
    foo(int num) : x(num) {}
};