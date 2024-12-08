//
// Created by 20212 on 3/11/2024.
//
//do while循环
#include <stdio.h>
//do 循环语句 while（表达式）；
//int mian(){
//    int i = 1;
//    do
//    {
//    printf("%d",i);
//    i ++;
//    }while(i <= 10);
//    return 0;
//}
//int main(){
//    int i = 1;
//    do {
//        if (i ==5)//如果if里面只有一个代码则不用{}
//            continue;
//        printf("%d",i);
//        i ++;
//    }while(i<=10);
//}
//int main(){
//    int number;
//    scanf("%d",&number);
//    switch(number){
//        case 1:
//            printf("hello 1");
//            break;
//        default:
//            printf("你好");
//    }
//}
//int main(){
//    int n = 0;
//    int num = 1;
//    int sum;
//    do{
//        sum = num*n;
//        n ++;
//        printf("%d\n",sum);
//    }while(n<=10);
//}
//int main(){
//    int n = 1;
//    int ret = 1;
//    do{
//        ret *= n;
////        printf("%d\n",ret);
//        n ++;
//        printf("%d\n",ret);
//    }while(n <= 10);
//int main(){
//    int i = 0;
//    int n =0;
//    int ret = 1;
//    scanf("%d",&n);
//    int num =0;
//    for(i=1;i<=n;i++){
//        ret *=i;
//        num += ret;
//    };
//    printf("%d",num);
//};
//int main(){
////    123456789 10
////折半查找 二分查找 效率更高
//    int arr[] = {1,2,3,4,5,6,7,8,9,10};
//    int k = 7;
////    在arr这个有序的数组中查找k（7）的值
//    int sz = sizeof(arr) / sizeof(arr[0]);//数组元素的个数
//    int left = 0;
//    int right = sz-1;
//    while(left <= right) {
//        int mid = (left + right) / 2;
//        if (arr[mid] < k) {
//            left = mid + 1;
//        } else if (arr[mid] > k) {
//            right = mid - 1;
//        } else {
//            printf("找到了下标为%d", mid);
//            break;
//        }
//    }
//    if (left > right){
//        printf("找不到了\n");
//
//    }
//    return 0;
////    1 2 3 4 5 6 7 8 9 10
////   left0              right9
//
//}
#include <string.h>
#include <windows.h>
//int main(){
//    char arr1[] = "welcome to bit!!!!!!";
//    char arr2[] = "####################";
//    int left = 0;
////    strlen用于计算字符串的长度
//    int right = strlen(arr1) - 1;
//    while(left <= right)
//    {
//        arr2[left] = arr1[left];
//        arr2[right] = arr1[right];
//        printf("%s\n", arr2);
//        Sleep(1000);
//        system("cls");
//
//        left++;
//        right--;
//    }
//    return 0;
//}
//int main(){
//    int i = 0;
//    char password[20] = {0};
//password本来就是一个地址的第一位元素
//    for(i=0;i<3;i++){
//        printf("请输入密码");
//        scanf("%s",&password);
//这是在比较两个首字母字符的地址
//        //        if(password == "123456")err两个字符串不能直接比较，应该用strcmp
//比较对应的ASCII码值
//        if(strcmp(password,"123456") == 0){
//            printf("登入成功\n");
//            break;
//        }
//        else{
//            printf("密码错误，重新输入! ")
//        }
//    }
//    if(i==3){
//        printf("三次密码错误，退出程序\n");
//    }
//}
