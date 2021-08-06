#include <stdio.h>
#include "calc.h"
#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

/* the following code implement a stack in C
    a stack is a data structure that stores elements
    following the last in, first out directive (LIFO)
    meaning that the last element pushed in the stack
    will be the first one to be popped out of it */

/* push: push f onto value stack */
void push(double f) 
{
    if (sp < MAXVAL){
        val[sp++] = f;
    }
    else{
        printf("error: stack full, can't push %g\n",f);
    }
}

/* pop: pop and return top value from stack */
double pop(void) 
{
    if (sp > 0){
        return val[--sp];
    }
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}