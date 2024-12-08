//
// Created by 20212 on 3/10/2024.
//
//局部变量和全局变量冲突，局部变量优先
//strlen（）求字符串长度
//\n 换行符
//创建数组时表达式必须含有常量
//c99标准中引入 支持数组在创建的时候，用变量指定大小的，但是这个数组不能初始化
//一般编程时不把变量名写成全大写，因为全大写一般是宏定义
//define不是关键字，是预处理指令
//sizeof也不是关键字，因为sizeof是一个运算符
//指针类型一般是四个或者八个字节
//static修饰的变量也可以修改
#if 0 
//#include <stdio.h>
//int Max(int x,int AlgorithmExercises){
//    return x > AlgorithmExercises ? x : AlgorithmExercises;
//}
//int main(){
//    int a = 10;
//    int b = 20;
//    float c = 1.0;
//     scanf("%d%d",&a,&b);
//    int m = Max(a,b);
//    printf("m = %d\n",m);
//}
//c语言是结构化程序设计语言
//顺序结构 选择结构 循环结构
//分支语句 if switch 循环语句 while do while for
//c语言中一个分号代表一条语句


//c语言表示1 真 0 表示假
//if(表达式) 语句
//#include <stdio.h>
//int main(){
//    int age =10;
//    if(age >= 18){
//        printf("成年\n");
//}else{
//    printf("未成年\n");
//}
//    return 0;
//}
//
#include <stdio.h>
//int main(){
//    for(int i = 1;i <= 100;i+=2){
//        if(i % 2 ==1){
//        printf("i = %d\n",i);}
//    }
//}

//
//swtich用于多分支环境
//int main(){
//    int day_14 = 0;
//    &取地址符,当你使用 scanf("%d", &day_14); 时，你实际上是告诉 scanf 函数将输入的整数存储在 day_14 变量的内存地址中
//当你int 初始化一个变量时，会给这个变量分配一个内存地址
//scanf是将输入的值赋值给变量,本质是把这个值放到变量的内存地址中
//swich语句中的case后面的值必须是常量
//swich必须使用整型或者字符型,因为字符型底层是ASCII码,也是整型
//default是可选的,默认选项,当所有的case都不满足时,执行default
//    scanf("%d",&day_14);
//    switch(day_14){
//        case 1:
//            printf("星期一\n");
//            break;
//        case 2:
//            printf("星期二\n");
//            break;
//        case 3:
//            printf("星期三\n");
//            break;
//        case 4:
//            printf("星期四\n");
//            break;
//        case 5:
//            printf("星期五\n");
//            break;
//        case 6:
//            printf("星期六\n");
//            break;
//        case 7:
//            printf("星期日\n");
//            break;
//        default:
//            printf("输入错误\n");
//            break;
//    }
//}

//switch允许嵌套
//int main(){
//    int n =1;
//    int m = 2;
//    switch (n){
//        case 1:
//            m++;
//case 2:
//    n++;
//    case 3:
//        switch(n){
//            case 1:
//                n++;
//            case 2:
//                m++;
//                break;
//        }
//    }
//    printf("m = %d,n = %d\n",m,n);
//}

//
//
//
//switch 中break是跳出当前的switch语句
//int main(){
//    int n = 1;
//    int m = 2;
//    switch(n){
//        case 1:
//            m++;
//            break;
//        case 2:
//            n++;
//            break;
//        case 3:
//            switch(n){
//                case 1:
//                    n++;
//                case 2:
//                    m++;
//                    break;
//            }
//    }
//    printf("m = %d,n = %d\n",m,n);
//}

//while 循环在while循环中break代表永久跳出循环 continue代表跳出本次循环
//int main(){
//    int i = 1;
//    while(i <= 10){
//        if (i ==5 ){
//            printf("hello world %d\n",i);
//            break;
//        }
//        printf("hello world %d\n",i);
//        i ++;
//    }
//}
//getchar 获取一个字符
//  EOF -> end of file文件结束的标志
//int main(){
////    int ch = 0;
////    int ch = getchar();
////    while((ch = getchar()) != EOF){
////    printf("%c\n",ch);
////putchar(ch);
////    }
//    int ch = 0;
//    while((ch = getchar() !=(-1))){
//        putchar(ch);
//    }
//}
//键盘和getchar之间有个缓存区,当键盘输入一个字符时,会先放到缓存区,当按下回车键时,getchar才会从缓存区取出一个字符
//int main(){
//    int ch = 0;
//    while((ch = getchar()) != EOF){
//        putchar(ch);
//    }
//}
int main(){
    // printf("请输入密码");
    // char password[30] = {0};
    // scanf(" %s",password);
    printf("请确认密码\n");
    int ch = getchar();
    int i = 1;
    while(i) {
        if (ch == 'Y') {
            printf("密码正确\n");
            i = 0;
        } else {
            printf("密码错误\n");
            continue;
        }
    }
//    这里password没有取地址,因为password本身就是一个数组名,数组名就是数组的首地址
//    scanf("%s",password);
}

#endif













