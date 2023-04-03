#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]){

   if (argc != 2){
        perror("Invalid arguments\n");
        exit(1);
    }

    if(argv[1][strlen(argv[1])-1] != '!'){
        perror("Invalid string\n");
        exit(1);
    }

    char *str = (char*) malloc(200);
    str = argv[1];
    printf("Input string is: %s\n", str);

    int i = 0;
    char c;
        q1:
            c = str[i++];
            switch(c){
                case 'a':
                    printf("Recieved a on state 1 ---- Moving to state 2\n");
                    goto q2;
                case 'b':
                    printf("Recieved b on state 1 ---- Moving to state 4\n");
                    goto q4;
                default:
                    if (c == '!'){
                
                        printf("End of string.\nString rejected\n");
                    }
                    else printf("Wrong string\n");
                    exit(2);
            }
         q2:
            c = str[i++];
            switch(c){
                case 'a':
                    printf("Recieved a on state 2 ---- Moving to state 3\n");
                    goto q3;
                case 'b':
                    printf("Recieved b on state 2 ---- Moving to state 4\n");
                    goto q4;
                default:
                    if (c == '!'){
                
                        printf("End of string.\nString rejected\n");
                    }
                    else printf("Wrong string\n");
                    exit(2);
            }
         q3:
            c = str[i++];
            switch(c){
                case 'a':
                    printf("Recieved a on state 3 ---- Moving to state 3\n");
                    goto q3;
                case 'b':
                    printf("Recieved b on state 3 ---- Moving to state 4\n");
                    goto q4;
                default:
                    if (c == '!'){
                
                        printf("End of string.\nString Accepted\n");
                    }
                    else printf("Wrong string\n");
                    exit(2);
            }
         q4:
            c = str[i++];
            switch(c){
                case 'a':
                    printf("Recieved a on state 4 ---- Moving to state 2\n");
                    goto q2;
                case 'b':
                    printf("Recieved b on state 4 ---- Moving to state 5\n");
                    goto q5;
                default:
                    if (c == '!'){
                
                        printf("End of string.\nString rejected\n");
                    }
                    else printf("Wrong string\n");
                    exit(2);
            }
         q5:
            c = str[i++];
            switch(c){
                case 'a':
                    printf("Recieved a on state 5 ---- Moving to state 2\n");
                    goto q2;
                case 'b':
                    printf("Recieved b on state 5 ---- Moving to state 5\n");
                    goto q5;
                default:
                    if (c == '!'){
                
                        printf("End of string.\nString Accepted\n");
                    }
                    else printf("Wrong string\n");
                    exit(2);
            }



    return 0;
}