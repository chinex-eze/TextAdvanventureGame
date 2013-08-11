#include "command.h"
#include <stdlib.h>

#define JAIL 0
#define MONSTERROOM 1
#define FINISH 2

#define CLOSE 0
#define OPEN 1


unsigned int key = CLOSE;
unsigned int door = CLOSE;
unsigned int m_RoomId = JAIL;




char * item[6] = { "RAT", "CUPBOARD", "TOILET", "TABLE", "CHAIR", "BED" };
/////////////////////////////////////////////////////////////////
/*look command messages*/
const char * onlookjailMsg = "\nYou are currently in jail! \nEverywhere stinks. \nThe jail is smelling badly and has a leaking toilet\n";

const char * onlookmonsterMsg = "\nYou are currently in the monster room. \nNow is the time to kill this monster. \nGood luck player\n";

const char * onlookfinishMsg = "\nThis is the Finish room.\n!!!!!!!!!!!!!! You win!!!!!!!!!!!!!!\n The queen is sitted with the guards. \nYou have to move north to to end the game.............\n";

const char * onlookdefault = "\nYou cannot look here yet \n";
/////////////////////////////////////////////////////////////////


/*searchitem command messages*/
const char * searchRatMsg = "\nYou open the mouth of the rat and found the key. \nUse this key to open the door and move north\n";

const char * searchCupBMsg = "\nYou searched the cupboard but did not find anything useful\n";

const char * searchToiletMsg = "\nYou put your hand into the toilet sink and only made contact with your old faeces. \nYou found nothing useful here\n";

const char * searchTableMsg = "\nYou search the table but found decaying food on the table. \nYou found nothing useful here\n";

const char * searchChairMsg = "\nYou search the chair and found nothing useful\n";

const char * searchBedMsg = "\nYou search the bed but found nothing useful\n";
/////////////////////////////////////////////////////////////////
/*search Room messages*/
const char * searchJailMsg = "There are the following items in the jail. \nThey are \n1)Rat \n2)Cupboard \n3)Toilet \n4)Table \n5)Chair \n6)Bed\n";

const char * searchMonstRoomMsg = "\nYou don't have to search the room. \nJust kill the monster and go away\n";

const char * searchFinishRoomMsg = "\nYou do not need to search in this room!\n";  

/////////////////////////////////////////////////////////////////

/*examine command string*/
const char * jailExamineMsg = "\nThe Jail is made up of brick and is rectangular in shape.\n";
const char * monsExamineMsg = "\nThe Monster room is dark and made of rusty iron with a red eyed monster.\n";
const char * finishExamineMsg = "\nThe finish room is made of gold\n";
////////////////////////////////////////////////////////////////

/*examine item command strings*/
const char * examineRatMsg = "\nThe rat is rotten and decaying.\n";

const char * examineCupBMsg = "\nThe cupboard is made up of wood.\n";

const char * examineToiletMsg = "\nThe toilet is made up of ceramic and rusty.\n";

const char * examineTableMsg = "\nThe table is made up of rusty wood.\n";

const char * examineChairMsg = "\nThe chair is made of iron.\n";

const char * examineBedMsg = "\nYou search the bed but found nothing useful.\n";
////////////////////////////////////////////////////////////////


	 
  void UseCommand(char * input, char* useparam,char* toObj, char * toparam)                
 {
	if(strncmp( input, "USE", 3 )== 0)
	{

		if( (strncmp( useparam,"KEY",3 )== 0) && (strncmp(toObj,"TO",2) == 0) && (strncmp( toparam,"DOOR",4 )== 0) )
		{ 
		    if((m_RoomId  == JAIL ) && (key == OPEN))
		    {
		        ///must be in jail room
				door = OPEN;
				printf("You have opened the door of the Jail. \nMove North to enter the monster Room\n");      
		    }
			else
			{
				printf("You are not in the Jail or You don't have the key\n");
			}
		}
		else
		{
			printf("use COMMAND or HELP for more information\n");
		}
	}
}
 
/////////////////////////////////////////////////////////////////
void look(int state)
{
	if(state == JAIL)
	{
		printf("%s",onlookjailMsg);
	}
	else if(state == MONSTERROOM )
	{
		printf("%s",onlookmonsterMsg);	
	}
	else if(state == FINISH)
	{
		printf("%s",onlookfinishMsg);
	}
	else
	{
		printf("%s",onlookdefault);
	}
}

void LookCommand(char * input)
{
	if( strncmp(input,"LOOK",4) == 0 )
	{
		look(m_RoomId); 
	}
}
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
void search(int state)
{
	if(state == JAIL)
	{
		printf("%s", searchJailMsg);
	}
	else if(state == MONSTERROOM )
	{
		printf("%s",searchMonstRoomMsg);
	}	
	else if(state == FINISH)
	{
		printf("%s",searchFinishRoomMsg);
	}
	else
	{
		printf("You cannot search here yet!!!!\n");
	}
}

void SearchCommand(char * input)
{
	if( strncmp(input, "SEARCH", 6) == 0 )
	{
		search(m_RoomId); 
	}
}

