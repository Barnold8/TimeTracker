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

int validFile(char* filename){ //Writing EOF as a module name will work (can be fixed later)

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

    if(strcmp("EOF",str) == 0 && lineCount >= 3){ // to process the last piece of data

        eof = 1;
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
    char ch;
    if(hasFile(file) == -1){return -1;}

    while(!feof(fptr))
    {
        ch = fgetc(fptr);
        if(ch == '\n'){
            lines++;
        }
    }
    
    fclose(fptr);
    return lines;
}


int checks(){

    char* fn = "data";

    if(hasFile(fn) == -1){
        
        printf("No file has been found. If this is wrong, please put a file named 'data' in the same directory as the binary and reload the program\n\nIf this is not wrong, press Enter to go through the file setup process");
        getchar();    
        system("clear");
        
        if(makeFile() == -1){
        
            printf("The file you just made isnt valid for this program to process. It is possible that the program failed to write some necessary data. Delete the file named 'data' and rerun the program to try again\n");
            return -1;
        }
    }

    else if(validFile(fn) == -1){
        printf("The file named 'data' is invalid. Try adding EOF to the end of the file to fix this problem.\nNOTE: if this isn't the problem, it will either do nothing or add undefined behaviour to the program and you could lose all saved data\n");    
        return -1;
    }
    
    return 1;

    
}

