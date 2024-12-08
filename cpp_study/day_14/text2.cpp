//
// Created by 20212 on 12/9/2024.
//
/*
 *
 *
 *
 *
 * */
#include <iostream>

class Data {
public:
    Data(int year = 0, int month = 1, int day = 1) {
        _year = year;
        _month = month;
        _day = day;
    }

    //void Print() -> void Print(Data* this)
    //void Print(const Data* this)
    void Print() const {
        //const修饰*this 代表指向的对象的内容不能被更改
        //就不能修改成员变量了，因为const修饰保护了*this
        std::cout << _year << "-" << _month << "-" << _day << std::endl;
    }
    // const Data* p1 -> 指向的对象
    // Data const *p2 -> 指向的对象
    // Data* const p3 -> 指针本身

    //*之后是指针本身 *之前是指向的对象
    void f(const Data &d) {
        d.Print();//实际上是传 d.Print(&d),隐含this指针,实际上这里的指针是 const Data*
    }

//    void f1(){ //void f1(Data* this)
//        f2();//this -> f2(this)
//可读可写传过去可读 所以是可以的
//    }
//    void f2() const{
//
//    };
//    void f3(){
//
//    };
//    void f4() const{
//        f3()
//不行 属于权限放大
//    };
//只要调用成员函数，都涉及this指针
    Data *operator&() {
        std::cout << "opeartor &()" << ":";
        return this;
    }

    const Data *operator&() const {
        std::cout << "const opeartor &()";
        return this;
    }

private:
    int _year;
    int _month;
    int _day;
};

int main() {
//    Data d1(2020,4,18);
//    d1.f(d1);
//    d1.Print();
    //权限可以缩小但是权限不可以放大
    Data d1;
    Data d2;
    const Data d3;

    std::cout << &d1 << std::endl;
    std::cout << &d2 << std::endl;
    std::cout << &d3 << std::endl;
//const对象不可以调用非const
//结论 什么时候会给成员函数加const 只要成员函数钟不需要修改成员变量 最好都加上const

//const对象 const可调 非const也可调
//只要成员函数中。只要成员函数中不直接或者间接改变成员变量建议都加上const
//只有这样const和非const才都可以调用
    return 0;
}