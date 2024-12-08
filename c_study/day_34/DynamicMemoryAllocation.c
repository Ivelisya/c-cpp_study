//
// Created by 20212 on 24-4-26.
//
/**
    StackArea LocalVariables FunctionParameters
    HeapArea DynamicMemoryAllocation
    malloc calloc
    free realloc
    staticArea
    global variables
    static variables
**/
#if 0 
#include <malloc.h>
#include <stdio.h>
//DynamicMemoryAllocation
int main(){
    //assume allocate 10 int area
    int arr[10];//StackArea
    //allocated by dynamic
    //malloc request on an available space
    //calloc initialize the memory address to 0
    //realloc reopen the space
    int *p = (int*)malloc(10*sizeof(int));//default void*
    //realloc A null pointer may be returned, and returning a null pointer will lose the old address
    if (p == NULL){
        perror("main");
        return 0;
    }
    //use this area
    int i;
    for (i=0;i<10;i++){
        *(p + i) = i;
    }
    //reclaim space
    free(p);
    //free can only be used to free up dynamic carved space
    p = NULL;
    //malloc --> free appears in pairs
    return 0;//do it yourself,set p as a null pointer
}
#endif