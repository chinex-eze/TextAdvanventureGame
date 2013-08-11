
#ifndef __player_h__
#define __player_h__
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct 
{
  char * player_name;       //player name
  char * character_name;    //character name
  int playerLive;           //player life
  bool lifeStatus;          //dead or alive
}Player;

  void init_Player(Player * obj, int live, bool status);


  void SetName(Player * obj, char*  name );
  //return players name

  char * GetName(Player * obj);

  //set players life
  void setPlayerLive(Player * obj,int Live);

  //return player life
  int getPlayerLive(Player * obj);

  //set life
  void setPlayerlifeStatus(Player * obj, bool Status);

  //return the status of life
  bool  getPlayerlifeStatus(Player * obj);


  //decrease life
  void decreasePlayerLife(Player * obj);

  void OnAttackPlayer(Player * obj);

#endif
