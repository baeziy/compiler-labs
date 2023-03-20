#include <stdio.h>
#include <stdlib.h>

char* removeSpaces(char *);

int main(int argc, char **argv)
{

    char *str = (char *)malloc(200);

    printf("Please enter a string: ");
    fgets(str, 200, stdin);

    printf("%s", removeSpaces(str));

    return 0;
}

char* removeSpaces(char *str)
{
    int charFoundFlag = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {

        if (str[i] != ' ')
        {

            charFoundFlag = 1;
        }
    }
}