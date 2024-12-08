//
// Created by 20212 on 2024/4/27.
//
//Flexible array The last element in the structure is allowed to be an array of unknown size

#include <malloc.h>

struct s{
    int n;//4
    int a[];//unknown size
};
int main(){
    //it is expected that the size of a is 10 integers
    struct s* ps = (struct s*)(malloc(sizeof(struct s) + 10*sizeof(int)));
    //flexiblearray carved in heap space
    //Because you can increase or decrease space through realloc
}
