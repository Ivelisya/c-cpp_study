//
// Created by 20212 on 2024/3/20.
//
//递归与迭代
#include <stdio.h>
//int Fac(int n){
//    if(n <= 1){
//        return 1;
//    }
//    else
//        return n * Fac(n - 1);
//}
////有些功能可以用迭代或者递归完成
//int main(){
//    int n = 0;
//    scanf("%d",&n);
//    int ret = Fac(n);
//    printf("%d",ret);
//    return 0;
//};
//long long int count = 0;
//long long int Fid(long long int n){
////    if (n == 3){
//        count++;
//    }
//    if ( n <= 2){
//        return 1;
//    }
//    else{
//        return Fid(n - 1) + Fid(n - 2);
//    long long int a = 1,b=1,c = 1;
//    while(n>2){
//        c = a + b;
//        a = b;
//        b = c;
//        n--;
//    }
//    return c;
//}
//int main(){
//    long long int n = 0;
//    scanf("%lld",&n);
//    long long int ret = Fid(n);
//    printf("%lld\n",ret);
//}