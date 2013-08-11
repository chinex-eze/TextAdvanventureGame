#include "player.h"


  void init_Player( Player * obj, int live, bool status )
  {
	obj->playerLive = live;       //player life
	obj->lifeStatus = status;      //dead or alive
  }

  void SetName(Player * obj, char*  name )
  {
       obj->player_name = name;
  }

  //return players name

   char * GetName(Player * obj)
  {
        return obj->player_name;
  }

  //set players life
  void setPlayerLive(Player * obj, int Live)
  {
        obj->playerLive = Live;    
  }

  //return player life
  int getPlayerLive(Player * obj)
  {
        return obj->playerLive;
  }

  //set life
  void setPlayerlifeStatus(Player * obj, bool Status)
  {
        obj->lifeStatus = Status;
  }

  //return the status of life
  bool  getPlayerlifeStatus(Player * obj)
  {
        return obj->lifeStatus;
  }

  //decrease life
  void decreasePlayerLife(Player * obj){
        if(getPlayerlifeStatus(obj)){
            if( --obj->playerLive == 0 ){ 
                setPlayerlifeStatus(obj,false) ;
                printf("%s\n", "Player is dead!");
            }
        }
        else{ printf("%s\n", "Player is dead already->"); }
    }


//attack object
void OnAttackPlayer(Player * obj){

    int value = ( rand() % 2 );      
    
    if( value==1 ){
        printf("%s\n","Monster attacked you successfully!");
        decreasePlayerLife(obj);          
    }
    else{
        printf("%s\n","Monster attack was UNSUCCESSFUL!!!");
    }
    printf("%s%d%s\n","You have '" ,getPlayerLive(obj), "' life left");
}

