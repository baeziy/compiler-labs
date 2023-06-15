#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define productions
char productions[5][5] = {"BwA", "eps", "CxB", "yC", "z"};

// Define parsing table as per the given table
int parseTable[3][5] = {{-1, -1, 0, 0, 1},
                        {-1, -1, 3, 2, -1},
                        {-1, -1, -1, 4, -1}};



// Function to get the index of a character in the parsing table
int getIndex(char c) {
    switch(c) {
        case 'w': return 0;
        case 'x': return 1;
        case 'y': return 2;
        case 'z': return 3;
        case '$': return 4;
        case 'A': return 0;
        case 'B': return 1;
        case 'C': return 2;
    }
    return -1;
}
char* reverseStr(const char* str) {
    int l, r;
    char temp;
    int len = strlen(str);
    char* reversedStr = (char*)malloc(sizeof(char) * (len + 1));  // +1 for null-terminator

    strcpy(reversedStr, str);
    l = 0;
    r = len - 1;

    while (l < r) {
        // Swap characters
        temp = reversedStr[l];
        reversedStr[l] = reversedStr[r];
        reversedStr[r] = temp;
        
        l++;
        r--;
    }

    return reversedStr;
}


int main(int argc, char **argv) {
    // Check command line argument
    if(argc != 2) {
        printf("Error: You must provide exactly one argument.\n");
        return 1;
    }

    // Initialize input and stack
    char* input = argv[1];
    strcat(input, "$");  // append end symbol to input
    char stack[100] = "$A";
    int stackLen = 1;

    int i = 0;  // pointer to scan through the input
    printf("Stack\t\tinput\t\taction\n");
    while(strlen(stack) > 1) {
        int inputIndex = getIndex(input[i]);


        int stackIndex = getIndex(stack[stackLen]);

        // If end of stack or invalid character encountered
        if(inputIndex == -1 || stackIndex == -1) {
            break;
        }

        if (input[i] >= 'A' && input[i] <= 'Z'){
            perror("Error: Invalid character in input.\n");
            exit(1);
        }
        

        // if top of stack and input symbol are same then pop stack and increment input pointer
        if (stack[stackLen] == input[i]) {
            stack[stackLen--] = '\0';
            printf("%s\t\t%s\t\tmatch %c\n", stack, input + i, input[i++]);
            continue;
        }

        int prodIndex = parseTable[stackIndex][inputIndex];

        if(prodIndex == -1) {
            perror("Error: Invalid character in stack or inp.\n");
            break;
        }
        
        else{
            
            // pop stack and push production
            
            if (!strcmp(productions[prodIndex], "eps")){
                stack[stackLen--] = '\0';
                printf("%s\t\t%s\t\t%s\n", stack, input + i, productions[prodIndex]);
                continue;
            }
            
            stack[stackLen--] = '\0';
            strcat(stack, reverseStr(productions[prodIndex]));
            stackLen += strlen(productions[prodIndex]);
            printf("%s\t\t%s\t\t%s\n", stack, input + i, productions[prodIndex]);

        }
      

    }
    if((!strcmp(&stack[stackLen], "$")) && (!strcmp(&input[i], "$"))){
        printf("\nInput string '%s' is accepted\n", argv[1]);
        return 0;
    }

        printf("Input string '%s' is rejected.\n", argv[1]);

    return 0;
}
