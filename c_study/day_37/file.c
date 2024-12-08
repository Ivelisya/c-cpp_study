//
// Created by 20212 on 2024/4/28.
//
//Files are generally divided into program files and data files

//Whenever a file is opened, the system automatically generates a variable of the FILE structure based on the file's condition.
#include <stdio.h>
//int main(){
//    FILE * pf = fopen("../c_study/day_37/txt.data","w");
//    if(pf == NULL){
//            perror("fopen");
//            return 1;
//        }
//    //write file
//    fclose(pf);
//}

int main(){
    FILE*pf = fopen("../c_study/day_37/txt.data","w");
//    fputc('b',stdout);
//    fputc('i',stdout);
    fputs("abcd1ef",pf);
}
//As long as the C language program is run, three streams will be opened by default
//stdin standard input stream keyboard
//stdout standard output stream screen
//stderr standard output stream screen
//int main(){}
