%{
#include <stdio.h>
%}

%option noyywrap

%%

^"#"[^\n]* { printf("Preprocessor directive: %s\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]*[[:blank:]]*[a-zA-Z_][a-zA-Z0-9_]*[[:blank:]]*\([^)]*\)[[:blank:]]*\{ { printf("Function definition: %s\n", yytext); }
[[:blank:]*][a-zA-Z_][a-zA-Z0-9_]*[[:blank:]]*\([^)]*\); { printf("Function call: %s\n", yytext); }
"return"[[:blank:]]*[a-zA-Z0-9_]*[[:blank:]]*; { /* ignore return statements */ }
[[:blank:]]*\}[[:blank:]]*\n { /* ignore lines with only a closing brace */ }

%%

int main(void) {
    yylex();
    return 0;
}
