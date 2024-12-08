//
// Created by 20212 on 2024/4/7.
//
//void(* signal(int,void(*)(int)))(int);
//1.signal 和 （） 相结合，说明signal是函数名
//2.signal函数的第一个参数类型是int，第二个参数的类型是函数指针
//该函数指针指向一个参数为int，返回类型是void的函数
//3.signal函数的返回类型也是一个函数指针
//该函数指针指向一个参数为int，返回类型为void的函数

//函数指针数组
int Add(int x,int y){
    return x + y;
}
int Sub(int x,int y){
    return x - y;
}
//int main(){
//    int(*pf1)(int,int) = Add;
//    int(*pf2)(int,int) = Sub;
//    int (*pfArr[2])(int,int) = {Add,Sub};
//    return 0;
//}
void menu(){
}
int main(){
    //计算器-计算加减乘除
    menu()
}