/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:35:17 by msarda            #+#    #+#             */
/*   Updated: 2024/01/12 18:45:03 by msarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"

static void	ft_handler(int sig, siginfo_t *info, void *other)
{
	static int		i;
	static int		c;
	static pid_t	pid;

	(void)other;
	if (pid != info->si_pid)
	{
		i = 0;
		c = 0;
		pid = info->si_pid;
	}
	c = (c << 1) + (sig - 30);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;

	ft_printf("Server Pid Is : %d\n", getpid());
	sig.sa_sigaction = ft_handler;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
