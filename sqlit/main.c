#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"


int main(){
    datatype arr[] = {12, 23, 34, 45, 56};
    datatype arr1[] = {34, 45, 67, 78,89};
    sqlist *list = NULL, *list1 = NULL;
    list = sqlist_creat(list1);
    sqlist_creat_(&list1);
    printf("%d %ld \n", __LINE__, sizeof(arr)/sizeof(*arr));
    for(int i = 0; i < sizeof(arr)/sizeof(*arr); ++i){
        sqlist_insert(list, i, arr+i);
    }
    printf("%d %ld \n", __LINE__, sizeof(arr1)/sizeof(*arr1));
    for(int i = 0; i < sizeof(arr1)/sizeof(*arr1); ++i){
        sqlist_insert(list1, i, arr1+i);
    }
    sqlist_display(list);
    sqlist_display(list1);
    sqlist_union(list, list1);
    sqlist_display(list);
    sqlist_destry(list);
    sqlist_destry(list1);
    return 0;
}