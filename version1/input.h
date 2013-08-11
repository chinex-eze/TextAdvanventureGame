#ifndef __INPUT_h__
#define __INPUT_h__
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdbool.h>

int countCommandLineParameter(char *st);
char ** stringtokenizer(char *st,int SIZE);
char * convertToUpperCase(char *st);
char ** readCommand();
bool isCommandValid(char * command[],int SIZE);

#endif
