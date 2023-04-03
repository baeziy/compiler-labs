#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){

   if (argc != 2){
        perror("Invalid arguments\n");
        exit(1);
    }

    if(argv[1][sizeof(argv[1])-1] != '!'){
        perror("Invalid string\n");
        exit(1);
    }

    char *str = (char*) malloc(200);
    str = argv[1];
    printf("Input string is: %s", str);

    int i = 0;
    char c;

    while(1){

        q1:
            c = str[i++];

            switch(c){
                case 'a':
                    printf()
                    goto q2;
                case 'b':
                    goto q4;
                default:
                    if (c == '!'){
                
                        printf("End of string.\nString rejected\n");
                    }

                       
                    printf("Wrong string\n");
                    exit(2);
            }


            


    }


    return 0;
}