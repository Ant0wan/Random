%{ /* lex.l - Lexing rules for JSON */
#include <stdlib.h>
#include <string.h>

#include "json.tab.h"
%}

digit   [0-9]
digit1  [1-9]
digits  {digit}+
int     -?{digit}|-?{digit1}{digits}
char	[A-Za-z0-9/_\.+-]
str	{char}+

%%

[ \t\n\r]+	{ return SPACE };
[\[]		{ return '[' };
[\]]		{ return ']' };
[\{]		{ return '{' };
[\}]		{ return '}' };
{int}		{ yylval.ival = atoi(yytext); return INT; }
{str}		{ yylval.sval = strdup(yytext); return STRING; }


%%
