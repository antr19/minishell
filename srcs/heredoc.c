
#include "../incs/minishell.h"

static void	write_heredoc(t_redir *redir, int i)
{
	char	*str;
	int		fd;

	fd = open(redir->filename[i], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
		exit(1);
	str = readline("> ");
	while (str != NULL && ft_strcmp(str, redir->filename[i]))
	{
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
		free(str);
		str = readline("> ");
	}
	free(str);
	close(fd);
}

int	deal_heredoc(t_redir *redir, int i)
{
	pid_t	pid;
	int		fd;

	fd = 0;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	pid = fork();
	if (pid == -1)
		return (0);
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		write_heredoc(redir, i);
		exit(0);
	}
	else
	{
		waitpid(pid, NULL, 0);
		fd = open(redir->filename[i], O_RDONLY, 0644);
		if (fd < 0)
			exit (1);
		dup_close(fd, 0);
		if (unlink(redir->filename[i]))
			return (0);
		return (1);
	}
}
