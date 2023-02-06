#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    // C语言内存分配
    int *a = (int *)malloc(sizeof(int));
    free(a);
    // C++内存分配
    int *b = new int(123); // 分配一个变量并初始化为123
    cout << *b << endl;
    delete b;
    int *c = new int[5]{1, 2, 3, 4, 5}; // 分配一个数组并初始化
    cout << *c;
    delete c;
    return 0;
}