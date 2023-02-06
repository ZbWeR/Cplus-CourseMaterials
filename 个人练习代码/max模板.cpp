#include <iostream>
using namespace std;

template <class T>
T get_max(T *nums, int len)
{
    T tmp = -1;
    for (int i = 0; i < len; i++)
        tmp = tmp > nums[i] ? tmp : nums[i];
    return tmp;
}
template <class T>
T get_min(T nums[], int len)
{
    T tmp = 0x7fffffff;
    for (int i = 0; i < len; i++)
        tmp = tmp < nums[i] ? tmp : nums[i];
    return tmp;
}

int main()
{
    int arr_int[6] = {1, 2, 3, 4, 5, 6};
    double arr_double[6] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
    cout << get_max(arr_int, 6) << endl;
    cout << get_max(arr_double, 6) << endl;
    return 0;
}