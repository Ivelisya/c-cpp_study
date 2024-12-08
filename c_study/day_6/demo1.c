//
// Created by 20212 on 3/12/2024.
//
//写一个猜数字游戏
//1.自动产生一个1-100的随机数
//2.猜数字
//a.恭喜你猜对了，游戏结束
//b.你猜错了就会告诉你猜大了还是小了
//3。这个游戏可以一直完，除非你退出游戏
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void menu(){
    printf("1.play\n");
    printf("0.exit\n" );
}
void game(){
    //猜数字游戏的实现
    int guess;
    int ret = rand() % 100 +1;//rand返回0-32767  %100+1范围就是1-100
//    随机数有个起点
    while(1){
        printf("猜数字/n");
        scanf("%d",&guess);
        if(guess<ret){
            printf("猜小了");

        }
        else if(guess>ret){
            printf("猜大了");
        }
        else{
            printf("猜对了");
            break;
        }
    }
}
int main(){
//    time返回整数类型 我们不使用time的参数   
//
    srand((unsigned int)time(NULL));
        int input;
        do {
            menu();
            printf("请选择");
            scanf("%d", &input);
            switch (input) {
                case 1:
                    game();
                    break;
                case 0:
                    printf("退出游戏");
                    break;
                default:
                    printf("重新选择");
                    break;
            }
        }while(input);
        return 0;
}