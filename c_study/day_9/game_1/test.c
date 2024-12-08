//
// Created by 20212 on 2024/3/21.
//
#include <stdio.h>
#include "game.h"
void game() {
    //存储数据 -二维数组
    char board[ROW][COL];
//   初始化棋盘 - 初始化空格
    InitBoard(board, ROW, COL);
//    打印棋盘
    DisplayBoard(board, ROW, COL);
//    填入棋子
//    与电脑判断胜负
    char ret = '0';//获取游戏状态
    while (1) {
        // 玩家下棋
        PlayerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        ret = IsWin(board, ROW, COL);
        if (ret != 'C') { // 如果游戏结束（玩家赢、电脑赢或平局）
            break; // 跳出循环
        }
        // 电脑下棋
        ComputerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        ret = IsWin(board, ROW, COL);
        if (ret != 'C') { // 如果游戏结束（玩家赢、电脑赢或平局）
            break; // 跳出循环
        }
    }

// 循环外：游戏已结束，现在判断是谁赢了或是否平局
    if (ret == '*') {
        printf("玩家赢。\n");
    } else if (ret == '#') {
        printf("电脑赢。\n");
    } else if (ret == 'Q') {
        printf("平局。\n");
    }
}
void menu(){
    printf("**************************\n");
    printf("*******  1.play  *********\n");
    printf("*******  0.exit  *********\n");
    printf("**************************\n");
}
int main(){
    int input = 0;
    srand((unsigned int) time(NULL));
    do{
        menu();
        printf("请选择:>");
        scanf("%d",&input);
        switch(input){
            case 1:
                printf("三字棋游戏\n");
                game();
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("输入错误，请重试\n");
                break;
        }
    }while(input);
}