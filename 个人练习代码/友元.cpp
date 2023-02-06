#include <iostream>
using namespace std;

class student
{
private:
    int pos, score;

public:
    student(int x, int y) : pos(x), score(y) {}
    friend void show(student s); // 友元函数
    friend class teacher;
};

class teacher
{
public:
    void show(student s) { cout << s.pos << " " << s.score << endl; }
};
void show(student s) { cout << s.pos << " " << s.score << endl; }

int main()
{
    student A(1, 99);
    show(A);
    teacher B;
    B.show(A);
    return 0;
}
