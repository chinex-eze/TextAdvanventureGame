
#include <stdio.h> 
#include <stdlib.h>


#include "game.h"
////////////////////////////////////////////////////////////////////////////////
int main()
{
  Game  * game = (Game  *)malloc(sizeof(Game  ));

  Game_Init(game);
  Game_PrintIntro(game );
  Game_MainLoop( game );

  printf("%s\n","Exiting, bye!");
  Game_Destroy(game);
  free(game);
  return 0;
}
/////////////////////////////////////////////////////////////////
