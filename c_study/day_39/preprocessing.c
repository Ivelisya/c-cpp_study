//
// Created by 20212 on 07/05/2024.
//
//
/**

#include <stdio.h>

int main() {
    printf("%s\n", __FILE__);
    printf("%d\n", __LINE__);
    printf("%s\n", __DATE__);

    int i = 0;
    FILE *pf = fopen("log.txt", "a+");
    if (pf == NULL) {
        perror("fopen\n");
        return 1; // 如果文件打开失败，返回错误码并退出程序
    }

    for (i = 0; i < 10; i++) {
        fprintf(pf, "%s %d %s\n", __FILE__, __LINE__, __DATE__);
    }

    fclose(pf);
    pf = NULL;
    return 0;
}

//#define SQUARE(x) x*x //宏和define都是替换文本，所以不用加;
//define是完全替换
//define 定义宏 括号很重要
#include <stdio.h>
#define M 1000
#define add(x,y) x + y
int main(){
    int i  = add(1,2);
    printf("%d\n",i);
}
**/
#include <stdio.h>
// #define PRINT(x,format) printf("the val of " #x /*#x代表x所对应的字符串*/ " is " format,x)
// int main(){
//     int a = 10;
//     int b = 20;
//     PRINT(a,"%d");
// }
//define 完全替换 #只能用于宏 将宏对应的变量的字符串名字
//##合并

#define CAT(X,Y) X##Y
int main(){
    int class101 = 100;
    printf("%d\n",CAT(class,101));
}