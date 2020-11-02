/* parse.y - Yacc grammar for JSON. */
%{
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
extern FILE *yyin;

void yyerror(const char *s);
%}

%union {
	long long ival;
	long double fval;
	char *sval;
}

%token SPACE
%token <ival> INT
%token <fval> FLOAT
%token <sval> STRING

%start json

%%
taskmaster:
INT taskmaster		{ fprintf(stdout, "bison found an int: %d\n", $1); }
| STRING taskmaster	{ fprintf(stdout, "bison found a string: %s\n", $1); free($1); }
| INT			{ fprintf(stdout, "bison found an int: %d\n", $1); }
| STRING		{ fprintf(stdout, "bison found a string: %s\n", $1); free($1); }
;

json:
	element
	;

value:
	object
	| array
	| string
	| number
	| "true"
	| "false"
	| "null"
	;

object:
	'{' ws '}'
	| '{' members '}'
	;

members:
	member
	| member ',' members
	;

member:
	ws string ws ':' element
	;

array:
	'[' ws ']'
	| '[' elements ']'
	;

elements:
	element
	| element ',' elements
	;

element:
	ws value ws
	;

string:
	'"' characters '"'
	;

characters:
	""
	| character characters
	;

character:
	'0020' . '10FFFF' - '"' - '\'
	| '\' escape
	;

escape:
	'"'
	| '\'
	| '/'
	| 'b'
	| 'f'
	| 'n'
	| 'r'
	| 't'
	| 'u' hex hex hex hex
	;

hex:
	digit
	| 'A' . 'F'
	| 'a' . 'f'
	;

number:
	integer fraction exponent
	;

integer:
	digit
	| onenine digits
	| '-' digit
	| '-' onenine digits
	;

digits:
	digit
	| digit digits
	;

digit:
	'0'
	| onenine
	;

onenine:
	'1' . '9'
	;

fraction:
	""
	| '.' digits
	;

exponent:
	""
	| 'E' sign digits
	| 'e' sign digits
	;

sign:
	""
	| '+'
	| '-'
	;

ws:
	""
	| '0020' ws
	| '000A' ws
	| '000D' ws
	| '0009' ws
	;

%%

int main(int argc, char **argv) {
	// open a file handle to a particular file:
	FILE *myfile;

	if (argc == 2) {
		myfile = fopen(argv[1], "r");
	} else return 1;

	// make sure it's valid:
	if (!myfile) {
		fprintf(stderr, "I can't open %s!\n", argv[1]);
		return -1;
  	}
	// set lex to read from it instead of defaulting to STDIN:
	yyin = myfile;

	// Parse through the input:
	yyparse();
}

void yyerror(const char *s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}
