#include <iostream>
#include <cstring>
using namespace std;

class Circle
{
private:
    float radius;

public:
    Circle(float a) : radius(a) {}
    float GetArea()
    {
        return 3.14 * radius * radius;
    }
};
class Table
{
private:
    float high;

public:
    Table(float a) : high(a) {}
    float GetHigh()
    {
        return high;
    }
};
// 多重继承写法
class RoundTable : public Circle, public Table
{
private:
    char color[20];

public:
    RoundTable(float a, float b, char *c) : Circle(a), Table(b)
    {
        if (c)
            strcpy(this->color, c);
    }
    char *GetColor()
    {
        return color;
    }
};

int main()
{
    float radius, high;
    char color[20];
    cin >> radius >> high >> color;
    RoundTable RT(radius, high, color);
    cout << "Area:" << RT.GetArea() << endl;
    cout << "High:" << RT.GetHigh() << endl;
    cout << "Color:" << RT.GetColor() << endl;
    return 0;
}