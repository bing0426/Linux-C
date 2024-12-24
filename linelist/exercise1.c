#include <stdio.h>
#include <stdlib.h>

#define ARRSIZEOF(ARR)  sizeof(ARR)/sizeof(ARR[0])

typedef struct func{
    int num;
    int x;
}func;

typedef struct nohead_link{
    func data;
    struct nohead_link *next;
}nohead_link;

int link_insert(nohead_link **me, func *data){
    nohead_link *node = NULL;
    node = malloc(sizeof(*node));
    if(node == NULL){
        printf("err: malloc err\n");
        return -1;
    }
    node->data = *data;
    node->next = *me;
    *me = node;
    return 0;
}
void link_union(nohead_link *me1, nohead_link *me2){
    for(nohead_link *node2 = me2; node2 != NULL; node2 = node2->next){
        for(nohead_link *node1 = me1; node1 != NULL; node1 = node1->next){
            if(node1->data.x == node2->data.x){
                node1->data.num += node2->data.num;
                break;
            }
            while (node1->next == NULL)
            {
                nohead_link *tmp = NULL;
                tmp = malloc(sizeof(*tmp));
                tmp->data = node2->data;
                tmp->next = NULL;
                node1->next = tmp;
                tmp = NULL;
                break;
            }
        }
    }
};
void link_display(nohead_link *me){
    for(nohead_link* node = me; node != NULL; node = node->next){
        if(node->data.x == 0)
            printf("%d +",node->data.num);
        else
            printf(" %dX^%d +",node->data.num, node->data.x);
    }
    printf("\b");
    printf("\n");
};
void link_destroy(nohead_link *me){
    for(nohead_link* node = me; node != NULL; node = me){
        me = node->next;
        free(node);
    }
};
int main(){
    int arr1[][2] = {{5, 10},{15,8},{7,2},{2,0}};
    int arr2[][2] = {{1,12}, {4,8},{19, 6},{6,2}};
    nohead_link *link_1 = NULL, *link_2 = NULL;
    for(int i = 0; i < ARRSIZEOF(arr1); ++i){
        func f;
        f.num = arr1[i][0];
        f.x = arr1[i][1];
        link_insert(&link_1, &f);
    }
    for(int i = 0; i < ARRSIZEOF(arr2); ++i){
        func f;
        f.num = arr2[i][0];
        f.x = arr2[i][1];
        link_insert(&link_2, &f);
    }
    link_union(link_1, link_2);
    link_display(link_1);
    link_destroy(link_1);
    link_destroy(link_2);
    return 0;
}