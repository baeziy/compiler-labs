#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Invalid arguments\n");
        exit(1);
    }

    int lineCounter = 0;
    int charCounterPLine = 0;

    FILE *fp;

    fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        perror("Uh oh, Can't open file");
        exit(1);
    }

    char *line = (char *)malloc(200);
    int flag = 0;

    // flag checking if there is a space found at start of the line (we can't count it)
    int spaceFlag = 1;

    int counterWithoutTabs = 0;



    while (1)
    {
        flag = 0;
        spaceFlag = 1;
        fgets(line, 200, fp);

        lineCounter++;

        for (; line[charCounterPLine] != '\0'; charCounterPLine++)
        {
            if (line[charCounterPLine] == ' ' && spaceFlag == 1)
            {   
                // as we can't count spaces before a string starts, thus
                counterWithoutTabs = 0;
            }
            else
            {
                counterWithoutTabs++;
                spaceFlag = 0;
                
                // as there is \n on every line and we have to print [chars] on the same line, we remove \n with \0
                if (line[charCounterPLine] == '\n')
                {
                    line[charCounterPLine] = '\0';
                    flag = 1;
                }
            }
        }


        fputs(line, stdout);

        //checking if it's not the last line as last line doesn't contain \n
        if (flag == 1)
            printf(" [%d]\n", --counterWithoutTabs);
        else
            printf(" [%d]\n", counterWithoutTabs);

        charCounterPLine = 0;
        counterWithoutTabs = 0;

        if (feof(fp))
        {
            break;
        }
    }

    printf("\nTotal number of lines in the file are: %d\n", lineCounter);

    return 0;
}