# C++学习记录

## 引用

即变量的别名。必须在定义时初始化,且不能更改,只能引用一级,不能为空`NULL`。

一般情况下修改引用的值,被引用的值也会随之修改.通常会使用**常引用**.

==(暂未掌握)==引用类型:[C++ 引用类型 — 左值引用、常引用和右值引用 - 简书 (jianshu.com)](https://www.jianshu.com/p/2ed2689afa49)

### 作为参数

```cpp
void Swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}
```

### 作为返回值

要注意被引用的对象不能超出作用域。所以返回一个对局部变量的引用是不合法的，但是，可以返回一个对静态变量的引用。

```cpp
int allUseCan[] = {1, 2, 3, 4, 5, 6};
int &setValue(int i){
    return allUseCan[i];
}
用法：
setValue(0) = 2333;
```

### 常引用

```cpp
int a=1;
int const & n = a;// 不能修改n的值
```

### 示例代码

```cpp
#include <bits/stdc++.h>
using namespace std;
void Swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}
int allUseCan[] = {1, 2, 3, 4, 5, 6};
int &setValue(int i){
    return allUseCan[i];
}
int main(){
    int ZhangBoWen = 2333;
    int &zbw = ZhangBoWen;
    printf("ZhangBoWen is %d\n", ZhangBoWen);
    printf("zbw is %d\n", zbw);
    printf("#######################\n");
    int x = 2, y = 3;
    printf("Before: x=%d y=%d\n", x, y);
    Swap(x, y);
    printf("After : x=%d y=%d\n", x, y);
    printf("#######################\n");
    for (int i = 0; i < 6; i++)
        printf("%d ", allUseCan[i]);
    putchar('\n');
    setValue(0) = 2333;setValue(1) = 666;
    for (int i = 0; i < 6; i++)
        printf("%d ", allUseCan[i]);
    return 0;
}
```

## 指针与常量

```cpp
int main(){
    int x = 0, y = 0;
    int *const p1 = &x; 
    // p1是指针常量,确定后不能更改指向的地址,可以修改具体值
    // p1 = &y; 报错
    // *p1 = 9;
    int const *p2 = &x; 
    // p2是指向常量的指针,不能修改它具体的值,可以修改地址
    // p2 = &y;
    // *p2 = 9; 报错
    int const *const p3 = &x;
    // p3是指向常量的指针常量,不能动也不能改.
    cout << x << " " << y;
    return 0;
}
```

+ 指针常量：类型为常量的指针，地址不能移动.
+ 常量指针：指向常量的指针,值不能随便更改.

## 重载函数

```cpp
int add(int x,int y){
    return x+y;
}
int add(int x,int y,int z){
    return x+y+z;
}
int add(double x,double y){
    return x+y;
}
//返回类型不同,其他都相同的函数无法重载.
double add(int x,int y){
    return x+y;
}
```

重载函数：源代码中即使使用了两个完全相同的函数名，在编译的过程中也不会发生重名冲突。只需满足以下两个条件之一即可：

+ 参数个数不同
+ 参数类型不同

## 默认形参

```cpp
void Register(int number, char const *name, int age = 18, char const *country = "China"){
    cout << "Number: " << number << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Country: " << country << endl;
}
void Register(int number, char const *name){
    cout << "###";
    cout << "Number: " << number << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << 18 << endl;
    cout << "Country: China " << endl;
}

int main(){
    // Register(1, "ZhangSan"); /* error */
    Register(2, "WangWu", 20);
    Register(3, "Tom", 18, "England");
    // 这两行执行的都是第一个Register
    return 0;
}
```

可以在定义函数时给出默认的形参值。调用函数时如果给出了实参值， 则使用给出的实参值；如果未给出实参值，则使用默认的形参值。

需要注意的是：(参考代码中)

> 如果在代码中存在多个重载函数，并且这些函数在形参列表上除了默认形参之外都相同，那么在调用这些函数时就会出现二义性，因为编译器无法确定应该调用哪个函数。为了避免这种情况，在定义重载函数时最好**不要使用默认形参**。

## 动态内存分配

```cpp
// C语言内存分配
int *a = (int *)malloc(sizeof(int));
free(a);
// C++内存分配
int *b = new int(123); // 分配一个变量并初始化为123
cout << *b << endl;
delete b;
int *c = new int[5]{1, 2, 3, 4, 5}; // 分配一个数组并初始化
cout << *c;
delete c;
```

+ C语言: `malloc`和`free`
+ C++: `new`和`delete`,两者必须配合使用,未删除内存或重复删除内存都可能导致程序崩溃.

## 封装继承多态

> **封装:**指的是将一些细节隐藏起来，只提供给外部调用的接口。这样可以保证外部的代码不会直接操作内部的实现，使得代码更安全和可靠。**隐藏细节，提供接口**
> 
> **继承:**指的是在已有的类的基础上创建新类。新类可以继承原有类的属性和方法，并且可以添加新的属性和方法。这样可以减少重复的代码，提高代码的复用性。**继承父类,节约代码**
> 
> **多态:**指的是在不同的类中可以有相同的方法名，但它们所执行的操作可能不同。多态可以让我们在不需要知道具体的类型的情况下调用方法，使得代码更加灵活。**同一消息，不同反应**

### 示例代码

```cpp
class Shape
{
public:
    Shape() {}  // 构造函数
    ~Shape() {} // 析构函数
    // 采用纯虚函数体现多态思想:不同的类计算面积或者周长的方法不同
    virtual double GetArea() = 0;
    virtual double GetPerimeter() = 0;
    static Shape *createRectangle(double length, double width);
    static Shape *createCircle(double radius);
};
// 继承
class Rectangle : public Shape
{
    /* 私有成员,体现封装思想:隐藏细节,只提供外部可调用的接口 */
private:
    double l, w;
public:
    Rectangle(double l, double w)
    {
        this->l = l;
        this->w = w;
    }
    double GetArea() { return l * w; }
    double GetPerimeter() { return 2 * (l + w); }
};
class Circle : public Shape
{
private:
    double r;
public:
    Circle(double r) { this->r = r; }
    double GetArea() { return 3.14 * r * r; }
    double GetPerimeter() { return 2 * 3.14 * r; }
};

Shape *Shape::createRectangle(double l, double w){
    return new Rectangle(l, w);
}
Shape *Shape::createCircle(double r){
    return new Circle(r);
}
```

### 构造函数

构造函数，是一种特殊的成员函数，函数名和类名完全相同，没有返回 类型。构造函数的主要任务，是对对象进行“初始化”操作。可以根据需求定义多个构造函数，它们之间通过不同的参数区分（重载构造函数）.

### 拷贝构造函数

当我们需要使用一个已有对象对新建对象进行初始化的时候，我们如果直接采用`=`来进行这个操作，就会调用默认构造拷贝函数。

默认的拷贝构造函数会让不同对象的指针指向同一片内存,当一个指针释放时，另一个指针也就失效了，导致程序错误。因此涉及到指针时，我们需要自定义拷贝构造函数，并为指针`new`一片新的空间.

值得注意的是: 如果只定义了拷贝构造函数，而没有定义析构函数，则会导致**内存泄漏**。

### 析构函数

析构函数也是一种特殊的成员函数，函数名是在类名前面加一个`~`号， 没有返回类型，也没有参数。析构函数不能重载，每个类只有一个析构函数。析构函数在释放对象时调用，可用于释放动态申请的内存空间或 其它“扫尾”工作。

### 参考代码

```cpp
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
        //在对象内部访问对象使用 this->
        this->number = number;
        this->score = score;
        p = new int(202200 + number);
    }
    // 等价于上面的构造函数,较为简便的写法
    // student(int x, double y = 0.0) : number(x), score(y),p(new int(202200+number)) {}
    // 拷贝构造函数,利用已有对象对新建对象初始化
    student(student &x) : number(x.number), score(x.score)
    {
        p = new int(*x.p); // 深拷贝,开辟新空间存放已有对象中指针的具体值
    }
    // 析构函数,释放内存
    ~student() { delete p; }
    void show() { cout << *p << " " << score << endl; }
};

int main()
{
    student A(1, 66.7); A.show();
    student B(A);
    A.~student(); B.show();
    return 0;
}
```

### 临时对象

直接调用构造函数，会生成一个临时对象。例如`student C = student()`,等号右侧直接调用了构造函数,生成了一个`student`类的临时对象，并使用这个临时对象去初始化新建的对象`C`,这就涉及到上面讲到的拷贝构造函数。

临时对象通常被认为是“右值”，通常是不可以修改的，如果我们调用拷贝构造函数，我们需要将其变为==常引用==才能正常拷贝。

```cpp
构造函数：注意const修饰
foo(const foo &A) : pos(A.pos) {}
使用临时对象初始化:
foo A = foo(10); // foo A = {9};两者等价
foo B = foo(A);
foo C[3] = {{1}, {2}, {3}}; // 数组的初始化
```

### 友元

封装实现了隐藏细节，不让外部访问内部私有成员。虽说安全性提高了，但也使得有些操作不够方便。友元可以打破类的权限规则。为一个类设置友元后，该类的所有成员对该友元都是可见的。有两种类型的友元：友元函数与友元类。

```cpp
class student{
private:
    int pos, score;

public:
    student(int x, int y) : pos(x), score(y) {}
    friend void show(student s); // 友元函数
    friend class teacher;        // 友元类
};
class teacher{
public:
    void show(student s) { cout << s.pos << " " << s.score << endl; }
};
void show(student s) { cout << s.pos << " " << s.score << endl; }
```

### 类的组合

如果一个成员变量是类类型，称为“类的组合”在使用类的组合时，要特别注意一个对象和它包含的对象的初始化问题。

构造函数的调用顺序：先成员，后自己。析构函数的调用顺序：先自己，后成员。

### 常成员函数

常成员函数表明该函数不会修改类内其他成员的值。

```cpp
class student{
private:
    int pos, score;

public:
    student(int x, int y) : pos(x), score(y) {}
    void show() const {
        // error: const成员函数中不允许修改
        score = 100;
    }
};
```

### 常成员变量

例如：学号是一个学生入学(初始化)时就确定了，以后不能修改。这就是常成员变量，在初始化后便不可修改。且只能在初始化列表中进行初始化：

```cpp
class foo{
private:
    const int x;
    foo(int num) { x = num; } // error: x不允许修改
    foo(int num) : x(num) {}  // 只允许通过这种方式来初始化
};
```

### 静态成员

#### 静态成员变量

所有对象共享的数据，可以设为静态变量。它的值在整个类的对象中是相同的。静态成员变量不属于任何特定的对象，而是属于整个类。因此，可以通过类名来访问静态成员变量。静态成员变量通常用于记录类的信息，例如统计类中实例的个数。

#### 静态成员函数

静态成员函数是一种特殊的成员函数，它的访问范围是整个类而不是某个特定的对象。静态成员函数不能访问类的非静态成员，但可以访问类的静态成员。通常，静态成员函数用于维护类的静态成员，或者实现与特定类相关的工具函数。

```cpp
class foo
{
private:// 变量在类的内部定义
    static char name[30];
public:
    static void show(){ cout << name << " " << endl; }
};
// 变量在类的外部声明
char foo::name[30] = "Class foo";
int main()
{
    foo A; // name 属于foo这个类,而不是属于A这个对象.
    A.show();foo::show(); // 可以直接通过类名加运算符调用函数,而不用创建一个对象
    return 0;
}
```

#### 实现单例模式

单例模式是一种常用的设计模式，其目的是保证一个类只有一个实例，并提供一个全局访问点来访问该实例。单例模式可以用来实现全局变量的替代，避免了使用全局变量带来的命名冲突和维护困难的问题。

实现单例模式的关键在于控制对象的创建和复制。通常，可以通过将构造函数、析构函数和拷贝构造函数声明为私有来防止外界直接创建和复制对象。然后，提供一个公有的静态成员函数用于返回唯一的对象实例。

```CPP
int id = 0;
class foo{
public:
    // 方法一: 
    static foo &CreatFoo(){
        static foo instance;
        return instance;
    }
    // 方法二: 借助静态成员变量 *vip
    static foo *CreateFoo2(){
        if (vip == nullptr)
            vip = new foo();
        else
            cout << "only one\n";
        return vip;
    }
    void show() { cout << pos << endl; }

private:
    int pos;
    static foo *vip;
    foo() : pos(++id) {}
    ~foo() {}
    foo(const foo &);
};
foo *foo::vip = nullptr;

int main()
{
    foo &A = foo::CreatFoo();A.show();
    foo &B = foo::CreatFoo();B.show();
    // foo *C = foo::CreateFoo2();C->show();
    // foo *D = foo::CreateFoo2();D->show();
    return 0;
}
```

### 不同继承方式的权限

| 继承方式      | 公有成员  | 保护成员  | 私有成员 |
| ------------- | --------- | --------- | -------- |
| public继承    | public    | protected | 不可访问 |
| protected继承 | protected | protected | 不可访问 |
| private继承   | private   | private   | 不可访问 |

### 多重继承

多重继承是一些面向对象编程语言的特性，它允许一个类从多个父类继承特征和行为。譬如表示[鸟]的类，可能同时继承[动物]类和[飞行]类，可以帮助我们提高代码的复用性，利于模块化设计。

### 虚基类

多重继承中可能会出现菱形继承的问题：当一个类(D)派生自两个父类(B,C)时，这两个父类又派生自同一个公共基类(A),就可能会造成歧义和创建基类的多个副本，出现内存管理的问题。

这时候我们可以使用虚拟继承的方法，也叫虚基类来避免这个问题：通过将基类指定为virtual，可以确保它只实例化一次，并且继承它的层次结构中的所有类将共享基类的相同实例。

```cpp
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
int main(){
    D x;
    return 0;
}
```

去掉`virtual`会发现`A create`了两次,这就会重复创建对象导致资源浪费。

### 多态的实现

#### 虚函数

虚函数即对成员函数添加`virtual`修饰，它可以被派生类覆盖。这意味着派生类可以提供属于自己的虚函数实现，当在派生类的对象上调用函数时，将调用它而不是基类实现。

#### 纯虚函数

例如: `virtual void say_hello() = 0;`

虚函数和纯虚函数之间的主要区别是虚函数提供实现，而**纯虚函数不提供**，但是派生后的子类必须实现这个纯虚函数，否则无法正常运行。

一些名词定义：

> 抽象类： 拥有纯虚函数的类称为抽象类。抽象类不能被实例化，只能作为其它类的基类.
>
> 接口类： 当一个抽象类的所有成员函数都是纯虚函数时，这个抽象类又称为接口类。

```cpp
class Animal {
public:
    virtual void makeNoise() = 0; // pure virtual function
};
class Cat : public Animal {
public:
    void makeNoise() {
        std::cout << "Meow!" << std::endl;
    }
};
class Dog : public Animal {
public:
    void makeNoise() {
        std::cout << "Woof!" << std::endl;
    }
};
int main() {
    Cat c;
    Dog d;
    Animal *a1 = &c;
    Animal *a2 = &d;
    
    a1->makeNoise(); // prints "Meow!"
    a2->makeNoise(); // prints "Woof!"
    return 0;
}
```

#### 模板函数

模板函数是用泛型类型参数定义的函数，允许它对各种数据类型进行操作。当您希望编写一个可用于多种类型数据的函数，而不必为每种类型编写函数的单独版本时，这是非常有用的。

```cpp
template <class T>
T add(T a, T b){
    return a + b;
}
int a=1,b=2; add(a,b) // prints 3
double a=1.1,b=2.2 ; add(a,b) // prints 3.3
```

#### 模板类

与模板函数类似，只不过变成了类，将多个模板函数封装起来。例如[栈]数据结构,[链表]数据结构.

```cpp
template<typename T>
class Stack {
public:
    void push(T value);
    T pop();
    bool isEmpty();

private:
    std::vector<T> data;
};
int main() {
    Stack<int> intStack;
    intStack.push(123);
    intStack.push(456);
    std::cout << intStack.pop() << std::endl; // prints "456"

    Stack<double> doubleStack;
    doubleStack.push(3.14);
    doubleStack.push(2.71);
    std::cout << doubleStack.pop() << std::endl; // prints "2.71"

    Stack<std::string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");
    std::cout << stringStack.pop() << std::endl; // prints "World"

    return 0;
}
```

