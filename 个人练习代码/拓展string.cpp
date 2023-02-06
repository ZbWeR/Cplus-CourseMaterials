// #include "CString.h"
#include <iostream>
#include <cstring>
using namespace std;
class String
{
protected:
    char *mystr;
    int len;

public:
    String(const char *p)
    {
        len = strlen(p);
        mystr = new char[len + 1];
        strcpy(mystr, p);
    }
    ~String()
    {
        if (mystr != NULL)
        {
            delete[] mystr;
            mystr = NULL;
            len = 0;
        }
    }
    void showStr() { cout << mystr; }
    char *GetStr() { return mystr; }
    virtual bool IsSubString(const char *str)
    {
        int i, j;
        for (i = 0; i < len; i++)
        {
            int k = i;
            for (j = 0; str[j] != '\0'; j++, k++)
            {
                if (str[j] != mystr[k])
                    break;
            }
            if (str[j] == '\0')
                return true;
        }
        return false;
    }
};

class EditString : public String
{
public:
    EditString(const char *p) : String(p) {}
    int IsSubString(int start, const char *str);
    void EditChar(char s, char d);
    void EditSub(char *subs, char *subd);
    void DeleteChar(char ch);
    void DeleteSub(char *sub);
};

int EditString::IsSubString(int start, const char *str)
{
    int i, j;
    for (i = start; i < len; i++)
    {
        int k = i;
        for (j = 0; str[j] != '\0'; j++, k++)
        {
            if (str[j] != mystr[k])
                break;
        }
        if (str[j] == '\0')
            return i;
    }
    return -1;
}

void EditString::EditChar(char s, char d)
{
    for (int i = 0; i < this->len; i++)
        if (this->mystr[i] == s)
            this->mystr[i] = d;
}

void EditString::EditSub(char *subs, char *subd)
{
    int n = strlen(subs), m = strlen(subd);
    int tmplen = len * max(1, n - m), k = 0, flag = 0;
    char tmp[tmplen];
    for (int i = 0; i < len; i++)
    {
        if (mystr[i] != subs[0])
        {
            tmp[k++] = mystr[i];
            continue;
        }
        flag = 0;
        for (int j = 0; j < n; j++)
            if (mystr[i + j] != subs[j])
                flag = 1;
        if (flag == 1)
        {
            tmp[k++] = mystr[i];
            continue;
        }

        for (int j = 0; j < m; j++)
            tmp[k++] = subd[j];
        i += n - 1;
    }
    delete[] mystr;
    mystr = new char[k + 1];
    strcpy(mystr, tmp);
}

void EditString::DeleteChar(char ch)
{
    char tmp[len + 1];
    int k = 0;
    for (int i = 0; i < len; i++)
        if (mystr[i] == ch)
            continue;
        else
            tmp[k++] = mystr[i];
    delete[] mystr;
    mystr = new char[k + 1];
    strcpy(mystr, tmp);
}

void EditString::DeleteSub(char *sub)
{
    char tmp[1000];
    int k = 0, flag;
    for (int i = 0; i < len; i++)
    {
        if (mystr[i] != sub[0])
        {
            tmp[k++] = mystr[i];
            continue;
        }
        flag = 0;
        for (int j = 0; j < strlen(sub); j++)
            if (mystr[i + j] != sub[j])
                flag = 1;

        if (flag == 1)
        {
            tmp[k++] = mystr[i];
            continue;
        }

        i += strlen(sub) - 1;
    }
    delete[] mystr;
    mystr = new char[k + 1];
    strcpy(mystr, tmp);
}

int main()
{
    EditString es("tewsttesttwest");
    es.EditSub("es", "qwq"); //"tttttt";
    es.showStr();

    return 0;
}