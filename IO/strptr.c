#include <stdio.h>

void print_str(char* pstr){
    printf("%s\n",pstr);
}

void fix(char* pstr){
    *(pstr+1) = 'o';
    printf("%s\n",pstr);
}
int main(){
    char* str = "Hello";
    print_str(str);
    fix(str)
    print_str(str);
    return 0;
}