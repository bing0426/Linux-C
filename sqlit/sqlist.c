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
    me->last = 0;
    return me;
};
void sqlist_creat_(sqlist **prt){
    *prt = NULL;
    *prt = malloc(sizeof(**prt));
    if(*prt == NULL){
        perror("malloc");
        exit(-1);
    }
    (*prt)->last = 0;
};
int sqlist_destry(sqlist *me){
    free(me);
    return 0;
};
int sqlist_insert(sqlist *me, int index, datatype *data){
    if(index < 0 || index > me->last || index > DATASIZE - 1){
        printf("%d %d err: index err\n",__LINE__, index);
        exit(-1);
    }
    for(int i = me->last; i > index; --i){
        me->data[i] = me->data[i-1];
    }
    me->data[index] = *data;
    ++(me->last);
};
void sqlist_display(sqlist *me){
    for(int i = 0; i < me->last; ++i){
        printf("%d ",me->data[i]);
    }
    printf("\n");
}
int sqlist_delete(sqlist *me, int index){
    if(index < 0 || index > me->last-1 || index > DATASIZE - 1){
        printf("err: index err\n");
        exit(-1);
    }
    --(me->last);
    for(int i = index; i < me->last; ++i){
        me->data[i] = me->data[i+1];
    }
    return 0;
};
int sqlist_find(sqlist *me, datatype *data){
    for(int i = 0; i < me->last; ++i){
        if(me->data[i] == *data)
            return i;
    }
    return -1;
};
int sqlit_isempty(sqlist *me){
    if(me->last == 0)
        return 1;
    return 0;
};
int sqlit_setempty(sqlist *me){
    me->last == 0;
    return 0;
};
int sqlist_getnum(sqlist *me){
    return me->last;
};
int sqlist_union(sqlist *list1, sqlist *list2){
    for(int i = 0; i < list2->last; i++){
        if(sqlist_find(list1, &(list2->data[i])) < 0){
            sqlist_insert(list1, list1->last, &list2->data[i]);
        }
    }
    return 0;
};