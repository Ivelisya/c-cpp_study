//
// Created by 20212 on 12/9/2024.
//
#include <iostream>
using namespace std;
class Data{
    //为什么会有初始化列表
    //有些成员必须在初始化列表初始化
    //引用成员
    //const成员
    //自定义成员没有默认构造函数(不用传参就可以调用的构造函数，叫做默认构造函数）
public:
//    Data(int year = 0,int month = 1,int day = 1){
//        _year = year;
//        _month = month;
//        _day = day;
//        //函数体赋值
//    }
    Data(int year = 0,int month = 1,int day = 1):_year(year),_month(month),_day(day){
    //初始化列表
    //可以理解为初始化列表是成员变量定义的地方
}
private:
    int _year;
    int _month;
    int _day;
    //成员变量的声明

    //自定义类型默认调用它的构造函数初始化


    //初始化的顺序和初始化列表无关,跟private里的顺序有关
    //成员变量声明次序，才是初始化次序
};