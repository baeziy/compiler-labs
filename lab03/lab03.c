#include<stdio.h>
#include<stdlib.h>

void removeBlankLines(FILE *, char *[]);
void displayFile(char *, int);
void addLineNumber(FILE *, char *[]);

int main(int argc, char * argv[]){
  
  if (argc != 4){

    printf("Invalid arguments\n");
    exit(1);
   
  }

  FILE *fp1;

    fp1 = fopen(argv[1], "r");

    if (fp1 == NULL)
    {
        perror("Uh oh, Can't open file1");
        exit(1);
    }
	

	addLineNumber(fp1, argv);

	
	displayFile(argv[2], 2);
	
	fp1 = fopen(argv[1], "r");

    if (fp1 == NULL)
    {
        perror("Uh oh, Can't open file1");
        exit(1);
    }
	removeBlankLines(fp1, argv);
	
	fclose(fp1);
	displayFile(argv[3], 3);
    
  
    return 0;
}

void displayFile(char*file, int n){
	
	FILE *fp;
	fp = fopen(file, "r");

    if (fp == NULL)
    {
        perror("Uh oh, Can't open file1");
        exit(1);
    }
    
    printf("=======FILE %s=======\n", file);
    char *line = (char *)malloc(200);
	
	while (1)
    {
     fgets(line, 200, fp);
      printf("%s", line);
     if (feof(fp)){
     printf("\n");
      break;
     }
           
     
         
    }
    
    fclose(fp);

}

void addLineNumber(FILE *fp1, char * argv[]){
  FILE *fp2;
  fp2 = fopen(argv[2], "w");

    if (fp2 == NULL)
    {
        perror("Uh oh, Can't create file2");
        exit(1);
    }

    int c;
    int charCounter = 0;
    int lineCounter = 1;
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
	   fprintf(fp2, "\n%d. ", ++lineCounter);
	 }
	 else{
	   fputc(c, fp2);
	 }
            
    }
    
    fclose(fp2);
    fclose(fp1);
    }
    
    
 void removeBlankLines(FILE *fp1, char * argv[]){
    FILE *fp3;
  	fp3 = fopen(argv[3], "w");

    if (fp3 == NULL)
    {
        perror("Uh oh, Can't create file3");
        exit(1);
    }

    int lineCounter = 1;
    int flag = 0;
    int newlineIndex = 0;
    char *line = (char *)malloc(200);
   int flag2=0;
   while(fgets(line, 200, fp1)){
   flag = 0;
   flag2 = 0;
   newlineIndex = 0;
    
      for(int i = 0; line[i]!='\0'; i++){
	if((line[i] == '\n') && (i == 0)){
		flag = 1;
		continue;
	}
	if(line[i] != ' '){
		flag2 = 1;
	}
	if(line[i] == '\n')
		newlineIndex = i;
      }
      
      
      if (flag == 1 || flag2 == 0){
      	continue;
      }
      
      
      
      else{
         fprintf(fp3, "\n%d. ", lineCounter++);
      line[newlineIndex] = ' ';
      fputs(line, fp3);
      }
   
   
   }
    	
        
         fclose(fp3);
    

    
  }
    	

