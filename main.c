// This program aims to help track the time spent on uni modules during a semester. 10 creds = 100hr needed, 20 creds = 200hr needed

#include <stdio.h>
#include <stdlib.h>
#include "headers/fileRDR.h"

int main(){

    char* fn = "data";

    if(hasFile(fn) == -1){
        
        printf("No file has been found. If this is wrong, please put a file named 'data' in the same directory as the binary and reload the program\n\nIf this is not wrong, press Enter to go through the file setup process");
        getchar();    
        system("clear");
        
        if(makeFile() == -1 || validFile(fn) == -1){
        
            printf("The file you just made isnt valid for this program to process. It is possible that the program failed to write some necessary data. Delete the file named 'data' and rerun the program to try again\n");
            exit(1);
        }
    }

    else if(validFile(fn) == -1){
        printf("The file named 'data' is invalid. Try adding EOF to the end of the file to fix this problem.\nNOTE: if this isn't the problem, it will either do nothing or add undefined behaviour to the program and you could lose all saved data\n");    
        exit(1);
    }
    
    


    return 0;
}
