#include <iostream>
using namespace std;

class tmpObj
{
public:
    int x;
    tmpObj() {}
    tmpObj(int x) : x(x) {}
};

class Obj_
{
public:
    int x;
    Obj_() {}
    Obj_(int x) : x(x) {}
    void Print(tmpObj A)
    {
        cout << A.x;
    }
};

int main()
{
    tmpObj A(2333);
    Obj_ B(1);
    B.Print(A);

    return 0;
}