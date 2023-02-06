#include <bits/stdc++.h>
using namespace std;
/*
引用: (变量的别名)
    必须在定义时初始化,且不能更改,只能引用一级,不能为空
1. 作为参数
    类似指针传参
2. 作为返回值
3. 常引用不可修改
*/

void Swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int allUseCan[] = {1, 2, 3, 4, 5, 6};

int &setValue(int i)
{
    return allUseCan[i];
}

int main()
{
    int ZhangBoWen = 2333;
    int &zbw = ZhangBoWen;
    const int &zbwer = ZhangBoWen;
    printf("ZhangBoWen is %d\n", ZhangBoWen);
    printf("zbw is %d\n", zbw);
    printf("#######################\n");
    int x = 2, y = 3;
    printf("Before: x=%d y=%d\n", x, y);
    Swap(x, y);
    printf("After : x=%d y=%d\n", x, y);
    printf("#######################\n");
    for (int i = 0; i < 6; i++)
        printf("%d ", allUseCan[i]);
    putchar('\n');
    setValue(0) = 2333;
    setValue(1) = 666;
    for (int i = 0; i < 6; i++)
        printf("%d ", allUseCan[i]);
    // zbwer = 2; 修改常引用: 报错
    return 0;
}