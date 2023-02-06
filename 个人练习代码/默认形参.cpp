#include <iostream>
#include <cstdio>
using namespace std;

void Register(int number, char const *name, int age = 18, char const *country = "China")
{
    cout << "Number: " << number << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Country: " << country << endl;
}
void Register(int number, char const *name)
{
    cout << "###";
    cout << "Number: " << number << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << 18 << endl;
    cout << "Country: China " << endl;
}

int main()
{
    // Register(1, "ZhangSan"); /* error */
    // 调用的都是第一个register
    Register(2, "WangWu", 20);
    Register(3, "Tom", 18, "England");
    return 0;
}
