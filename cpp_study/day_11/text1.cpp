//
// Created by 20212 on 4/9/2024.
//
//拷贝构造传引用
//Data(const Data& d)

//const避免d被修改，出现权限缩小.d是只读
//拷贝构造是构造的一种重载
#include <iostream>

using namespace std;

class Data {
public:
    Data(const Data &d1) {
        _year = d1._year;
        _day = d1._day;
        _month = d1._month;
    }

    Data(int year = 0, int month = 1, int day = 1) {
        _year = year;
        _month = month;
        _day = day;
    }

    //Data d2(d1) //对象初始化时自动调用构造函数(拷贝构造)
    void Print() {
        cout << _year << "-" << _month << "-" << _day << endl;
    }

    bool operator==(const Data &d) {
        return _year == d._year
               && _month == d._month
               && _day == d._day;
    }

    bool operator>(const Data &d) {
        if (_year > d._year) {
            return true;
        } else if (_year == d._year && _month > d._month)
            return true;
        else if (_year == d._year && _month == d._month && _day > d._day)
            return true;
        return false;
    }

private:
    int _year;
    int _month;
    int _day;
};
//bool IsDataEqual(const Data &d1,const Data &d2){
//    return
//}
//运算符有几个操作数，operator重载的函数就有几个操作数
//自定义类型是不能用运算符的，要用就得实现重载函数，用的时候就等价于调重载函数

int main() {
    Data d1(2020, 9, 4);
    Data d2(d1);
    d1 == d2;
    cout << (d1 == d2) << endl;
    cout << (d1 > d2) << endl;
}
//运算符重载