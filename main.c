// This program aims to help track the time spent on uni modules during a semester. 10 creds = 100hr needed, 20 creds = 200hr needed

#include <stdio.h>
#include <stdlib.h>
#include "headers/fileRDR.h"
#include "headers/dataSTRUC.h"

int main(){

    if(checks() == -1){return -1;} 

    struct Module* mods = constructModules();

    printModules(mods);

    free(mods);
    return 0;
}
