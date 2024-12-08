//
// Created by 20212 on 2024/4/29.
//

#include <stdio.h>
//struct S{
//    char arr[10];
//    int num;
//    float sc;
//};
//int main(){
//    struct S s= {"abcdef",10,5.5f};
////"../c_study/day_37/txt.data"
//    FILE*pf = fopen("../c_study/day_37/txt.data","r");
//    if(pf == NULL){
//        perror("fopen");
//        return 1;
//    }
////    fprintf(pf,"%s %d %f",s.arr,s.num,s.sc);
//    fscanf(pf,"%s %d %f",s.arr,&(s.num),&(s.sc));
//    printf("%s %d %f",s.arr,s.num,s.sc);
//
//    //program output file writing
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}
struct S{
    char arr[10];
    int num;
    float sc;
};
int main(){
//    struct S s= {"abcdef",10,5.5f};
    struct S s= {0};

    FILE*pf = fopen("../c_study/day_37/txt.data","r");
    if(pf == NULL){
        perror("fopen");
        return 1;
    }
//    fwrite(&s,sizeof(struct S),1,pf);
    fread(&s,sizeof(struct S),1,pf);
    printf("%s %d %f\n",s.arr,s.num,s.sc);
}

