#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "game.h"
#include "input.h"
#include "command.h"


#define NO_OF_LIFE 5
 
const char * helpDefaultMsg = "Type HELP for instructions and COMMAND for list of Commands\n";

const char * commandMsg = "Available commands:\n\nLOOK\nEXAMINE\nEXAMINEITEM\nSEARCH\nMOVE\nATTACK\nUSE\nITEMSEARCH\nHELP\nQUIT\nCOMMAND\n";

const char * helpMsg = "These Commands are case insensitive e.g SEarch and search are the same. \nCommand name		|    Description \nLOOK			|Reveals description of a room or environment where player is in. \nEXAMINEITEM <name>	|Reveals detailed description of named game object that player can see or possesses. \nEXAMINE			|Reveals composition of the rooms. \nITEMSEARCH 	     	|Searches current room to find something. \nSEARCH			|Searches the rooms only to tell the items in the room. \n			|Then use ITEMSEARCH for each item. \nMOVE <direction>	|Attempts to move to a direction (Possible options are north, east, south and west). \nATTACK <name>		|Attacks named game object. \nUSE <name> [ TO <object> ] \nUSE <name>:		|Attempts to use named game object in some fashion. \nUSE <name> TO <object>:	|Attempts to use game object in some fashion. Use is targeted to another gameobject <object>. \nHELP          		|Prints help message that describes available commands in this table with descriptions. \nQUIT         		|Exits game.\n";

void Game_Init( Game * game)
{
	game->game_is_on = true;

	game->player = (Player *) malloc(sizeof(Player));
    game->monster = (Monster *) malloc(sizeof(Monster));
     
	init_Monster(game->monster, NO_OF_LIFE, true);  
	init_Player(game->player, NO_OF_LIFE, true);
}

void Game_Destroy( Game * game)
{
    if (game->player)
        free(game->player) ;
    if(game->monster)
        free(game->monster);
}

void Game_PrintIntro( Game * game )
{
  printf("%s\n", "=================================================");
  /// Actual game is about to start
  printf("%s\n","\nAnd behold; the adventure begins! ");
  printf("%s\n","You wake up in a cell. \nYou see a bed with a rock hard matress. \nThere is a rat as your companion. Cell door is locked.");
  
  printf("%s\n",helpDefaultMsg);
}
////////////////////////////////////////////////////////////////////////////////
void Game_MainLoop( Game * game )
{
	
  	while ( game->game_is_on )
  	{
    	char ** cmd = readCommand();

		if(cmd)		
		{
			if (strncmp("QUIT",cmd[0],4 ) == 0)
			{
		  		game->game_is_on = false; // exit loop
			}
			if (strncmp("LOOK",cmd[0],4 ) == 0)
			{
				LookCommand(cmd[0]);
			}
			if (strncmp( "EXAMINE",cmd[0],7) == 0)
			{
				ExamineCommand(cmd[0]);
			}
			if (strncmp("EXAMINEITEM",cmd[0],11 ) == 0)
			{
				ExamineItemCommand(cmd[0],cmd[1] );
			}
			if (strncmp( "SEARCH",cmd[0],6 ) == 0)
			{
				SearchCommand(cmd[0]);
			}
			if (strncmp("MOVE",cmd[0],4 )==0)
			{
				MoveCommand(game->monster,cmd[0],cmd[1]);
			}
			if (strncmp("ATTACK", cmd[0], 6 ) == 0)
			{
				AttackCommand( game->monster, game->player, cmd[0], cmd[1] );
			}
			if (strncmp("USE",cmd[0],3 ) == 0)
			{
				UseCommand(cmd[0],cmd[1],cmd[2],cmd[3]);              
			}
			if (strncmp("ITEMSEARCH",cmd[0],10 ) == 0)
			{
				SearchItemCommand(cmd[0],cmd[1]);
			}
			if (strncmp("HELP",cmd[0],4 ) == 0)
			{
				printf("%s",helpMsg);
			}
			if (strncmp( "COMMAND",cmd[0],7 ) == 0)
			{
				printf("%s", commandMsg);
			}

		}

  	}// end while
}
////////////////////////////////////////////////////////////////////////////////
