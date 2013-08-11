TextAdvanventureGame
====================

Project Team Members
 
Odoh Kenneth Emeka
Chinedu eze
Gboyega J. Akinbami 


HOW TO COMPILE THIS PROGRAM:
This program was designed with modularity in mind.It has been implemented to be easy to maintain.We used a model where we ensure every memory allocation takes place in the game init function while memory deallocation takes place in the Gamedestroy method.This will enable us avoid most forms of memory leaks.


This program is licensed as an open software. The source code comes with an executable file. 
The user can run this executable file as a script called compile.sh. It is a bash script that 
compiles the program using the gcc compiler.

Compiling from source
$ ./compile.sh  		---this compiles the codes
$ ./adventure			---this runs the game program


First make sure that all the files are saved in the same folder.

Note: This makes use of the  GNU  compiler. 
The codes are stable and successfully tested on a linux machine.



HOW TO RUN IT:

Open the command prompt. Then, from the command line, go to the location of the files. 
To run the program, type the command, "./adventure.exe" while in the same location as above.




HOW TO PLAY:

First, the program is compiled and run as described above, a welcome message is displayed showing some informationa. 
The program ask only for your name as you don't need so much personal information in order to play this game.

A player starts from the "Jail room", which is the first room in the game. To get out of the jail the player has to find a key to open the door of the jail.
 
The key is [permanently] placed in item in the room. In subsequent versions of the game, the key would
be randomly placed in different items in the "Jail Room", in order to make it more interesting.

To find the key, player performs itemsearch on each item in the room with the command itemsearch <object>.
Where <object> is an object in the room. The command is repited until the key is found.
Once the key is found, player must use the command USE <key> TO <door> 
where key and door are both arguments to the respective commands. 
After the command is issued, the door is opened with the message "door opens". 
But player is still in the JAIL room. To leave the room, player must use the command, 
MOVE <north> where north is the argument is the argument to the command MOVE. 
Other arguments (east, west and south) exists but player cannot move in those directions.
This is because the door is at the north of the room.

After the above command is issued, player advances to the next room, which is the Monster room 
with the guarding monster. To escape, player has to attack the monster consecutively 5 times 
in order to kill it. The ATTACK <monster> command is used for this purpose. For each attack issued 
by the player, the monster attacks back. An attack may or may not be successful, both for player 
and monster. If monster succeeds in hitting player five times first, then player dies 
and game is over. But if it happens the other way around, then monster dies and player may move 
to the next room. It should be noted that since the success of a hit is based on a randomly generated
output, both player and monster has a 50-50 chance of success.

NB:
You can only move forward and not backward.If you leave a room.You cannot re-enter it again.

To advance to the next room, player has to issue the command MOVE <north>, 
then player is in the final Finish room, where player is greeted and kissed by the beautiful princess. 
The kiss is then rudely interrupted and player is turned into a frog and game ends.
Subsequent versions of the game would support multiple players, in which case, the next player plays. 
Game ends when the last player dies. However, in this current version, the current player dies and the game ends.

NB: To end the game at any time, the command QUIT is issued with no arguments. 
In subsequent versions that would support multiple players, the QUIT command would only end the 
current player's game and the next player starts. The entire game ends when the command is issued 
by the last player.
However, in the current verion, the command ends the entire game as there is only one player.


Player must unlock cell door and defeat the guarding monster.
The areas of the game is :
->Jail room
->Guarding room
->Finish room

*The doors will be opened with a key.
*Player searches and gets the key in the jail cell and uses key to unlock
the door.
*Player opens door and move north.
*After move command,player moves to next room(Guardian monster room)
*When the player reaches the guardian room.He attacks the monsters 5 times to kill it.
*Player dies if monster hits the player first for five time.
*Player moves only north
*When the player reaches finish room.He will be congratulated by
princess.
*Players turns int frog.

RULES OF THE GAME
*Player/monster hitpoint count to 5.
*Probability of attack player/monster is 50%.
*Game is turn based.

The game is designed to ensure that the player does limit typing.
This will make the game more interactive.


INSTALLATION AND GETTING STARTED
This is pretty easy. First the files are stored into the same location (directory).
Then follow the instructions as above to compile and run the program.
NB:
The game could be played right away by running the "adventure" file as a script
on a linux machine.

IMPORTANT KNOWN PROBLEMS
The user input is not exactly validated but it is reasonably validated. 
No problems were found during testing. However,if user sees any signifant bug.
Feel free to reach us on kenluck2001@yahoo.com

BUG REPORTS
This version is relatively stable on windows platform. It could could on other plateform will 
limited guaranty.

COPYRIGHT INFORMATION
This is a freeware. This program comes without a guarantee. 
You are free to modify the codes without informing the owner. 
This license implies that this code could be used for commercial project without reservation.


THE BRIEF DESCRIPTION OF THE COMMANDS:
You will have to get a clearer understanding of these commands by playing the game.
Here is a summary of the commands:

HELP:		This displays the commands that are available to player.
COOMAND: 	This is used to display a list of COMMMANDS.

LOOK: 		This is used to give a description of the current room where a player is at the moment.eg look jail,look monster,look finish

SEARCH:		This is used to search the rooms to see the items.
ITEMSEARCH:	This is used to search the specific items in that room

EXAMINE: 	This is used to get the description of the composition of the room.e.g "examine jail" This will tell us what the jail is made up of.

EXAMINEITEM:This is used to get the description of the composition of the items room.e.g if the jail has a plate and we want to examine the plate .we use "examineitem plate"

MOVE:		Is used to move in a particular direction. The direction to move is supplied as an 
	arguement to the command e.g. north. 

ATTACK: 	Is used to attack the guarding monster at the monster room. The object to attack is 
	supplied as an argument to the command. Attack is turn based though. An attack may or may not be successful.

USE:		This is used to use a tool or object that the player possesses on / to an object in the 	
	game e.g. to use the key to open the door. It also has an optional additional command TO which takes an argument as well e.g. to open the door, USE <key> TO <door> is issued after player possesses the key with the examine command.

QUIT:		This command ends the game of the current player or ends the game entirely if the current.This displays the exit message. 


            ************ENJOY**************

References
1)	A book on C: programming in C by Al Kelley, Ira Pohl . 
2)  C programming: a modern approach by Kim N. King.
3)  Beej's Guide to C Programming(http://beej.us/guide/bgc/output/print/bgc_A4.pdf).
4)  
 
