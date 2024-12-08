//
// Created by 20212 on 3/9/2024.
//
//typedef 类型重定义
#include <stdio.h>
//typedef unsigned int uint;
//int main(){
//    uint a;
//    a = -10;
//    printf("%d\n",a);
//    return 0;
//}
//static --静态变量
//1.修饰全局变量
//2.修饰局部变量
//3.修饰函数
//int main(){
//    int a = 0;
//    a ++;
//    printf("a = %d\n",a);
//}
//static修饰局部变量，改变了局部变量的生命周期（本质上是改变了变量的存储类型）
//void test(){
//    static int a = 0;//静态变量只初始化一次,不销毁，生命周期和程序一样长
//    a ++;
//    printf("a = %d\n",a);
//}
//int main(){
//    int i = 0;
//    while(i < 10){
//        test();
//        i ++;
//    }
//}
//static 修饰全局变量，使这个全局变量只能在自己所在的源文件使用
//static也可以将函数的链接属性改为内部链接属性（和static修饰全局变量一样）
//全局变量可以在其它源文件内部使用，是因为全局变量有外部链接属性，但是被static修饰后，全局变量就只能在自己所在的源文件内部使用，只有内部链接属性，其他源文件不能链接到了
//define预处理指令
//1define定义符号
//2define定义宏
//extern int g_val;
//extern int Add(int,int);
//int main(){
//    int a = 3;
//    int b = 4;
//    int c = Add(a,b);
//    printf("c = %d\n",c);
//    printf("g_val = %d\n",g_val);
//    return 0;
//}
//宏是一种通过预处理器进行定义的指令，它们在编译程序之前被处理。宏可以被用来定义文本替换的规则，这些规则告诉预处理器在实际编译之前将程序中的某些文本替换为不同的文本

//#define Add(x,AlgorithmExercises) (x+AlgorithmExercises)
//int main(){
//    int a = 3;
//    int b = 4;
//    int c = 4 * Add(a,b);
//    printf("c = %d\n",c);
//    return 0;
//}
