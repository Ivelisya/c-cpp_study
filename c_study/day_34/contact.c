#include "contact.h"
void InitContact(Contact *pc){
    pc -> sz = 0;
    //memset() 内存设置
    //data是数组名，指向首元素空间的地址
    memset(pc -> data,0,sizeof(pc -> data));
}
void AddContact(Contact *pc){
    if(pc -> sz == MAX){
        printf("通讯录已满，无法添加");
        return;
    }
    //增加一个人的信息
    printf("请输入名字>");
    scanf("%s",pc -> data[pc->sz].name);//name是一个数组，所以不需要取地址
    printf("请输入年龄>");
    scanf("%d",&(pc -> data[pc -> sz].age));
    printf("请输入性别>");
    scanf("%s",pc -> data[pc->sz].sex);
    printf("请输入电话>");
    scanf("%s",pc -> data[pc->sz].tele);
    printf("请输入地址>");
    scanf("%s",pc -> data[pc->sz].addr);
    pc -> sz ++;
    printf("添加成功\n");
}
void PrintContact(const Contact *pc){
    int i = 0;
    //打印标题
    printf("%10s\t%10s\t%10s\t%12s\t%10s\t\n","名字","年龄","性别","电话","地址");
    for(i = 0;i < pc -> sz;i++){
        printf("%10s\t%10d\t%10s\t%12s\t%10s\t\n",
               pc ->data[i].name,
               pc ->data[i].age,
               pc -> data[i].sex,
               pc -> data[i].tele,
               pc -> data[i].addr
        );
    }
}
static int FindByName(Contact * pc,char name[]){
    int i = 0;
    for(i = 0;i < pc -> sz;i++) {
        if(strcmp(pc->data[i].name,name) == 0){
            //strcmp 若字符串相同返回0
            return i;
        }
    }
    return -1;
}
void DelContact(Contact *pc){
    char name[MAX_NAME] = {0};
    if(pc -> sz == 0){
        printf("通讯录为空\n");
        return;
    }
    //1.查找
    //有或者没有
    printf("请输入要删除人的名字:>");
    scanf("%s",name);
    int pos = FindByName(pc,name);
    if (pos == -1){
        printf("要删除的人不存在\n");
        return;
    }
    //2.删除
    int i = 0;
    for(i = pos;i < pc -> sz-1;i++){
        pc -> data[i] = pc -> data[i+1];
    }
    pc -> sz--;//sz代表通讯录人数
    printf("删除成功\n");
}
void SearchContact(Contact *pc){
    char name[MAX_NAME] = {0};
    if(pc -> sz == 0) {
        printf("通讯录为空\n");
        return;
    }
    printf("请输入要查找人的名字:>");
    scanf("%s",name);
    int pos = FindByName(pc,name);
    if (pos == -1){
        printf("要查找的人不存在\n");
        return;
    }
    printf("%10s\t%10s\t%10s\t%12s\t%10s\t\n","名字","年龄","性别","电话","地址");
    printf("%10s\t%10d\t%10s\t%12s\t%10s\t\n",
           pc ->data[pos].name,
           pc ->data[pos].age,
           pc -> data[pos].sex,
           pc -> data[pos].tele,
           pc -> data[pos].addr);
    printf("查找成功\n");
}
void ModifyContact(Contact *pc){
    char name[MAX_NAME] = {0};
    if(pc -> sz == 0) {
        printf("通讯录为空\n");
        return;
    }
    printf("请输入要修改人的名字:>");
    scanf("%s",name);
    int pos = FindByName(pc,name);
    if (pos == -1){
        printf("要修改的人不存在\n");
        return;
    }
    printf("请输入名字>");
    scanf("%s",pc -> data[pos].name);//name是一个数组，所以不需要取地址
    printf("请输入年龄>");
    scanf("%d",&(pc -> data[pos].age));
    printf("请输入性别>");
    scanf("%s",pc -> data[pos].sex);
    printf("请输入电话>");
    scanf("%s",pc -> data[pos].tele);
    printf("请输入地址>");
    scanf("%s",pc -> data[pos].addr);
    pc -> sz ++;
    printf("查找成功\n");
}
void SortContact(Contact *pc) {
    if (pc->sz == 0) {
        printf("通讯录为空\n");
        return;
    }
    int i, j;
    char *temp = NULL;
    for (i = 0; i < pc->sz - 1; i++) {
        for (j = 0; j < pc->sz - i - 1; j++) {
            // 比较电话号码的首位数字
            if (pc->data[j].tele[0] > pc->data[j + 1].tele[0]) {
                // 交换电话号码
                //strdup 复制一个字符串，并返回新字符串的地址
                temp = strdup(pc->data[j].tele);
                strcpy(pc->data[j].tele, pc->data[j + 1].tele);
                strcpy(pc->data[j + 1].tele, temp);
                free(temp);
            }
        }
    }
}