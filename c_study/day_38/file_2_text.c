#include <stdio.h>

//
// Created by 20212 on 2024/4/29.
//
//struct S{
//    char arr[10];
//    int age;
//    float f;
//};
//int main(){
//    struct S s = {"hello",10,5.5f};
//    struct S tmp = {0};
//    char buf[100] = {0};
//    //sprintf convert a formatted data into a string
//    sprintf(buf,"%s %d %f",s.arr,s.age,s.f);
//    sscanf(buf,"%s %d %f",tmp.arr,&(tmp.age),&(tmp.f));
//    printf("%s\n",tmp.arr);
//}
////allocated
//int main(){
//    FILE* pf = fopen("../c_study/day_37/txt.data","r");
//    if(pf == NULL){
//        perror(fopen);
//        return 1;
//    }
//    //read file
//    int st = fgetc(pf);
//    printf("%c\n",st);
//    fseek(pf,-1,SEEK_CUR);
//    //SEEK_CUR current location
//    st = fgetc(pf);
//    printf("%c\n",st);
//    st = fgetc(pf);
//    //Let the file pointer point to the starting position
//    //remind
//    printf("%c\n",st);
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}
//int main(){
//    int a = 10000;
//    FILE* pf = fopen("../c_study/day_37/txt.data","wb");
//}
//feof Used for the end of file reading to determine whether the reading fails or ends when the end of the file is encountered.

//fgetc The function will return EOF when reading is completed. During normal reading, it will return the ASCII code value of the character read.
//fgets The function returns a null pointer when reading ends. During normal reading, it returns the starting address of the string space.
//fread When the function reads, it returns the number of complete elements actually read. If it is found that the number of complete elements read is less than the specified number of elements,
//This is the last read

//feof determine the type of file reading end

//int main(){
//    FILE* pfread = fopen("../c_study/day_38/text.txt","r");
//    if(pfread == NULL){
//        return 1;
//    }
//    FILE *pfwrite = fopen("../c_study/day_38/text.txt_2","w");
//    if(pfwrite == NULL){
//        fclose(pfread);
//        pfread = NULL;
//        return 1;
//    }

//    int ch = 0;
//    while((ch = fgetc(pfread)) != EOF){
//        fputc(ch,pfwrite);
//    }

//    fclose(pfread);
//    pfread = NULL;
//    fclose(pfwrite);
//    pfwrite = NULL;
//    return 0;
//}

