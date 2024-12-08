//
// Created by 20212 on 24-4-25.
//

#include "C_study/day_33/contact_old.h"
void menu(){
    printf("************************************");
    printf("*******1.add ****** 2.del*********************");
    printf("*******3.search*****4.modify*******************");
    printf("*******5.sort ******6.print*********************");
    printf("*******0.exit****************************");
    printf("************************************");
}
enum Option{
    EXIT,
    ADD,
    DEL,
    SEARCH,
    SORT,
    PRINT
};
int main(){
    int input = 0;
    PeoInfo data[MAX];
    int sz = 0;
    do{
        menu();
        printf("请选择 ：->");
        scanf("%d",&input);
        switch(input){
            case ADD:
                //增加人的信息
                AddContact();
                break;
            case DEL:
                break;
            case SEARCH:
                break;
            case SORT:
                break;
            case PRINT:
                break;
        }

    }while(input != EXIT);
    return 0;
}