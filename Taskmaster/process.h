#ifndef CONFIG_H
# define CONFIG_H

# include <termios.h>

# define RESTART_NEVER      0x01
# define RESTART_UNEXPECTED 0x02
# define RESTART_ALWAYS     0x03

struct config
{
	char **argv;
	int numprocs;
	int umask;
	char *workingdir;
	_Bool autostart;
	int autorestart; /* RESTART_* value */
	int *exitcodes;
	int exitcodes_nb; /* len of exitcodes tab */
	int startretries;
	int starttime;
	int stopsignal; /* signals value */
	int stoptime;
	int stdout; /* fd from opening file */
	int stderr; /* fd from opening file */
	char **env;
};

struct process
{
	struct config config;
	int argc;
	pid_t pid;
	pid_t pgid;
	char completed;
	char stopped;
	int status;
	char notified;
	struct termios tmodes;
};

#endif
