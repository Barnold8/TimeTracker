#ifndef FILERDR
#define FILERDR

#include <stdio.h>

int hasFile(char*); // return -1 if file doesnt exist, return 1 if file exists

int validFile(char*); // return -1 if file isnt valid, return 1 if it is

int makeFile(); // starts sequence for generating the file to read and write to for use in the program overall

int getLines(char*);

#endif
