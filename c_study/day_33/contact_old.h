//
// Created by 20212 on 24-4-25.
//
#include <stdio.h>
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30
#define MAX 1000
//
//typedef [existing_data_type] [new_data_type_name];
//typedef 是 C 语言中用来为已有的数据类型定义新的名称的关键字
typedef struct PeoInfo{
    char name[MAX_NAME];
    char sex[MAX_SEX];
    int age;
    char tele[MAX_TELE];
    char addr[MAX_ADDR]
}PeoInfo;//给struct PeoInfo重命名为PeoInfo
typedef struct Contact{
    PeoInfo data[MAX];//存放添加进来人的信息
    int sz;//记录当前通讯录中有效信息的个数
}Contact;