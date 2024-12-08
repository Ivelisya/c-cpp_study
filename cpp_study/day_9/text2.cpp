//
// Created by 20212 on 1/9/2024.
//

//实例化 -> 就是用自己定义出的类型定义出对象
//1.内置类型,基本类型 int/char/double
//2.自定义类型,class/struct
#include <iostream>

using namespace std;
class Time{
    Time(){
        _hour = 0;
        _minute = 0;
        _second = 0;
    }
private:
    int _hour;
    int _minute;
    int _second;
};
class Data {
public:
    //编译器处理时会加一个隐含的this指针
    //void Print(Data* this)

    //this是谁调用这个成员函数就指向谁

    //构造函数 ->在对象构造时调用的函数,这个函数完成初始化工作
    //构造函数 函数名与类名相同
    //构造函数可以重载
   /* Data(int year,int month,int day_14){
        _year = year;
        _month = month;
        _day = day_14;
    }
    Data(){
        _year = 0;
        _month = 1;
        _day = 1;
    }
    */
    Data(int year = 0,int month = 1,int day = 1){
        _year = year;
        _month = month;
        _day = day;
    }//利用缺省，实现想传几个就传几个
   //我们没有显示定义构造函数，这里编译器生成无参默认构造函数，一旦我们显示定义呀，编译器将不在默认生成
   //默认生成无参的构造函数
   //1.针对内置类型的成员变量没有做处理
   //2.针对自定义类型的成员变量，调用它的构造函数初始化

    void Print() {
        cout << _year << "-" << _month << "-" << _day << endl;
    }

    //形参
    void Init(int year, int month, int day) {//void Init(this* this)
        this->_year = year;
        this->_month = month;
        this->_day = day;
    }

private:
    int _year;
    int _month;
    int _day;
};

int main() {
//    int i1;
//    int ii1;
//对象实列化时自动调用
//    Data d1(2024,9,1);
    Data d1;//调用编译器生成的构造函数
//    Data d2()不可以这样写,编译器不认识
    //实参
//    d1.Init(2024, 1, 9);//d1.Init(&d1);
//    Data d2;
//    d2.Init(2024,1,9);
    d1.Print();
//    d2.Print();
    return 0;
}
//算类型的大小,实际上是算这个类型定义出对象的大小

//this指针是存在进程地址空间的哪个区域 this指针是存在栈上的 因为它是一个形参,函数参数都是函数栈帧的一部分(ps:vs下是在ecs这个寄存器来传递)

//如果类中没有显示定义构造函数，则c++编译器会自动生成一个无参的默认构造函数
//无参的构造函数和全缺省的构造函数还有不写编译器默认生成的，都是默认构造函数
//但是默认构造函数只能存在一个

//析构：对象声明周期到了之后自动调用，完成清理工作，不是完成d1和d2的销毁