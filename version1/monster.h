
#ifndef __MONSTER_h__
#define __MONSTER_h__

#include <stdbool.h>
#include <string.h>
#include <stdio.h>




typedef struct
{
   int monterliveCounter;   ///life count
   bool lifeStatus;         ///dead or alive
}Monster;

  	void init_Monster( Monster * obj, int live, bool status);


    void setlifeStatus( Monster * obj, bool Status); //set the status

    void setMonterLive( Monster * obj, int counter);//set the life

    int getMonterLive( Monster * obj);//return the life


    bool getMonsterlifeStatus( Monster * obj); //return the status

    //decrease life
    void decreaseLife( Monster * obj);

    //attack the player
    void OnAttackMonster( Monster * obj);


#endif

