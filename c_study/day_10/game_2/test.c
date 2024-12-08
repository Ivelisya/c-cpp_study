//
// Created by 20212 on 2024/3/22.
//
#include "game.h"
//1.布置雷
//2.排查雷
void game(){
    srand((unsigned int)time(NULL));
    char mine[ROWS][COLS] = {0};
    char show[ROWS][COLS] = {0};
    InitBoard(mine,ROWS,COLS,'0');
    InitBoard(show,ROWS,COLS,'*');

//    DisPlayBoard(mine,ROW,COL);
//    排查雷
    SetMine(mine,ROW,COL);
//    DisPlayBoard(show,ROW,COL);
    DisPlayBoard(mine,ROW,COL);


}
void menu(){
    printf("****************************\n");
    printf("****************************\n");
    printf("******   1.paly   **********\n");
    printf("******   2.exit   **********\n");
    printf("****************************\n");
}
int main(){
    int input = 0;
    do {
        menu();
        printf("请选择:>\n");
        scanf("%d", &input);
        switch (input) {
            case 1:
                printf("扫雷\n");
                game();
                break;
            case 0:
                printf("退出\n");
                break;
            default:
                printf("输入错误请重新输入\n");
                break;
        }
    } while (input);
}