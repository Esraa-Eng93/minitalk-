#include "minitalk.h"

void	send_each_char(pid_t pid, char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (((c >> i) & 1) == 1)
			kill(pid, SIGUSR1);
		else
			 kill(pid, SIGUSR2);
		usleep(110);
	}
}

void	send_each_word(pid_t pid, const char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
	send_each_char(pid, str[i]);
	i++;
	}
	send_each_char(pid, '\0');
}

int main(int ac, char **av)
{
	if (ac != 3 || av[2] == NULL)
	{
		write(1, "Please Enter the Server ID and the messeage\n", 45);
		return (-1);
	}
	pid_t server_id = ft_atoi(av[1]);
	send_each_word(server_id, av[2]);
	return (0);
}

