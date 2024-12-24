#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* fp = NULL;
    fp = fopen("./test.txt", "w");
    if(fp == NULL){
        perror("fopen ");
        exit(-1);
    }
    fseek(fp, 1024, SEEK_SET);
    fclose(fp);
    return 0;
}