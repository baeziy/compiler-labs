#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *removeSpaces(char *);

int main(int argc, char *argv[])
{
    
    if (argc != 2){
        perror("Invalid no of arguments\n");
        exit(1);
    }

    char *str = malloc(strlen(argv[1]) + 2);
    strcpy(str, argv[1]); 
    strcat(str, " \n");


    printf("%s", removeSpaces(str));


    free(str);
    return 0;
}

char *removeSpaces(char *str)
{
    int charFoundFlag = 0;
    int spaceCounter = 0;
    int newStrCounter = 1;
    char *newStr = (char *)malloc(200);
	newStr[0] = '"';
    for (int i = 0; str[i] != '\n'; i++)
    {

        if (str[i] != ' ')
        {
        	
            newStr[newStrCounter] = str[i];
            newStrCounter++;
            charFoundFlag = 1;
            spaceCounter = 0;
        }
        //space found at starting
        
        else if (str[i] == ' ' && charFoundFlag == 0)
        {
            continue;
        }
        // space found after a nonspace
        
        else
        {	
            if (spaceCounter == 0)
            {
                newStr[newStrCounter] = str[i];
                newStrCounter++;
                spaceCounter++;
            }
        }
    }
    
	 newStr[newStrCounter] = '"';
    int semiColonCheck = 0;
    char* finalStr = (char*)malloc(200);
    finalStr[0] = '"';
    int i = 1;
    for(; newStr[i] != '"'; i++){
        
        if(newStr[i] == ';' && newStrCounter-2 == i){
            semiColonCheck = 1;
            if(newStr[i-1] == ' '){
                finalStr[i-1] = ';';
            }
            if(newStr[i+1] == ' '){
                finalStr[i] = '"';
                finalStr[i+1] = '\n';
                break;
            }
        }
        finalStr[i] = newStr[i];
    }
    if (!semiColonCheck){
        finalStr[i-1] = '\"';
        finalStr[i] = '\n'; 
        // strcat(finalStr, "\"\n");
    }
    return finalStr;
}




