#include <iostream>
using namespace std;

template <class T>
void Swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}
template <class X>
X Max(X a, X b)
{
    if (a > b)
        return a;
    return b;
}
template <class Type>
Type get_sum(Type *x, int len)
{
    Type Sum = 0;
    for (int i = 0; i < len; i++)
        Sum += x[i];
    return Sum;
}

int main()
{
    int arr_int[6] = {1, 2, 3, 4, 5, 6};
    double arr_double[6] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
    cout << get_sum(arr_int, 6) << endl;
    cout << get_sum(arr_double, 6) << endl;

    return 0;
}