//
// Created by 20212 on 16/9/2024.
//
#include <iostream>

using namespace std;

class Date {
    friend ostream &operator<<(ostream &out, const Date &d);

    friend istream &operator>>(istream &in, Date &d);

    friend void f(Date &d);

public:
//    Date():_year(10){}
//    void Print(){
//        cout <<_year<<"-"<<_month<<"-"<<_day<<endl;
//    }
    Date(int year = 0, int month = 1, int day = 1) : _year(year),
                                                     _month(month), _day(day) {

    }

private:
    //c++11
    //声明时给缺省值
    int _year = 0;
    int _month = 1;
    int _day = 1;
    //static int _n 这个不能给初始值 必须在类外面去定义
};

//int Date::n = 1;
ostream &operator<<(ostream &out, const Date &d) {
    out << d._year << "/" << d._month << "/" << d._day << endl;
    return out;
}

void f(Date &d) {
    d._year = 10;
    cout << d._year << endl;
}

istream &operator>>(istream &in, Date &d) {
    in >> d._year >> d._month >> d._day;
    return in;
}

int main() {
//    Date d1;
//    d1.Print();
    Date d1(2024, 9, 13);
    Date d2(2024, 9, 14);
    cout << d1 << d2; // operator  << (cout,d1);
//    int i = 0, j = 1;
//    cout << i << j << endl;
//    f(d1);
    int x = 1;
    double y = 1.11;
    //为什么能自动识别类型，因为函数重载
    cout << x;
    cout << y;
    return 0;
}
//类里面都是声明
//友元 类外面访问类里面私有的方式
//友元 类外面访问

//cout -> ostream
//cin -> istream

//面向对象 低耦合，高内聚，工程项目