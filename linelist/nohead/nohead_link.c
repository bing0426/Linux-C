#include <stdio.h>
#include <stdlib.h>

#define NAMESIZE    32

typedef struct Student{
    int id;
    char name[NAMESIZE];
    int math;
}Student;
typedef struct nohead_link
{
    Student data;
    struct nohead_link *next;
}nohead_link;

int link_insert(nohead_link** me, Student* student){
    nohead_link *node = NULL;
    node = malloc(sizeof(nohead_link));
    if(node == NULL){
        printf("err: malloc err");
        return -1;
    }
    node->data = *student;
    node->next = *me;
    *me = node;
    return ;
};
Student * link_find(nohead_link* me, int id){
    for(nohead_link* node = me; node != NULL; node = node->next){
        if(node->data.id = id)
            return &(node->data);
    }
    return NULL;
}
void link_display(nohead_link* me){
    for(nohead_link *node = me; node != NULL; node = node->next){
        printf("%d %s %d \n", node->data.id, node->data.name, node->data.math);
    }
};

void link_destroy(nohead_link* me){
    for(nohead_link* node = me; node != NULL; node = me){
        me = node->next;
        free(node);
    }
}
int main(){
    nohead_link *list = NULL;
    for(int i = 0; i < 6; ++i){
        Student s;
        s.id = i;
        s.math = rand()%100;
        snprintf(s.name,NAMESIZE,"stu%d", i);
        link_insert(&list, &s);
    }
    link_display(list);
    int id =4;
    Student *st = NULL;
    st = link_find(list, id);
    printf("%d %s %d\n",st->id, st->name, st->math);
    link_destroy(list);
    return 0;
}