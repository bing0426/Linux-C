#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main(){
    DATATYPE arr[] = {12, 23, 34, 45, 56};
    DATATYPE num = 9;
    linelist *llist = NULL;
    llist = linelist_creat(llist);
    for(int i = 0; i < sizeof(arr)/sizeof(*arr); ++i){
        linelist_insert_at(llist, i, arr+i);
    }
    linelist_display(llist);
    linelist_insert_at(llist, 2, &num);
    linelist_display(llist);
    num = 90;
    linelist_order_insert(llist, &num);
    linelist_display(llist);
    linelist_detel_at(llist, 3);
    linelist_display(llist);
    linelist_destry(llist); 
    return 0;
}