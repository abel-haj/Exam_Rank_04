

#include <sys/wait.h>
#include <unistd.h>

void	ft_putstr_fd(int fd, char *s)
{
	for (int i=0;s[i];i++)
	{
		write(1, &s[i], 1);
	}
}

int	main ( int ac, char **av, char **envp )
{
	int	ret;
	pid_t	pid;
	char	*path;
	int	status;

	path = av[1];
	char *args[] = {path, av[2], NULL};
	pid = fork();

	if (pid < 0)
	{
		ft_putstr_fd(2, "fatal: error\n");
	}
	// child process
	else if (pid == 0)
	{
		ret = execve(path, args, envp);
		if (ret == -1)
		{
			ft_putstr_fd(2, "error: cannot execute ");
			ft_putstr_fd(2, path);
			ft_putstr_fd(2, "\n");
		}
	}
	// parent process
	else
	{
		waitpid(pid, &status, WCONTINUED);
	}

	return 0;
}

