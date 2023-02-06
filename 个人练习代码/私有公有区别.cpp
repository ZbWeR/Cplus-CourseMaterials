#include <bits/stdc++.h>
using namespace std;

class student
{
private:
    char name[10];

public:
    int number;
    int score;

    student()
    {
        strcpy(name, "none");
        number = -1;
        score = -1;
    }
    student(char const *text)
    {
        strcpy(name, text);
        number = 0;
        score = 0;
    }
    student(char const *text, int n, int s)
    {
        strcpy(name, text);
        number = n;
        score = s;
    }

    void display()
    {
        cout << name << " " << number << " " << score << endl;
    }
};
int main()
{
    student a("zbwer", 2, 3);
    a.display();
    double n;
    scanf("%lf", &n);
    if (n > 0)
        printf("+%10.4lf", n);
    // cout << a.name; private不允许外部访问;
    // a.display(); 只能内部访问
    return 0;
}