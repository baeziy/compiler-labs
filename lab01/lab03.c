#include<stdio.h>
#include<stdlib.h>

void removeBlankLines(FILE *);
void displayFile(FILE *);
void addLineNumber(FILE *);

int main(int argc, char *[] argv){
  
  if (argc != 4){

    printf("Invalid arguments\n");
    exit(1);
   
  }

  FILE *fp1;

    fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        perror("Uh oh, Can't open file1");
        exit(1);
    }

    
  
    return 0;
}

void addLineNumber(FILE *fp1){
  FILE *fp2;
  fp2 = fopen(argv[1], "w");

    if (fp2 == NULL)
    {
        perror("Uh oh, Can't create file2");
        exit(1);
    }

    int c;
    int charCounter = 0;
    while (1)
    {
        c = fgetc(fp1);
         if (feof(fp1))
            break;
	 charCounter++;

	 if(charCounter == 1){
	   fprintf(fp2, "%d. ", charCounter);
	 }

	 if(c == '\n'){
	   fprintf(fp2, "\n%d. ", charCounter);
	 }
	 else{
	   fputc(c, fp2);
	 }
            
    }

  
}
