//
// Created by 20212 on 2024/4/7.
//
#include <stdio.h>
//int main(){
//    char *a[] = {"www","yyy"};
//    char ** pa =a;
//    pa++;
//    printf("%s\n",*pa);
//}
int main(){
    char* c[] = {"a","b","c","d"};
     char ** cp[] = {c + 3,c+2,c+1};
     char *** cpp =cp;
     printf("%s\n",**++cpp);
}