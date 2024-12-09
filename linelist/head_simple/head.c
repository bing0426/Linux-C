#include "head.h"
#include <stdlib.h>
#include <stdio.h>

linelist * linelist_creat(linelist *me){
    me = NULL;
    me = malloc(sizeof(*me));
    if(me == NULL){
        printf("err: malloc err\n");
        exit(-1);
    }
    me->next = NULL;
    return me;
};
void linelist_destry(linelist *me){
    linelist *next = me->next;
    for(linelist *node = next; node != NULL; node = next){
        next = node->next;
        free(node);
    }
    free(me);
};
int linelist_insert_at(linelist *me, int index, DATATYPE *data){
    if(index < 0){
        printf("err: index cannot be negative \n");
        exit(-1);
    }
    int i = index;
    int j = 0;
    linelist *node = me;
    linelist *temp = NULL;
    for(j; j < i && node->next != NULL; ++j){
        node = node->next;
    }
    temp = node->next;
    node->next = malloc(sizeof(*node));
    if(node->next == NULL){
        printf("%d err: malloc err", __LINE__);
        exit(-1);
    }
    (node->next)->data = *data;
    (node->next)->next = temp;
    return ;
};
int linelist_order_insert(linelist *me, DATATYPE *data){
    linelist *node = me->next;
    while(node->next != NULL){
        node = node->next;
    }
    node->next = malloc(sizeof(*me));
    if(node->next == NULL){
        printf("%d err: malloc err\n", __LINE__);
        exit(-1);
    }
    (node->next)->data = *data;
    (node->next)->next = NULL;
    return ;
};
int linelist_detel_at(linelist *me, int index){
    if(index < 0){
        printf("err: invalid index !\n");
        exit(0);
    }
    int i = index;
    linelist *tmp = NULL;
    linelist *node = me;
    for(int j = 0; j < index; ++j){
        node = node->next;
    }
    tmp = node->next;
    node->next = tmp->next;
    free(tmp);
    return 1;
};
int linelist_isempty(linelist *me){
    if(me->next == NULL)
        return 1;
    return 0;
};
void linelist_display(linelist *me){
    linelist *node = me->next;
    while(node->next != NULL){
        printf("%d ",node->data);
        node = node->next;
    }
    printf("%d\n",node->data);
};