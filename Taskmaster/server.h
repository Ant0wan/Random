#ifndef SERVER_H
# define SERVER_H

# define SERVER_URL "http://localhost:9001"
# define SOCKEF_FILE_MODE "0700"

struct arguments {
	char *cgfile;
	char *child_dir;
	char *dir;
	char *fdsnum;
	char *level;
	char *lgfile;
	char *lgnum;
	char *mask;
	char *maxbytes;
	char *pdfile;
	char *poptions;
	char *procnum;
	char *str;
	char *usern;
	_Bool childlogdir:1;
	_Bool configuration:1;
	_Bool directory:1;
	_Bool identifier:1;
	_Bool lg_backup:1;
	_Bool lg_maxbytes:1;
	_Bool logfile:1;
	_Bool loglevel:1;
	_Bool minfds:1;
	_Bool minprocs:1;
	_Bool nocleanup:1;
	_Bool nodaemon:1;
	_Bool pidfile:1;
	_Bool profile_options:1;
	_Bool strip_ansi:1;
	_Bool umask:1;
	_Bool user:1;
};

struct unix_http_server
{
	_Bool file;
	_Bool chmod;
	char *filename;
	char *chmod_val;
};

#endif
