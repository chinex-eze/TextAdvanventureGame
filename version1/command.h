#ifndef __COMMAND_h__
#define __COMMAND_h__


#include "monster.h"
#include "player.h" 

#include <stdio.h>
#include <string.h>

 
void UseCommand(char * , char* ,char* , char *);              
void look(int );
void LookCommand(char * );
void search(int );
void SearchCommand(char *);
void examine(int );
void ExamineCommand(char * );
void ExamineItemCommand(char * , char *  );
void SearchItemCommand(char * ,char * );
void MoveCommand( Monster * , char *, char * );
void AttackCommand( Monster * , Player *, char *, char * );

#endif


