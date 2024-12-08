//
// Created by 20212 on 30/8/2024.
//
//c语言是面向过程的
//c++是面向对象的语言


//面向过程 关注求解的过程
#include <iostream>
using namespace std;
//类里面可以定义:1.成员变量 2.成员方法
//class Person{
//    void Print(){
//
//    }
//    char _name[10];
//    int _age;
//    //....
//};
////
////c++中class和struct都可以用来定义类，class默认访问限定符是私有的，struct默认访问限定符是共有的
//class Student{
//    //class默认的访问限定符是私有的
//public:
//    void ShowInfo(){
//        cout << _name <<endl;
//        cout << _age << endl;
//        cout << _stuid << endl;
//    }
//    int GetAge(){
//        return _age;
//    }
//private:
//    char* _name;
//    int _age;
//    int _stuid;
//};
//int main(){
//    Student s1;
//    Student s2;
//    s1._age = 18;
//    s1._stuid  = 10;
//    s1._name = "peter";
//    s1.ShowInfo();
//}
class Stack{
public:
    void Init(size_t n){

    }
    void Destory(){

    }
    void Pop(){

    }
private:
    int *_a;
    size_t _top;
    size_t _capacity;
};