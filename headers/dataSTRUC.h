#ifndef DATA
#define DATA

struct Module{ // each module has hours completed by user, credits to determine the amount of hours needed for the module

    char* name;
    float hours;
    int credits;
   
};


struct Module* constructModules(); // returns heap allocated struct array with all the modules read from file / FREE THIS LATER

#endif
