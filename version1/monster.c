#include <stdlib.h>
#include <time.h>

#include "monster.h"

  void init_Monster( Monster * obj, int live, bool status)
  {
	obj->monterliveCounter = live;       ///player life
	obj->lifeStatus = status;            ///dead or alive
  }

    void setlifeStatus( Monster * obj, bool Status) //set the status
    {
        obj->lifeStatus = Status;   
    }
    
    void setMonterLive( Monster * obj, int counter)//set the life
    {
        obj->monterliveCounter = counter;  
    }

    int getMonterLive( Monster * obj)//return the life
    {
        return obj->monterliveCounter;  
    }

    bool getMonsterlifeStatus( Monster * obj) //return the status
    {
        return obj->lifeStatus;   
    }

    //decrease life
    void decreaseLife( Monster * obj)
    {
        if(getMonsterlifeStatus(obj)){
            if( --(obj->monterliveCounter) == 0 ){   
                setlifeStatus(obj,false);                     
                printf("%s\n","MONSTER is dead!");
                printf("%s\n","you can now advance to finish! Move north!");
            }

        }
        else
        { 
            printf("%s\n", "Monster is dead already. Move North to final room."); 
        }
    }


    //attack the player
    void OnAttackMonster( Monster * obj)
    {
        srand((short)time(NULL) );
        int value = ( rand() % 2 );      
    
        if( value==0 ){
            printf("%s\n","You attacked monster successfully." );
            decreaseLife(obj)  ;                        
        }
        else{
            printf("%s\n","Attacked on monster was UNSUCCESSFUL!!!");
        }
        printf("%s%d%s\n","MONSTER has '" , getMonterLive(obj),"' life left!");                                                 
    }

