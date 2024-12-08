//
// Created by 20212 on 8/9/2024.
//
#include <iostream>

using namespace std;

class Data {
public:
    // 获取指定年份和月份的天数
    int GetMonthDay(int year, int month) const {
        int monthDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        // 是二月且是闰年，返回29天
        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) {
            return 29;
        }
        return monthDays[month];
    }

    // 构造函数
    Data(int year = 0, int month = 1, int day = 1) {
        if (year >= 0 && month >= 1 && month <= 12 && day >= 1 && day <= GetMonthDay(year, month)) {
            _year = year;
            _month = month;
            _day = day; // 修正：将 day 赋值给 _day
        } else {
            std::cout << "非法日期" << std::endl;
            _year = 0;
            _month = 1;
            _day = 1;
        }
    }

    // 拷贝构造函数
    Data(const Data &d) { // 使用 const 引用以避免修改原对象
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }

    //d1 < d2
    //d1.operator<(&d1,d2)
    bool operator<(const Data &d) const {
        if (_year < d._year) {
            return true;
        } else if (_year == d._year && _month < d._month) {
            return true;
        } else if (_year == d._year && _month == d._month && _day < d._day) {
            return true;
        }
        return false;
    }

    bool operator==(const Data &d) const {
        return _year == d._year && _month == d._month && _day == d._day;
    }

    bool operator<=(const Data &d) const {
        return *this < d || *this == d;
    }

    //运算符的重载是为了让自定义类型可以像内置类型一样去使用
    //d3 = d1 表达式的返回值是d3才能支持连等
    Data &operator=(const Data &d) {
        if (this != &d) {//针对自己给自己赋值的判断检查
            _year = d._year;
            _month = d._month;
            _day = d._day;
        }
        return *this;//this 就是d3的地址，*this就是d3
    }

    Data operator+(int day) {
        Data ret(*this);
//        ret._day += day;
//        while (ret._day > GetMonthDay(ret._year, ret._month)) {
//            ret._day -= GetMonthDay(ret._year, ret._month);
//            ret._month++;
//            if (ret._month == 13) {
//                ret._year++;
//                ret._month = 1;
//            }
//        }
        ret += day;
        return ret;
    }

    bool operator>(const Data &d) {
        return !(*this <= d);
    }

    Data &operator+=(int day) {
        if(day < 0)
            return *this -= -day;
        _day += day;
        while (_day > GetMonthDay(_year, _month)) {
            _day -= GetMonthDay(_year, _month);
            _month++;
            if (_month == 13) {
                _year++;
                _month = 1;
            }
        }
        return *this;
    }
    //d1 -= 10 d1.operator -= (&d1,10) this
    //-= 代表 减之后自己的值也跟着改变
    Data &operator-=(int day){
        if(day < 0)
            return *this -= -day;
        this -> _day -= day;
        while(_day <= 0){//day不合法需要继续处理的条件
            --_month;
            if(_month = 0){
                --_year;
                _month = 12;
            }
            _day += GetMonthDay(_year,_month);
        }
        return *this;
    }
    //d1 - 10;
    Data &operator-(int day){
        Data ret = *this;
//        ret._day -= day;
//        while(ret._day <= 0){
//            --ret._month;
//            if(ret._month == 0){
//                --ret._month;
//                if(ret._month == 0){
//                    --ret._year;
//                    ret._month = 12;
//                }
//                ret._day += GetMonthDay(ret._year,ret._month);
//            }
//        }
        ret -= day;
        return ret;
    }
    Data &operator ++(){
        *this += 1;//前置
        return *this;//返回加之后
    };

    Data &operator --(int){//为了构成函数重载
        Data tmp(*this);
        *this += 1;
        return tmp;//返回之前的值
    };

    int operator-(const Data& d){

    }
    void Print() {
        std::cout << _year << "-" << _month << "-" << _day << std::endl;
    }

private:
    int _year;
    int _month;
    int _day;
};

int main() {
    Data d1;
    d1.Print();
    Data d2(2021, 2, 28); // 输入一个非法日期
    d2.Print();
    Data d3 = d2 + 10;
    d3.Print();

    d1 = d2;//两个对象都已经存在且初始化好了，现在我想把d2赋值(拷贝)给d1
    Data d4(d1);//构造d4时用d1去初始化
    Data d5 = d1;//因为d5还不存在，这里是调用拷贝构造
}
//void f1(Data d1) 传值会调用一次拷贝构造，会调用Data拷贝构造
//传值返回 会调用拷贝构造 传引用返回没有
//自定义类型传参数和返回值，在可以的情况下，尽量使用引用，减少拷贝

//自定义类型传参数和返回值 不使用引用会调用拷贝构造

//拷贝构造,在对象创建的时候初始化

//拷贝构造，和赋值 是类的默认成员函数

//c++浅拷贝问题
//同一块空间不允许释放两次 浅拷贝会导致
//深拷贝 拷贝这个指针变量指向的空间
//浅拷贝 同一块空间释放两次导致崩溃

//顺序表，链表，列表等等都存在深浅拷贝