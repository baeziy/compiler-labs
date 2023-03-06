
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        perror("Invalid arguments\n");
        exit(1);
    }

    FILE *fp;
    fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        perror("Uh oh, Can't open file");
        exit(1);
    }
    int c;
    char newline = '\n';
    int count = 1;
    int charcount = 0;
    while (1)
    {

       
        c = fgetc(fp);
         if (feof(fp))
            break;

        if (count == 1)
        {
            printf("%d. ", count);
            fputc(c, stdout);
            charcount+=2;
            count += 1;
        }

        else if (c == '\n')
        {
            fputc(c, stdout);
            printf("%d. ", count);
            count += 1;
        }
        else{
        if(c!= ' ')
         charcount+=1;
         fputc(c, stdout);
        }
            
    }
    printf("\n");
    printf("This file carries %d characters.\n", charcount);
    
    fclose(fp);
}
