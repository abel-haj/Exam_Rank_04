


#include <unistd.h>

void	ft_putstr_fd(int fd, char *s)
{
	for (int i=0;s[i];i++)
	{
		write(1, &s[i], 1);
	}
}

int	main ( int ac, char **av, char *envp )
{
	int	ret;
	pid_t	pid;

	pid = fork();

	// child process
	if (pid == 0)
	{
		ret = execve(envp);
		if (ret == -1)
		{
			ft_putstr_fd(2, );
			ft_putstr_fd(2, );
			ft_putstr_fd(2, );
		}
	}

	return 0;
}

