int	launch_process(t_process *p, pid_t pgid, int infile, int outfile, int errfile, int foreground)
{
	extern char	**environ;
	char		*path;
	pid_t		pid;

	path = ft_strdup(p->argv[0]);
	path_concat(&path);
	execve(path, p->argv, environ);
	ft_perror("Failed to launch process using execve");
	exit(1);
}

