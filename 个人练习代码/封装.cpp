#include <iostream>
#include <cstring>
using namespace std;

class dog
{
private:
    /* 私有成员，“别人”不能碰狗的尾巴 */
    char tail[10];

public:
    // 构造函数:初始化tail数组
    dog() { strcpy(tail, "wang~~~wang!"); }
    // 析构函数:释放动态申请的内存
    ~dog() {}
    /* 公有成员wag，“别人”可以叫狗摇尾巴 */
    void wag() { cout << tail; }
};

int main()
{
    dog A;
    // cout<<A.tail;  error:不可访问
    A.wag();
    return 0;
}