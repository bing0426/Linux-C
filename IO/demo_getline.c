#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
    if(argc < 2){
        fprintf(stderr, "Usage %s <filepath> \n", argv[0]);
        return 0;
    }
    FILE *fp = NULL;
    char *lineptr = NULL;
    size_t n = 360;
    fp = fopen(argv[1], "r");
    if(fp == NULL){
        perror("fopen ");
        exit(-1);
    }
    while (getline(&lineptr, &n, fp) >= 0)
    {
        printf("%s\n", lineptr);
        printf("%ld\n", strlen(lineptr));
        printf("%ld\n", n);
        printf("------\n");
        lineptr = NULL;
        n = 0;
    }
    fclose(fp);
    return 0;
}