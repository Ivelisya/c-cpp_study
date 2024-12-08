//
// Created by 20212 on 2024/3/22.
//

#include "game.h"
void InitBoard(char board[ROWS][COLS],int rows,int cols,char set){
    int i = 0;
    int j = 0;
    for(i = 0;i < rows; i++){
        for (j = 0;j < cols;j++){
            board[i][j] = set;
        }
    }
}
void DisPlayBoard(char board[ROWS][COLS],int row,int col){
    int i = 0;
    int j = 0;
    printf("-----扫雷游戏------\n");
    for (i = 0;i<=col;i++){
        printf( "%d ",i);
    }
    printf("\n");
    for(i = 1;i <= row;i++){
        printf("%d",i);//打印行
        for(j = 1;j <= col;j++){
            printf(" %c",board[i][j]);
        }
        printf("\n");
    }
}
void SetMine(char mine[ROWS][COLS],int row,int col){
//    布置十个雷
    int count = 10;
    while(count){
        int x = rand()%row + 1;
        int y = rand()%col + 1;
        if(mine[x][y] == '0'){
            mine[x][y] = '1';
            count--;
        }
    }
}