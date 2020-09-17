#ifndef HELP_H
# define HELP_H

# define HELP "\n"\
"default commands (type help <topic>):\n"\
"=====================================\n"\
"add    exit      open  reload  restart   start   tail\n"\
"avail  fg        pid   remove  shutdown  status  update\n"\
"clear  maintail  quit  reread  signal    stop    version\n\n"

# define ADD "add <name> [...]	Activates any updates in config for process/group\n"

# define AVAIL "avail			Display all configured processes\n"

# define CLEAR "clear <name>		Clear a process' log files.\n"\
	       "clear <name> <name>	Clear multiple process' log files\n"\
	       "clear all		Clear all process' log files\n"

# define EXIT "exit	Exit the supervisor shell.\n"

# define FG "fg <process>	Connect to a process in foreground mode\n"\
	    "		Ctrl-C to exit\n"

# define MAINTAIL "maintail -f 	Continuous tail of supervisor main log file (Ctrl-C to exit)\n"\
		  "maintail -100	last 100 *bytes* of supervisord main log file\n"\
		  "maintail	last 1600 *bytes* of supervisor main log file\n\n"

# define OPEN "open <url>	Connect to a remote supervisord process.\n"\
	      "		(for UNIX domain socket, use unix:///socket/path)\n"

# define PID "pid			Get the PID of supervisord.\n"\
	     "pid <name>		Get the PID of a single child process by name.\n"\
	     "pid all			Get the PID of every child process, one per line.\n"

# define QUIT "quit	Exit the supervisor shell.\n"

# define RELOAD "reload 		Restart the remote supervisord.\n"

# define REMOVE "remove <name> [...]	Removes process/group from active config\n"

# define REREAD "remove <name> [...]	Removes process/group from active config\n"

# define RESTART "restart <name>		Restart a process\n"\
		 "restart <gname>:*	Restart all processes in a group\n"\
		 "restart <name> <name>	Restart multiple processes or groups\n"\
		 "restart all		Restart all processes\n"\
		 "Note: restart does not reread config files. For that, see reread and update.\n"

# define SHUTDOWN "shutdown 	Shut the remote supervisord down.\n"

# define SIGNAL "signal <signal name> <name>		Signal a process\n"\
		"signal <signal name> <gname>:*		Signal all processes in a group\n"\
		"signal <signal name> <name> <name>	Signal multiple processes or groups\n"\
		"signal <signal name> all		Signal all processes\n"

# define START "start <name>		Start a process\n"\
	       "start <gname>:*		Start all processes in a group\n"\
	       "start <name> <name>	Start multiple processes or groups\n"\
	       "start all		Start all processes\n"

# define STATUS "status <name>		Get status for a single process\n"\
		"status <gname>:*	Get status for all processes in a group\n"\
		"status <name> <name>	Get status for multiple named processes\n"\
		"status			Get all process status info\n"

# define STOP "stop <name>		Stop a process\n"\
	      "stop <gname>:*		Stop all processes in a group\n"\
	      "stop <name> <name>	Stop multiple processes or groups\n"\
	      "stop all		Stop all processes\n"

# define TAIL "tail [-f] <name> [stdout|stderr] (default stdout)\n"\
	      "Ex:\n"\
	      "tail -f <name>		Continuous tail of named process stdout\n"\
	      "			Ctrl-C to exit.\n"\
	      "tail -100 <name>	last 100 *bytes* of process stdout\n"\
	      "tail <name> stderr	last 1600 *bytes* of process stderr\n"

# define UPDATE "update			Reload config and add/remove as necessary, and will restart affected programs\n"\
		"update all		Reload config and add/remove as necessary, and will restart affected programs\n"\
		"update <gname> [...]	Update specific groups\n"

# define VERSION "version			Show the version of the remote supervisord process\n"

# define ARGP_VERSION \
"Taskmaster (42 project) 0.0\n"\
"No Copyright (C) 2020.\n"\
"No License. <https://github.com/Ant0wan/Taskmaster.git>\n"\
"This is free software: you are free to change and redistribute it.\n"\
"There is NO WARRANTY, to the extent permitted by law.\n\n"\
"Written by Antoine Barthelemy."

# define REPORT_BUG "<abarthel@student.42.fr>"

# define CLIENT_DOC "Taskmaster-client controls applications run by Taskamaster-deamon from the command line."

# define SERVER_DOC "Taskamaster-deamon runs a set of applications as daemons."

# define ARGS_DOC "[ARGUMENTS]"

#endif
