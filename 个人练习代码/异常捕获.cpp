#include <iostream>
using namespace std;

int main()
{
    int index, dividend, divisor, result;
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    try
    {
        cin >> index >> divisor;

        if (index < 0 || index > 9)
            throw index;

        if (divisor == 0)
            throw divisor;

        dividend = array[index];
        result = dividend / divisor;
        cout << result << endl;
    }
    catch (int x)
    {
        if (x == 0)
            cout << "divide by 0";
        else
            cout << x << " out of bound\n";
    }

    return 0;
}
