#ifndef CLIENT_H
# define CLIENT_H

# define SERVER_URL "http://localhost:9001"

# define PROMPT "\e[38;5;44mTaskmaster[\e[38;5;82m%s@%s\e[38;5;44m]:$ \e[0m"

struct arguments {
	char *filename;
	char *passwd;
	char *url;
	char *user;
	_Bool configuration:1;
	_Bool interactive:1;
	_Bool history_file:1;
	_Bool password:1;
	_Bool serverurl:1;
	_Bool username:1;
};

struct s_client {
	int argc;
	char **argv;
	char **envp;
	char *input;
	long path_max;
	char *bin_path;
};

#endif
