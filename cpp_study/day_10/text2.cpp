//
// Created by 20212 on 2/9/2024.
//
#include <iostream>
using namespace std;
class Data{
public:
    Data(int year = 0,int month = 1,int day =1){
        _year = year;
        _month = month;
        _day = day;
    }
    //Data d2(d1) //对象初始化时自动调用构造函数(拷贝构造)
    Data(Data &d){
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }
    void Print(){
        cout << _year << "-" << _month << "-" <<_day <<endl;
    }
private:
    int _year;
    int _month;
    int _day;
};
void func(int i){

}
int main(){
    Data d1(2020,4,11);//调用之前要先传参
    //这两个写法都是调用拷贝构造
    Data d2(d1);//拷贝构造
    int j = 0;
    func(j);

    return 0;
}
//拷贝构造 对象初始化时自动调用构造函数(拷贝构造)
//调用之前要先传参

//拷贝构造调用函数要先传参
//调用的就是拷贝构造，但是在调用函数时要先传参数，传参的过程又是一个拷贝构造
//实参调用