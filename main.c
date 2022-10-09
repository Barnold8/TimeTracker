// This program aims to help track the time spent on uni modules during a semester. 10 creds = 100hr needed, 20 creds = 200hr needed

// ((24 * d) / n )  / 24 where d is the allocated days of the year to work and n is the hours needed

#include <stdio.h>
#include <stdlib.h>
#include "headers/fileRDR.h"
#include "headers/dataSTRUC.h"
#include "headers/menu.h"

extern struct Module* mods;

int main(){

    if(checks() == -1){return -1;} 

    mods = constructModules();
     
    runMenOpt(homeChoice());

    free(mods);

    return 0;
}
