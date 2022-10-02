#include "headers/fileRDR.h"
#include <stdlib.h>
#include <string.h>

int hasFile(char* filename){

    FILE * f;

    if((f = fopen(filename,"r"))){
        fclose(f);
        return 1;
    }
    return -1;
}

int validFile(char* filename){

    FILE *fptr;
    fptr = fopen(filename,"r");
    char str[255];
    int lineCount = 0; // if linecount < 3 and EOF SUCCESS, something is wrong
    int eof = -1;

    if(hasFile(filename) == -1){
        return -1;
    }
   
    while(fgets(str,sizeof(str),fptr)){

        lineCount++;
        if(strcmp("EOF",str) == 0 && lineCount >= 3){
            eof = 1;
        }
    }

    fclose(fptr);
    return eof;
}

int makeFile(){

    int c;
    int choice = 0;
    char str[255];
    char* actions[3] = {"Enter the module name: ","Enter the module credits: ","Enter the current amount of hours in the module: "};
    FILE* fptr;
    int charSum = 0;

    fptr = fopen("data","w");

    while(1){
    
        printf("type 1 to enter a module to the list or type any other number to exit this module information section: ");

        scanf("%d",&choice);

        if(choice != 1){
            fputs("EOF",fptr); // needed to validate file
            fclose(fptr);
            break;
        }
        
        while((c =  getchar()) != '\n' && c != EOF){} // fully clears the stdin buffer

        for(int i = 0; i < 3; i++){ 
            printf("%s",actions[i]);
            
            if(!(fgets(str,sizeof(str),stdin))){
                printf("FATAL ERROR\n");
                exit(1);
            }
            
            if(i > 0){ // After name of module is written
            
                if(atoi(str) == 0){
                    for(int i = 0; i < 255; i++){
                        
                        if(str[i] == 10 || str[i] == '\n' || str[i] == EOF){
                            break;
                        }    
                        
                        charSum += str[i];    
                    }

                    if(charSum != 48){
                        return -1;
                    }
                }

            }
            fputs(str,fptr);

        } 
        system("clear");
    }
    
    fputs("EOF",fptr); // this string is used so we can verify a valid file later
    fclose(fptr);
    return 1 ;

}


int getLines(char* file){

    FILE *fptr;
    fptr = fopen(file,"r");
    int lines = 0;

    if(hasFile(file) == -1){return -1;}

    while(fgets(NULL,0,fptr)){
        lines++;
    }


    fclose(fptr);
    return lines;
}


