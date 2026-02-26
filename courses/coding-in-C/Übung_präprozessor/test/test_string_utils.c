#include <assert.h>
#include "../include/string_utils.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    /*test for costume_len*/
    assert(custom_len("Schule") == 5);
    printf("Tests erfolgreich.\n");
    return 0;
}