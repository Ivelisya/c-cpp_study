//
// Created by 20212 on 17/8/2024.
//
#include <iostream>
using namespace std;
void Func(int a = 0){
    cout << a << endl;
}
//全缺省 半缺省
//全缺省
void Func1(int a = 10,int b = 20,int c = 30){
    cout << "a = "<< a << endl;
    cout << "b = "<< b << endl;
    cout << "c = "<< c << endl;
}
//半缺省(缺省部分参数，必须从右往左连续缺省）
void Func2(int a,int b = 20,int c = 30){
    cout << "a = "<< a << endl;
    cout << "b = "<< b << endl;
    cout << "c = "<< c << endl;
}
int main(){
    Func1();
    Func2(1);
}