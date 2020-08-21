%{
#include "wc.h"

struct wc	count = {0};
struct argument	arguments = {0};

%}

%%

[^ \t\n\r\f\v]+	{ count.words++; count.chars += strlen(yytext); }
\n		{ count.chars++; count.lines++; }
.		{ count.chars++; }

%%



int	main(int argc, char **argv)
{
	int	status;
	(void)input;
	(void)yyunput;

	status = 0;
	if (argc > 1)
	{
		status = parse_arguments(argc, argv);
		if (status)
			exit(EXIT_FAILURE);
		/* Here should each file be lexed */
	}
	else
	{
		yylex();
		fprintf(stdout, "%8d%8d%8d\n", count.lines, count.words, count.chars);
	}
	return (EXIT_SUCCESS);
}
