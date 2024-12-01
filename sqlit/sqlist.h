#ifndef SQLIST_H__
#define SQLIST_H__
#define DATASIZE    1024

typedef int  datatype;

typedef struct {
    int last;
    datatype data[DATASIZE];
}sqlist;

sqlist* sqlist_creat();
void sqlist_creat_(sqlist **sqlistprt);
int sqlist_destry(sqlist *);
int sqlist_insert(sqlist *, int index, datatype *);
int sqlist_delete(sqlist *, int index);
int sqlist_fine(sqlist *, datatype *);
int sqlit_isempty(sqlist *);
int sqlit_setempty(sqlist *);
int sqlist_getnum(sqlist *);
int sqlist_union(sqlist *, sqlist *);
#endif