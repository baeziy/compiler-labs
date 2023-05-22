
%{
#include <stdio.h>
%}

%option noyywrap

%%

"if"|"else"|"while"|"do"|"for"   { printf("Keyword: %s\n", yytext); }
[0-9]+                           { printf("Integer: %s\n", yytext); }
[0-9]+"."[0-9]+                  { printf("Floating-point number: %s\n", yytext); }
[a-zA-Z][a-zA-Z0-9]*             { printf("Identifier: %s\n", yytext); }
"="                              { printf("Assignment operator: %s\n", yytext); }
"<="|"=="|"!="|">="|"<"|">"     { printf("Relational operator: %s\n", yytext); }
"+"|"-"|"*"|"/"                  { printf("Arithmetic operator: %s\n", yytext); }
"("                             { printf("Left Parentheses: %s\n", yytext); }
")"                          { printf("Right Parentheses: %s\n", yytext); }
"{"                                { printf("Right Brace: %s\n", yytext); }
"}"                          { printf("Left Brace: %s\n", yytext); }
";"                              { printf("Semicolon: %s\n", yytext); }
[ \t\n]                          { /* ignore whitespace */ }
"/*"(.|\n)*?"*/"                 { /* ignore comments */ }

%%

int main(void) {
    yylex();
    return 0;
}

