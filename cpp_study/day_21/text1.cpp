//
// Created by 20212 on 21/9/2024.
//
#include <iostream>

using namespace std;

class A {
public:
    A(int a = 0)
    :_a(a)
    {
        cout << "A()" << endl;
    }

    ~A() {
        cout << "~A()" << endl;
    }

private:
    int _a;
};
//
//int main() {
//    A *p1 = (A *) malloc(sizeof(A));
//    A *p2 = new A;
//    A *p3 = (A *) operator new(sizeof(A));
//
//    //operator new和malloc的区别是什么
////    void* p4 = malloc(1024*1024*1024*2);
////    cout <<p4 <<endl;
//    try{
//        void* p5 = operator new(1024*1024*1024*2);
//        operator delete(p5);
//    }
//    catch(exception&e){
//        cout <<e.what() <<endl;
//    }
//
//    return 0;
//}

//operator new和malloc的区别
//结论 使用的方式都一样，处理错误的方式不一样

//malloc free
//operator new delete == malloc + 失败抛异常实现
//new delete -> operator new + 构造函数
//new 比起malloc不一样的地方 1.调用构造函数初始化 2.失败了抛异常
//operator delete的出现与operator new配对

int main(){
//    A*p = new A;
//    delete p;
//想要模拟上面的行为
//显示调用A的构造函数和析构函数
    A*p2 =(A*) operator new(sizeof(A));
    //对已经存在的一块空间调用构造函数初始化.定位new/replacement new
    new(p2)A(10);//new(空间的指针) 构造函数类型(参数)
    p2 ->~A();
    return 0;
}