//
// Created by 20212 on 24-10-24.
//
#include <iostream>
#include <string>
using namespace std;
//
// class Person
// {
// public:
//     void Print()
//     {
//         cout << "name:" << _name << endl;
//         cout << " age:" << _age << endl;
//     }
//
// protected:
//     string _name = "peter";
//
// private:
//     int _age = 18;
// };
//
// class Student : public Person
// {
// public:
//     void f()
//     {
//         //类中的私有和保护在当前类没差别
//         //在继承后的子类中有差别
//         cout << _name << endl;
//
//         // 基类的其它成员在派生类中的访问方式min(继承方式,访问限定符)
//         //比如基类是 public protect继承， public的访问方式变为protect只能在类里面使用
//     }
//
// protected:
//     int _stuid;
//     int _major;
// };
//
// //私有的在子派生类都不可见
// int main()
// {
//     Student s;
//     s.Print();
//     s.f();
// }

class Person
{
protected:
    string _name;
    string _sex;
    int _age;
};

class Student : public Person
{
public:
    int _No; //学号
};

int main()
{
    Person p;
    Student s;
    //子类和父类之间的赋值兼容规则
    //1.子类对象可以赋值给父类对象/指针/引用
    //也叫切割 切片 把父类的一部分切出来
    //父类对象的可以赋值给子类对象吗
    //有时候可以 这个父类的指针是指向子类对象的
    //Student* sptr = (Student*)sptr 要强转

    return 0;
}
//当父类和子类同时有同名成员时，子类的成员隐藏了父类的成员(重定义)

//重载要求是必须在同一作用域