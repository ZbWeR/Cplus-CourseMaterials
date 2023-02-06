#include <iostream>
#include <cstring>
using namespace std;

class student
{
private:
    int number;
    double score;
    int *p;

public:
    // 构造函数的重载
    student() {}
    student(int number, double score = 0.0)
    {
        this->number = number;
        this->score = score;
        p = new int(202200 + number);
    }
    // 等价于上面的构造函数,较为简便的写法
    // student(int x, double y = 0.0) : number(x), score(y),p(new int(202200+number)) {}
    // 拷贝构造函数,利用已有对象对新建对象初始化
    student(const student &x) : number(x.number), score(x.score)
    {
        cout << "construct\n";
        p = new int(*x.p); // 深拷贝,开辟新空间存放已有对象中指针的具体值
    }
    // 析构函数,释放内存
    ~student() { delete p; }
    void show() { cout << *p << " " << score << endl; }
};

int main()
{
    student A(1, 66.7);
    A.show();
    student B(A);
    A.~student();
    B.show();
    return 0;
}