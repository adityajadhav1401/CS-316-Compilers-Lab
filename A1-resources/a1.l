%{
    #include "storetokens.hh"
    #include "parser.tab.h"
%}
digit [0-9]
operator [-+*/]
letter [a-zA-Z]
underscore _
meta [,;(){}]
int int
float float
void void
return return
equal =

%%
[ \t]                     { }
\/\/.*$                   { }
\n                        { ++yylineno; }
{digit}+                  { store_token_name("NUM",yytext,yylineno); yylval.integer_value=atoi(yytext); return INTEGER_NUMBER;}
{digit}+\.{digit}+        { store_token_name("FNUM",yytext,yylineno); yylval.double_value=atof(yytext); return DOUBLE_NUMBER;}
{operator}                { store_token_name("ARITHOP",yytext,yylineno); return yytext[0];}
{int}                     { store_token_name("INTEGER",yytext,yylineno); return INTEGER;}
{float}                   { store_token_name("FLOAT",yytext,yylineno);   return FLOAT;}
{equal}                   { store_token_name("ASSIGN_OP",yytext,yylineno); return ASSIGN;}
{void}                    { store_token_name("VOID",yytext,yylineno);    return VOID;}
{return}                  { store_token_name("RETURN",yytext,yylineno);  return RETURN;}
{meta}                    { store_token_name("META CHAR",yytext,yylineno); return yytext[0];}
{letter}({letter}|{digit}|{underscore})*    { store_token_name("NAME",yytext,yylineno);yylval.string_value= new std::string(yytext);  return NAME;}
.                         { printf("Error\n");}
