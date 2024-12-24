#include <stdio.h>
#include <stdlib.h>


int main(){
    int n = 0;
    FILE * fp = NULL;
    char arr[] = "Hello fseek !";
    fp = fopen("./test.txt", "w+");
    if(fp == NULL){
        perror("fopen: ");
        exit(-1);
    }
    for(int i = 0; arr[i] != '\0'; ++i){
        fputc(arr[i], fp);
    }
    fseek(fp, -(sizeof(arr)/sizeof(arr[0]) - 1), SEEK_CUR);
    while((n = fgetc(fp)) != EOF)
        printf("%c",n);
    putc('\n', stdout);
    fclose(fp);
    return 0;
}