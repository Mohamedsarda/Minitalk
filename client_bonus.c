/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:35:09 by msarda            #+#    #+#             */
/*   Updated: 2024/01/12 18:39:48 by msarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"

static void	ft_handler(int pid, char c)
{
	int	i;
	int	bit;

	i = 8;
	bit = 0;
	while (i--)
	{
		bit = (c >> i) & 1;
		if (!bit)
		{
			if (kill(pid, SIGUSR1) < 0)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR2) < 0)
				exit(1);
		}
		usleep(800);
	}
}

static void	ft_msg_handler(int i)
{
	(void)i;
	ft_printf("Message Sent.\n");
}

int	main(int c, char **ar)
{
	int	pid;

	if (c == 3)
	{
		pid = check_pid(ar[1]);
		if (pid <= 0)
		{
			ft_printf("\nYour Pid Is Incorrect\n");
			exit (1);
		}
		if (signal(SIGUSR1, ft_msg_handler) < 0)
		{
			ft_printf("Failed To handle SIGUSR1");
			exit(1);
		}
		while (*ar[2])
			ft_handler(pid, *ar[2]++);
		ft_handler(pid, *ar[2]);
	}
	else
		ft_printf("Make Sure You Enter The Right Number Of Params");
	return (0);
}
