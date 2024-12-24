#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>

#define MAXMALLOC   120

ssize_t mygetline(char **linepptr, size_t *n, FILE *stream){
    *linepptr = malloc(((*n/MAXMALLOC) > 0 ? (*n/MAXMALLOC) : (*n/MAXMALLOC+1))*MAXMALLOC);//malloc 返回的视为一个字符数组
    if(*linepptr == NULL){
        perror("*linepptr malloc: ");
        return 0;
    }
    int c = 0;
    size_t count = 0;
    while ((c = getc(stream)) != EOF)
    {
        if((count%MAXMALLOC)+1 >= MAXMALLOC){
            char* new = NULL;
            new = realloc(*linepptr, ((count+1)/MAXMALLOC + 1)*MAXMALLOC);
            if(new == NULL){
                perror("new malloc: ");
                return 0;
            }
            *linepptr = new;
            new = NULL;
        }
        *(*linepptr+count) = c;
        ++count;
        if( c == '\n')
            break;  
    }
    *(*linepptr+count) = '\0';
    *n = (count/MAXMALLOC+1) * MAXMALLOC;
    return count;   
};
int main(int argc, char **argv){
    if(argc < 2){
        fprintf(stderr,"Usage %s <filepath>\n",argv[0]);
        return 0;
    }
    char *lineprt = NULL;
    size_t n = 0;
    FILE * fp = fopen(argv[1], "r");
    if(fp == NULL){
        perror("fopen ");
        exit(-1);
    }
    while (mygetline(&lineprt, &n, fp) > 0)
    {
        printf("%s",lineprt);
        printf("%ld %ld\n", strlen(lineprt), n);
        n = 0;
    }
    free(lineprt);
    fclose(fp);
    return 0;
}