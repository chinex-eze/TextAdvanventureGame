#include "input.h"

/*This method counts the number of words in a command line string*/
int countCommandLineParameter(char *st)
{
	char str[60];
	int i,count;
	strncpy (str,st,50); //copy the string from st to str and limit the match string to 50
	count=1;
	i=0;
	while(str[i]!='\0') //check that the string is not end of line
	{ 
		if(str[i]==' ')
			count++;
		i++;
	}
	return count;
}

/*This method splits the command line argument into tokens*/
char ** stringtokenizer(char *st,int SIZE)
{
  	char str[60];
	strncpy (str,st,50);
	char** Tmp = (char**)malloc(sizeof(char*) * SIZE); //allocate the memory

  	char * pch ;
  	pch = strtok (str, " "); //token the string
	int count = 0;
  	while (pch != NULL) //while pch is not null
  	{
		Tmp[count] = malloc(strlen(pch) + 1); //create memory 
		strcpy(Tmp[count],pch);
    	pch = strtok (NULL, " ");
		count++;
  	}
	return Tmp;
}
/*This ensures case insensitive*/
char * convertToUpperCase(char *st)
{
	char * pch = (char *)malloc(strlen(st) * strlen(st));
  	int i;
  	for (i = 0; st[i]; i++)	 
		pch[i] = toupper(st[i]); //convert to uppercase
	return pch;
}

/*receives the input from the user*/
char ** readCommand()
{
	char text[50];
	fputs("> ", stdout);
	fflush(stdout); 
	fgets(text, sizeof text, stdin);
	char * uppercaseString = convertToUpperCase(text);
	int argumentCount = countCommandLineParameter(uppercaseString);
	char ** stringToken = stringtokenizer(uppercaseString,argumentCount);
	if (isCommandValid(stringToken,argumentCount))
	{
		return stringToken;
	}
	else
	{
		printf("Type HELP for instruction and COMMAND for list of \n");
		return NULL;
	}
}

/*ensures that the command are valid*/
bool isCommandValid(char * command[], int SIZE)
{
	bool status;
	if(((strncmp(command[0],"HELP",4) == 0)&& (SIZE == 1)) || ((strncmp(command[0],"QUIT",4) == 0)&& (SIZE == 1)) || ((strncmp(command[0],"COMMAND",7) == 0)&& (SIZE == 1)) || ((strncmp(command[0],"LOOK",4) == 0)&& (SIZE == 1)) || ((strncmp(command[0],"SEARCH",6) == 0)&& (SIZE == 1)) || ((strncmp(command[0],"ITEMSEARCH",10) == 0)&& (SIZE == 2)) || ((strncmp(command[0],"EXAMINE",7) == 0)&& (SIZE == 1)) || ((strncmp(command[0],"EXAMINEITEM",11) == 0)&& (SIZE == 2)) || ((strncmp(command[0],"MOVE",4) == 0)&& (SIZE == 2)) || ((strncmp(command[0],"ATTACK",6) == 0)&& (SIZE == 2)) || ((strncmp(command[0],"USE",3) == 0 && strncmp(command[2],"TO",3) == 0 && SIZE == 4)))
	{
		status = true;
	}
	else
	{
		status = false;
	}
	return status;
}

