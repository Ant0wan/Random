#include <argp.h>
#include <stdlib.h>

#include "wc.h"

const char *argp_program_version = ARGP_VERSION;
const char *argp_program_bug_address = REPORT_BUG;
static char doc[] = FT_WC_DOC;
static char args_doc[] = ARGS_DOC;

const struct argp_option options[] =
{
	{ "bytes", 'c', 0, 0, "print the byte counts", 0 },
	{ "chars", 'm', 0, 0, "print the character counts", 0 },
	{ "lines", 'l', "URL", 0, "print the newline counts", 0 },
	{ "max-line-length", 'L', 0, 0, "print the maximum display width", 0 },
	{ "words", 'w', "", 0, "print the word counts", 0 },
	{ 0 }
};

static error_t parse_opt(int key, char *arg, struct argp_state *state)
{
	(void)state;
	(void)arg;
/*	printf("\narg_num:%d\n", arg_num);
*/
	switch (key)
	{
		case 'c':
			arguments.c = 1;
			break;
		default:
			return ARGP_ERR_UNKNOWN;
	}
	return 0;
}

static struct argp argp = { options, parse_opt, args_doc, doc, NULL, NULL, NULL };

/*
static void help_command(char *input)
{
	(void)input;
	fprintf(stdout, HELP);
}
*/

int	parse_arguments(int argc, char **argv)
{
	if (argp_parse(&argp, argc, argv, 0, 0, &arguments))
	{
		perror(argv[0]);
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
