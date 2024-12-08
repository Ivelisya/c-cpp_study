//
// Created by 20212 on 24-4-11.
//
#include <stdio.h>
void swap(char*e1,char *e2,int width){
    int i = 0;
    for(i = 0;i < width;i++){
        char temp = *e1;
        *e1 = *e2;
        *e2 = temp;
        e1 ++;
        e2 ++;
    }
}
 void bubble_sort(void *base,
                  int sz,
                  int width,
                  int (*cmp)(const void*e1,const void*e2)){
    int i = 0;
    for(i = 0;i < sz -1;i++){
        int j =0;
        for(j = 0;j < sz -1 - i;j++){
            if(cmp((char*)base + j*width,(char*)base + (j+1)*width)>0){
                //交换
                swap((char*)base +j*width,(char*)base + (j+1)*width,width);
            }
        }
    }
}
int cmp_int(const void*e1,const void*e2){
    return *(int*)e1 - *(int*)e2;
}
int main(){
    int arr[] = {1,22,13,34,95};
    int sz = sizeof(arr)/sizeof(arr[0]);
    int width = sizeof(arr[0]);
    bubble_sort(arr,sz,width,cmp_int);
    int i = 0;
    for(i;i < sz;i++){
        printf("%d\n",arr[i]);
    }
}