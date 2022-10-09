#include "headers/menu.h"
#include "headers/dataSTRUC.h"
#include "headers/fileRDR.h"
#include <stdlib.h>

#define MAX 7

int homeChoice(){

    char* menu_items[MAX] = {"View modules","Edit Module","Add Module","Delete Module","Write New File","Delete File","Exit"};
    int choice = 0;

    printf("\n");
    for(int i = 0 ; i < MAX; i ++){
        
        printf("%d. %s\n",i,menu_items[i]);
    }

    printf("\nPlease pick a menu item: ");
    scanf("%d",&choice);

    return (choice >= MAX) ? MAX-1 : choice;
}

void ex(){
    extern struct Module* mods;
    free(mods);
    exit(0);
}


void runMenOpt(int choice){ // 

    void* (*func_ptr[MAX])() = {printModules,editModule,addModule,deleteModule,NULL,deleteFile,ex};
    if(choice == 4){
        makeFile();
    }
    func_ptr[choice]();

}


