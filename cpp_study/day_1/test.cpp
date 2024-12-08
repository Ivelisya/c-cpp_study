//
// Created by 20212 on 17/8/2024.
//
//namespace N 定义命名空间
//N::a 打开N空间里面的a
//namespace N{
//    int a = 10;
//    int b = 20;
//}
//using namespace std; // c++库中的所有东西都是放在std命名空间的
#include <iostream>
int main(){
//    printf("%d",N::a);
//using namespace N;
//using N::a;
//自动识别类型
//在日常中，我们不在乎和库命名冲突，可以直接全导出
//常用的一些库和对象或者类型可以展出来
//using std::cout;
//using std::endl;
    std :: cout <<"hello world"<<std::endl;
    int i = 1;
    double d = 1.11;
    std::cin >> i >> d;
    std::cout<< i << " "<< d<<std::endl;
}
