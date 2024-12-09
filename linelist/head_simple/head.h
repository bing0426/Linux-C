#ifndef HEAD_H__
#define HEAD_H__

typedef int DATATYPE;
typedef struct linelist{   
    DATATYPE data;
    struct linelist *next;
}linelist;

linelist * linelist_creat(linelist *);
void linelist_destry(linelist *);
int linelist_insert_at(linelist *, int index, DATATYPE *);
int linelist_order_insert(linelist *, DATATYPE *);
int linelist_detel_at(linelist *, int index);
int linelist_isempty(linelist *);
void linelist_display(linelist *);

#endif