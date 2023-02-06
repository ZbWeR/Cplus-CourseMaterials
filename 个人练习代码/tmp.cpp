#include <iostream>
#include <cstdio>
using namespace std;

template <typename T>
T add(T a, T b)
{
    return a + b;
}

int main()
{
    int a = 1, b = 2;
    cout << add(a, b) << "\n";
    double c = 1.1, d = 2.2;
    cout << add(c, d);

    return 0;
}