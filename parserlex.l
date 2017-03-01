%{
#include<stdio.h>
int count=1;
%}

%%
"int"|"float"|"char"|"double" {fprintf(yyout,"%s","d");}
"return" {fprintf(yyout,"%s","r");}
"return"[0-9]+ {fprintf(yyout,"%s","raxa") ;}
"for" {fprintf(yyout,"%s","f");}
"for("[a-zA-Z]"=" {fprintf(yyout,"%s","f(ax");}
"while" {fprintf(yyout,"%s","w");}
"if" {fprintf(yyout,"%s","i");}
"do{"[a-zA-Z0-9 \n]*"}" {fprintf(yyout,"%s","");}
"else" {fprintf(yyout,"%s","e");}
"main" {fprintf(yyout,"%s","m");}
"printf" {fprintf(yyout,"%s","p");}
"scanf" {fprintf(yyout,"%s","p");}
"break" {fprintf(yyout,"%s","o");}
"&"[a-zA-Z]+ {fprintf(yyout,"%s","a");}  
"\""[a-zA-Z0-9\\ ]+ {fprintf(yyout,"%s","\"a\"");}
[a-zA-Z0-9\\ ]+"\"" {fprintf(yyout,"%s","a\"");}
[a-zA-Z0-9\\ ]+"%d"|"%c"|"%s"|"%l"|"%ld" {fprintf(yyout,"%s","ab");}
"%d"|"%c"|"%s"|"%l"|"%ld" {fprintf(yyout,"%s","b");}
"["[a-zA-Z0-9]+"]" ;
[0-9]+  {fprintf(yyout,"%s","n");}
"int"|"float"|"char"|"double"[a-zA-Z]+"," {fprintf(yyout,"%s","d");}
[a-zA-Z0-9\[\]]+"," ;
[a-zA-Z]+ {fprintf(yyout,"%s","a");}
"+"|"-"|"*"|"/" {fprintf(yyout,"%s","x");}
"++"|"--" {fprintf(yyout,"%s","xn");}
[(] {fprintf(yyout,"%s","(");}
[)] {fprintf(yyout,"%s",")");}
[}] {fprintf(yyout,"%s","}");}
[{] {fprintf(yyout,"%s","{");}
[;] {fprintf(yyout,"%s",";");}
[<] {fprintf(yyout,"%s","y");}
[>] {fprintf(yyout,"%s","y");}
"<="|">="|"=="|"!=" {fprintf(yyout,"%s","y");}
"||"|"&&"|"|"|"&" {fprintf(yyout,"%s","z");}
"//"[a-zA-Z0-9 ]* {fprintf(yyout,"%s","");}
"/*"(.|"\n")*"*/" {fprintf(yyout,"%s","");}
[ ]*	;
[\t]*	;
[\n]* fprintf(yyout,"%d",++count) ;
. ;
%%

int main()
{
yyin=fopen("input.c","r");
yyout=fopen("output.c","w");
fprintf(yyout,"%s","1");
yylex();
fprintf(yyout,"%s","$");
return 0;

}

int yywrap() { return 1;}


