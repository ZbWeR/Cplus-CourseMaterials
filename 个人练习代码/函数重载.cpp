#include <iostream>
#include <cstdio>
using namespace std;

int add(int x, int y)
{
    return x + y;
}
int add(int x, int y, int z)
{
    return x + y + z;
}
int add(double x, double y)
{
    return x + y;
}
/*
返回类型不同,其他都相同的函数无法重载.
double add(int x,int y){
    return x+y;
}
*/

int main()
{
    cout << add(1, 2) << endl;
    cout << add(1, 2, 3) << endl;
    cout << add(1.5, 2.1);
    return 0;
}