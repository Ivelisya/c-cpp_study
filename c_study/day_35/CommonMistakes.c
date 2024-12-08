#include <stdlib.h>
//
// Created by 20212 on 2024/4/26.
//
//common mistakes in dynamic memory opening
//1.dereference a null pointer
//int main(){
//    int*p = (int*)malloc(18888899990000);
//    //check whether the return value of malloc is null
//    int i = 0;
//    for(i;i<10;i++){
//        *(p+i) = i;
//    }
//    return 0;
//}
//2.out of bounds access
//3.Use free to free up space that is not dynamically carved
//int main(){
//    int arr[10] = {0};
//    int * p = arr;
//    free(p);
//}
//4. Use free to release a portion of the dynamic memory
//
//int main(){
//    int *p = malloc(10*sizeof(int));
//    if(p == NULL){
//        return 1;
//    }
//    int i = 0;
//    for (i = 0;i < 5;i ++){
//        *p++;
//    }
//    free(p);
//}
//5. Multiple releases of the same dynamically opened space

//6，The dynamically opened space forgets to release memory leak
//dynamic opened space   two ways to recycle
// first way Active release
//second way end of program
