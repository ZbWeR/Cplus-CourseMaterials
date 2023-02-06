#include <iostream>
#include <cstring>

using namespace std;

class animal 
{
    public:

    char name[8];

    animal(const char * name) 
    {
        strncpy(this->name, name, 7);
        this->name[7]='\0';
    }

    virtual void say_hello() = 0;

    char* get_name() 
    {
        return name;
    }

    virtual void say_food() = 0;
};

class dog : public animal
{
    public:

    int birth;

    dog(const char * name, int birth) : animal(name) 
    {
        this->birth=birth;
    }

    void say_hello() 
    {
        cout << "Wang Wang. My name is " << get_name() << ". I born in " << get_birth() << "." << endl;
    }

    int get_birth() 
    {
        return birth;
    } 

    void say_food() 
    {
        cout << "I like bone." << endl;
    }
};

class cat : public animal
{
    public:

    char color[8];

    cat(const char * name, const char * color) : animal(name) 
    {
        strncpy(this->color, color, 7);
        this->color[7]='\0';
    }

    void say_hello() 
    {
        cout << "Miao Miao. My name is " << get_name() << ". I am " << get_color() << "." << endl;        
    }

    char* get_color() 
    {
        return color;
    }

    void say_food() 
    {
        cout << "I like fish." << endl;
    }    
};

int main()
{
    dog wangcai("WangCai", 2021);
    cat jiafei("JiaFei", "BLACK");
    
    cout << "--- At home ---" << endl;
    wangcai.say_hello();
    jiafei.say_hello();

    cout << "--- At zoo ---" << endl;
    animal *zoo[3]={&wangcai, &jiafei};
    for(int i=0; i<2; i++)
    {
        zoo[i]->say_hello();
        zoo[i]->say_food();
    }

    return 0;
}