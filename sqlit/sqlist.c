#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "sqlist.h"

sqlist* sqlist_creat(){
    sqlist *me = NULL;
    me = malloc(sizeof(*me));
    if(me == NULL){
        perror("malloc");
        exit(1);
    }
    me->last = -1;
    return me;
};
void sqlist_creat_(sqlist **sqlistprt);
int sqlist_destry(sqlist *);
int sqlist_insert(sqlist *, int index, datatype *);
int sqlist_delete(sqlist *, int index);
int sqlist_fine(sqlist *, datatype *);
int sqlit_isempty(sqlist *);
int sqlit_setempty(sqlist *);
int sqlist_getnum(sqlist *);
int sqlist_union(sqlist *, sqlist *);