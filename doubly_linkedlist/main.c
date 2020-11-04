#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

int main(void){
    Dll_list * list1 = make_dll_list();
    dll_insert(list1 ,1,1);
    dll_insert(list1 ,1,1);
    print_dll_list(list1);
    delete_dll(list1,1);
    printf("\n");
    print_dll_list(list1);
    printf("\n");
    return 0;
}