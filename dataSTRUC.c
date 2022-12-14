#include "headers/dataSTRUC.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/fileRDR.h"

struct Module* mods; // this feels unsafe for some reason

struct Module* constructModules(){

    char *file = "data";
    char str[255];
    FILE *fptr;
    struct Module* arr;    
    int modules;
    int count = 0;
    int index = 0;

    fptr = fopen(file,"r");
    modules = getLines(file) / 3;
    

    if((arr = (struct Module*)malloc(modules * sizeof(struct Module)))== NULL){

        printf("Memory allocation error! Exiting the program\n");
        fclose(fptr);
        exit(1);

    }
    arr[0].length = modules;

    while(!feof(fptr)){
        

        if(!(fgets(str,sizeof(str),fptr))){ // grab line from file and sanitise on grab
            free(arr);
            fclose(fptr);
            printf("Fatal error in reading data and allocating to heap\nExiting program\n");
            exit(1);
        } 
    
        if(strcmp("EOF",str) == 0){ // dont include validation text as processable data
            break;
        }

        if(count > 2){
            count = 0;
            index++;
        }
        
        switch(count){ // no checks for atoi since we checked in the writing of the file
            
            case 0:
                
                for(int i = 0; i < 255; i++){
                    arr[index].name[i] = str[i];
                }
                break;
            
            case 1:
                arr[index].credits = atoi(str);
                break;

            case 2: 
                arr[index].hours = atoi(str);
                break;
    
            default:
                break;

        }

        count++;
    }
    
    fclose(fptr);

    return arr;

}

void printUnderline(char* title){
    
    int x = 0;
     
    while(title[x] != '\n'){
        printf("%c",'-');
        x++;
    }
    printf("\n");
    
}

void printModules(int pick){
    
    int x = 0;

    system("clear");

    printf("================== Modules ==================\n\n");

    for(int i = 0; i < mods[0].length;i++){

        (pick == 0 ? printf("%s",mods[i].name) : printf("%d. %s",i,mods[i].name));

        printUnderline(mods[i].name);

        x = 0;

        printf("\nCredits: %d\nCurrent Hours: %d\n\n",mods[i].credits,mods[i].hours);

    }
    contWait();
}

void displayModule(int index){

    system("clear"); 
    printf("0. %s",mods[index].name);
    printUnderline(mods[index].name);
    printf("1. Credits: %d\n2. Hours: %d",mods[index].credits,mods[index].hours);

}

void editModule(){

    int index,attr,c;
 
    printModules(1);    
    
    printf("\nPlease pick a module to edit: ");
    scanf("%d",&index);

    printf("%d scanf output\n",index);

    while((c =  getchar()) != '\n' && c != EOF){} 

    index = (index > mods[0].length) ? mods[0].length -1 : index;

    displayModule(index);

    runMenOpt(homeChoice());

}

void deleteModule(){

    printf("DeleteModule\n");

    
    runMenOpt(homeChoice());

}

void addModule(){

    printf("addModule\n");


    runMenOpt(homeChoice());
}

