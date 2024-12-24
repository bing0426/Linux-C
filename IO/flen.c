#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE * fp = NULL;
    fp = fopen("./test.txt", "r");
    if(fp == NULL){
        perror("fopen: ");
        exit(-1);
    }
    fseek(fp, 0, SEEK_END);
    printf("%ld\n", ftell(fp));
    fclose(fp);
    return 0;
}