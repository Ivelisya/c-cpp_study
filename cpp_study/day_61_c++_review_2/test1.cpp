//校招最看重你的基础功底知识以及你的潜力
#include <iostream>
using namespace std;
int main(){
    int a[] = {1,2,3,5};
    printf("%d\n", sizeof(a));//16
    printf("%d\n", sizeof(a+0));//4
    printf("%d\n", sizeof(*a));
    printf("%d\n", sizeof(a+1));
    printf("%d\n", sizeof(a[1]));
    printf("%d\n", sizeof(&a));
    printf("%d\n", sizeof(*&a));
    printf("%d\n", sizeof(&a+1));
    printf("%d\n", sizeof(&a[0]));
    printf("%d\n", sizeof(&a[0]+1));
    printf("-------------------\n");
    char arr[] = {'a','b','c','d','e','f'};
    printf("%d\n", sizeof(arr));//6
    printf("%d\n", sizeof(arr+0));//4
    printf("%d\n", sizeof(*arr));
    printf("%d\n", sizeof(arr[1]));
    // printf("%d\n", sizeof(&arr));
    printf("%d\n", sizeof(&arr+1));
    printf("%d\n", sizeof(&arr[0]+1));
    return 0;
}