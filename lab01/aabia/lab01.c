#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    // Checking the arguments are complete or not
   if (argc != 2)
    {
        printf("\nIncomplete arguments!!!");
        return 0;
        
    }
    
 // Open the file

FILE *fp;
    
fp = fopen(argv[1], "r");
    
if (fp == NULL)
    {
        printf("\nFile is empty.");
        return 0;
        
    }
    
 // Reading thie file character by character
int line_no = 1;
    int c;
    bool flag = true;
    c = fgetc(fp);
    int no_of_ch = 0;
    while (c != EOF)
    {
        if (flag == true)
        {
            printf("%d - ", line_no);
            flag = false;
            
        }
        if (c == '\n')
        {
            line_no++;
            flag = true;
            

        }
        
fputc(c, stdout);
        (c = fgetc(fp));
        
if (c != ' ' && c != '\n' && c != '\t')
        {
            
no_of_ch++;
            
        }
        


    }
    
printf("\nNo of Characters are: %d  \n", no_of_ch);
    return 0;
}