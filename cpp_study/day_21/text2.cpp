//
// Created by 20212 on 24-9-22.
//
#include <iostream>

using namespace std;

//malloc 和 new
//new会调用构造函数，失败抛异常 malloc失败了返回0
//malloc是一个函数 new是一个操作符
//malloc的用法 void*

//c++ 独有的问题 内存泄露 java就轻松很多，因为他有垃圾回收器

int main() {
//    char *p = new char[1024*1024*1024]; //p指向的内存不需要了，忘记或其它原因没有释放就是内存泄露
    //内存泄露的危害:长期运行的程序(游戏服务),出现内存泄露的危害就很大
//    return 0;
    size_t n = 4;
    try {
        void *p = new char[n * 1024 * 1024 * 1024];
        cout << "new:" << p << endl;
    }
    catch(exception&e){
        cout<< e.what() <<endl;
    }
    return 0;
}