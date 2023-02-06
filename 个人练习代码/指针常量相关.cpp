#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int x = 0, y = 0;
    int *const p1 = &x;
    // p1是指针常量,确定后不能更改指向的地址,可以修改具体值
    // p1 = &y; 报错
    // *p1 = 9; 可以执行,同时修改了x的值
    int const *p2 = &x;
    // p2是指向常量的指针,不能修改它具体的值,可以修改地址
    // p2 = &y;
    // *p2 = 9;
    int const *const p3 = &x;
    // p3是指向常量的指针常量,不能动也不能改.
    cout << x << " " << y;
    return 0;
}