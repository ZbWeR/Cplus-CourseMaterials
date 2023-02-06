#include <iostream>
using namespace std;

class A
{
public:
    A() { cout << "A create" << endl; }
    ~A() { cout << "A destruct" << endl; }
};
class B : virtual public A
{
public:
    B() { cout << "B create" << endl; }
    ~B() { cout << "B destruct" << endl; }
};
class C : virtual public A
{
public:
    C() { cout << "C create" << endl; }
    ~C() { cout << "C destruct" << endl; }
};
class D : public B, public C
{
public:
    D() { cout << "D" << endl; }
    ~D() { cout << "D end" << endl; }
};
int main()
{
    D x;
    return 0;
}