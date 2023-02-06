// #include "CSet.h"
#include <iostream>
using namespace std;
class Set
{
private:
    int n;
    int *pS; //集合元素
public:
    Set()
    {
        n = 0;
        pS = NULL;
    }
    Set(Set &s)
    {
        n = s.n;
        if (n != 0)
        {
            pS = new int[n + 1];
            for (int i = 1; i <= n; i++) //集合的下标从1开始，集合中不能有重复元素
                pS[i] = s.pS[i];
        }
    }
    ~Set()
    {
        if (pS)
        {
            delete[] pS;
            pS = NULL;
            n = 0;
        }
    }
    void ShowElement() const
    { //输出集合的元素
        int temp = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (pS[i] > pS[j])
                {
                    temp = pS[i];
                    pS[i] = pS[j];
                    pS[j] = temp;
                }
            }
        }
        cout << "{";
        for (int i = 1; i < n; i++)
            cout << pS[i] << ",";
        if (IsEmpty())
            cout << "}" << endl;
        else
            cout << pS[n] << "}" << endl;
    }
    bool IsEmpty() const { return n ? false : true; } //判断集合是否为空
    int size() { return n; }
    bool IsElement(int e) const
    {
        for (int i = 1; i <= n; i++)
            if (pS[i] == e)
                return true;
        return false;
    }
    bool operator<=(const Set &s) const; // this <= s判断当前集合是否包于集合s
    bool operator==(const Set &s) const; //判断集合是否相等
    Set &operator+=(int e);              // 向集合中增减元素e
    Set &operator-=(int e);              //删除集合中的元素e

    Set operator|(const Set &s) const; //集合并
    Set operator&(const Set &s) const; //集合交
    Set operator-(const Set &s) const; //集合差
};

Set &Set::operator+=(int e)
{
    if (IsElement(e))
        return *this;
    int *p = new int[n + 2];
    int n = this->n;
    for (int i = 1; i <= n; i++)
        p[i] = this->pS[i];
    p[n + 1] = e;
    this->n++;
    this->pS = p;
    return *this;
}

Set &Set::operator-=(int e)
{
    if (!IsElement(e))
        return *this;
    int *p = new int[n];
    int n = this->n, k = 1;
    for (int i = 1; i <= n; i++)
        if (this->pS[i] != e)
            p[k++] = this->pS[i];
    this->n--;
    this->pS = p;
    return *this;
}

bool Set::operator<=(const Set &s) const
{
    if (this->n > s.n)
        return false;
    int n = this->n;
    for (int i = 1; i <= n; i++)
        if (!s.IsElement(this->pS[i]))
            return false;
    return true;
}

bool Set::operator==(const Set &s) const
{
    if (this->n != s.n)
        return false;
    for (int i = 1; i <= n; i++)
        if (!s.IsElement(this->pS[i]))
            return false;
    return true;
}

Set Set::operator|(const Set &s) const
{
    // int k = 1;
    // int *p = new int[this->n + 1 + s.n + 1];
    // for (int i = 1; i <= this->n; i++)
    //     p[k++] = this->pS[i];
    // for (int i = 1; i <= s.n; i++)
    //     if (!this->IsElement(s.pS[i]))
    //         p[k++] = s.pS[i];
    // Set tmp;
    // tmp.n = k - 1;
    // tmp.pS = p;
    // return tmp;
    Set tmp;
    for (int i = 1; i <= this->n; i++)
        tmp += this->pS[i];
    for (int i = 1; i <= s.n; i++)
        tmp += s.pS[i];
    return tmp;
}

Set Set::operator&(const Set &s) const
{
    int n, flag, k = 1;
    if (this->n < s.n)
    {
        n = this->n;
        flag = 0;
    }
    else
    {
        n = s.n;
        flag = 1;
    }
    int *p = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        if (flag && this->IsElement(s.pS[i]))
            p[k++] = s.pS[i];
        if (!flag && s.IsElement(this->pS[i]))
            p[k++] = this->pS[i];
    }
    Set tmp;
    tmp.n = k - 1;
    tmp.pS = p;
    return tmp;
}

Set Set::operator-(const Set &s) const
{
    int k = 1;
    int *p = new int[this->n + 1 + s.n + 1];
    for (int i = 1; i <= this->n; i++)
        if (!s.IsElement(this->pS[i]))
            p[k++] = this->pS[i];
    Set tmp;
    tmp.n = k - 1;
    tmp.pS = p;
    return tmp;
}

int main()
{
    Set s1, s2;
    s1 += 1;
    s1 += 3;
    s2 += 2;
    s2 += 1;
    (s1 - s2).ShowElement();

    return 0;
}