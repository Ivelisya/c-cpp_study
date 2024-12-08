//
// Created by 20212 on 1/9/2024.
//
#include <iostream>

using namespace std;
class Time{
public:

};
class Data {
//类有六个默认的成员函数，你不写编译器就会默认生成
public:
//    Data(){
//        _year = 0;
//        _month = 1;
//        _day = 1;
//    }
//    Data(int year,int month,int day_14){
//        _year = year;
//        _month = month;
//        _day = day_14;
//    }
    Data(int year = 0, int month = 1, int day = 1) {
        _year = year;
        _month = month;
        _day = day;
    }

//可以不写，日期类没有什么资源需要清理
    ~Data() {
        cout << "~Data()" << endl;
    }

private:
    int _year;
    int _month;
    int _day;
    //1.我们不写编译器生成 2.全缺省的 3.无参的 -> 默认构造函数 -> 不传参可以调用的
    //我们不写，编译器生成的构造函数和析构函数
    //内置类型/基本类型 int/char 不会处理
    //自定义类型 调用构造函数初始化

    //不写编译器都可以自动调用
};

class Stack{
public:
    Stack(int n = 10){
        _a = (int*)malloc(sizeof(int)*n);
        _size = 0;
        _capacity = n;
    }
    void Push(int x);
    void Pop();
    size_t Size();
    //对象生命周期到之后，完成清理工作
    ~Stack(){
        free(_a);
        _a = nullptr;
        _size = _capacity = 0;
    }
private:
    int *_a;
    int _size;
    int _capacity;
};
int main() {
    //Data d1;//无参时不能带括号
    //Data d2(2020, 4, 11);

    return 0;
}