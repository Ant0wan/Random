#include <argp.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <unistd.h>

#include "server.h"
#include "help.h"
#include "server.h"

const char *argp_program_version = ARGP_VERSION;
const char *argp_program_bug_address = REPORT_BUG;
static char doc[] = SERVER_DOC;
static char args_doc[] = ARGS_DOC;

const struct argp_option options[] =
{
	{ "configuration", 'c', "FILENAME", 0, "Configuration file path (searches if not given)", 0 },
	{ "nodaemon", 'n', 0, 0, "Run in the foreground (same as 'nodaemon=true' in config file)", 0 },
	{ "user", 'u', "USER", 0, "Run Taskmaster-deamon as this user (or numeric uid)", 0 },
	{ "umask", 'm', "UMASK", 0, "Use this umask for daemon subprocess (default is 022)", 0 },
	{ "directory", 'd', "DIRECTORY", 0, "Directory to chdir to when daemonized", 0 },
	{ "logfile", 'l', "FILENAME", 0, "Use FILENAME as logfile path", 0 },
	{ "logfile_maxbytes", 'y', "BYTES", 0, "Use BYTES to limit the max size of logfile", 0 },
	{ "logfile_backups", 'z', "NUM", 0, "Number of backups to keep when max bytes reached", 0 },
	{ "loglevel", 'e', "LEVEL", 0, "Use LEVEL as log level (debug,info,warn,error,critical)", 0 },
	{ "pidfile", 'j', "FILENAME", 0, "Write a pid file for the daemon process to FILENAME", 0 },
	{ "identifier", 'i', "STR", 0, "Identifier used for this instance of Taskmaster-deamon", 0 },
	{ "childlogdir", 'q', "DIRECTORY", 0, "The log directory for child process logs", 0 },
	{ "nocleanup", 'k', 0, 0, "Prevent the process from performing cleanup (removal of old automatic child log files) at startup", 0 },
	{ "minfds", 'a', "NUM", 0, "The minimum number of file descriptors for start success", 0 },
	{ "strip_ansi", 't', 0, 0, "Strip ansi escape codes from process output", 0 },
	{ "minprocs", 'p', "NUM", 0, "The minimum number of processes available for start success", 0 },
	{ "profile_options", 'o', "OPTIONS", 0, "Run Taskmaster-deamon under profiler and output results based on OPTIONS, which  is a comma-sep'd list of 'cumulative', 'calls', and/or 'callers', e.g. 'cumulative,callers')", 0 },
	{ 0 }
};

static error_t parse_opt(int key, char *arg, struct argp_state *state)
{
	struct arguments *arguments = state->input;

	switch(key)
	{
		case 'c':
			arguments->configuration = 1;
			arguments->cgfile = arg;
			break;
		case 'n':
			arguments->nodaemon = 1;
			break;
		case 'u':
			arguments->user = 1;
			arguments->usern = arg;
			break;
		case 'm':
			arguments->umask = 1;
			arguments->mask = arg;
			break;
		case 'd':
			arguments->directory = 1;
			arguments->dir = arg;
			break;
		case 'l':
			arguments->logfile = 1;
			arguments->lgfile = arg;
			break;
		case 'y':
			arguments->lg_maxbytes = 1;
			arguments->maxbytes = arg;
			break;
		case 'z':
			arguments->lg_backup = 1;
			arguments->lgnum = arg;
			break;
		case 'e':
			arguments->loglevel = 1;
			arguments->level = arg;
			break;
		case 'j':
			arguments->pidfile = 1;
			arguments->pdfile = arg;
			break;
		case 'i':
			arguments->identifier = 1;
			arguments->str = arg;
			break;
		case 'q':
			arguments->childlogdir = 1;
			arguments->child_dir = arg;
			break;
		case 'k':
			arguments->nocleanup = 1;
			break;
		case 'a':
			arguments->minfds = 1;
			arguments->fdsnum = arg;
			break;
		case 't':
			arguments->strip_ansi = 1;
			break;
		case 'p':
			arguments->minprocs = 1;
			arguments->procnum = arg;
			break;
		case 'o':
			arguments->profile_options = 1;
			arguments->poptions = arg;
			break;
		default:
			return ARGP_ERR_UNKNOWN;
	}
	return 0;
}

static struct argp argp = { options, parse_opt, args_doc, doc, NULL, NULL, NULL };

int main(int argc, char **argv){

	struct arguments arguments = {0};

	if (argp_parse (&argp, argc, argv, 0, 0, &arguments)) {
		perror(argv[0]);
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
