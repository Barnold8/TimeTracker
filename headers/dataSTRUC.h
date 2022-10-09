#ifndef DATA
#define DATA

struct Module{ // each module has hours completed by user, credits to determine the amount of hours needed for the module

    char name[255];
    int hours;
    int credits;
    int length;
    int id; // used to determine what menu item each module is for the menu system
};


struct Module* constructModules(); // returns heap allocated struct array with all the modules read from file / FREE THIS LATER

void printModules (int);

void editModule();

void deleteModule();

void addModule();

void displayModule(int);

void printUnderline(char*);

#endif