/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
void examine(int state)
{
	if(state == JAIL)
	{
		printf("%s",jailExamineMsg);
	}
	else if(state == MONSTERROOM )
	{	
		printf("%s",monsExamineMsg);
	}
	else if(state == FINISH)
	{
		printf("%s",finishExamineMsg);
	}
	else
	{	
		printf("You cannot examine here yet!!!!\n");
	}
}

void ExamineCommand(char * input)
{

	if( strncmp(input,"EXAMINE",7) == 0 )
	{
		examine(m_RoomId); 
	}
}

/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
void ExamineItemCommand(char * input, char * nextInput )
{
	int count;
	if( strncmp(input,"EXAMINEITEM",11) == 0 )
	{
		if( m_RoomId == JAIL)//must be in monster room to attack
		{ 
			for(count = 0; count < 6; count++)
			{
					if( strncmp(nextInput,item[0],3) == 0 )
					{
						printf("%s",examineRatMsg);
						break;
					}
					else if( strncmp(nextInput,item[1],8) == 0 )
					{
						printf("%s",examineCupBMsg );
						break;
					}
					else if( strncmp(nextInput,item[2],6) == 0 )
					{
						printf("%s",examineToiletMsg);
						break;
					}
					else if( strncmp(nextInput,item[3],5) == 0 )
					{
						printf("%s",examineTableMsg);
						break;
					}
					else if( strncmp(nextInput,item[4],5) == 0 )
					{
						printf("%s",examineChairMsg);	
						break;		
					}
					else if( strncmp(nextInput,item[5],3) == 0 )
					{
						printf("%s",examineBedMsg);
						break;
					}
			}
		}
	}
}


void SearchItemCommand(char * input, char * nextInput )
{
	int count;
	if( strncmp(input, "ITEMSEARCH", 10) == 0 )
	{
		if(m_RoomId == JAIL)//must be in monster room to attack
		{ 
			for(count = 0; count < 6; count++)
			{ 
					if( strncmp(nextInput,item[0],3) == 0 )
					{
						printf("%s",searchRatMsg);
						key = OPEN;
						break;
					}
					else if( strncmp(nextInput,item[1],8) == 0 )
					{
						printf("%s",searchCupBMsg);
						break;
					}
					else if( strncmp(nextInput,item[2],6) == 0 )
					{
						printf("%s",searchToiletMsg);
						break;
					}
					else if( strncmp(nextInput,item[3],5) == 0 )
					{
						printf("%s",searchTableMsg);
						break;
					}
					else if( strncmp(nextInput,item[4],5) == 0 )
					{
						printf("%s",searchChairMsg);
						break;			
					}
					else if( strncmp(nextInput,item[5],3) == 0 )
					{
						printf("%s",searchBedMsg);
						break;
					}
			}
		}
	}
}
 

void MoveCommand( Monster * monstObj, char * input, char * nextInput ) 
{
	if( strncmp(input,"MOVE",4) == 0 )
	{
		if( strncmp(nextInput, "NORTH", 5) == 0 )
		{
			///use the room index to locate the current room
			if( m_RoomId == JAIL)
			{      
		            //check if door is open  
		            if( door == OPEN )
					{
		                ///set the current room to the monster room
		                m_RoomId = MONSTERROOM; 
		                look(m_RoomId); 
		            } 
		            else
					{	printf("%s\n","\nYou must first find key and open the door!" ); 
					}

		        }
		        else if(m_RoomId == MONSTERROOM )
		        {                   
		            if( !getMonsterlifeStatus(monstObj))
		            {
		                m_RoomId = FINISH; 
						look(m_RoomId) ;                       
		            }
		            else{
						printf("%s\n", "You must first slay the monster!.\n");
		            }
		        }
		        else if(m_RoomId == FINISH )
		        {
					printf("%s\n","You are with the princess. No need to move anywhere. \nShe kisses you on the face and you turn into a frog. \nGame is OVER...WELL DONE PLAYER !!!!!!!!!!!!!!!!");
					exit(0);
				}

		    }
		    else{ 
		        printf("%s%s%s\n","Can not move in '",nextInput,"' direction."); 
		    }
	}
}


void AttackCommand( Monster * monstObj, Player * playerObj, char * input,char * nextInput)
{
	if( strncmp(input, "ATTACK", 6) == 0 )
	{
		if( strncmp(nextInput, "MONSTER", 7) == 0 )
		{
		    if( m_RoomId == MONSTERROOM )   ///must be in monster room to attack
			{
                if(getPlayerlifeStatus(playerObj))
				{
                    printf("\nAttacking monster...\n");
		        	OnAttackMonster(monstObj);
				}
		        
		        if(getMonsterlifeStatus(monstObj))
				{
		            printf("%s\n","Monster attacks back!");
		            OnAttackPlayer(playerObj);          ///monster attacks back immediately
		        }
                if(!(getPlayerlifeStatus(playerObj)))
				{
                    printf("Player is Dead...\n");
		        	exit(0);
				}

		    }
		    else{
		        printf("%s\n","Can not attack in here! ");
		    }
		}
		else{
		    printf( "%s %s", "Can not attack object: ", nextInput );
		}
	}

}


