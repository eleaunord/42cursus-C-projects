/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:20:27 by eleroty           #+#    #+#             */
/*   Updated: 2024/04/25 14:28:42 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>

int		g_flag;

void	send_char(int pid, unsigned char c)
{
	int	i;
	int	signal;
	int	send_sig_to_server;

	i = 8;
	while (i--)
	{
		g_flag = 0;
		if (((c >> i) & 1) == 1)
			signal = SIGUSR1;
		else
			signal = SIGUSR2;
		send_sig_to_server = kill(pid, signal);
		if (send_sig_to_server == -1)
			exit(ft_printf("Error when sending signal to server\n"));
		while (g_flag == 0)
			;
	}
}

void	send_message(int pid, const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		send_char(pid, str[i++]);
	send_char(pid, '\0');
}

void	server_signal(int signal)
{
	if (signal == SIGUSR1)
		g_flag = 1;
}

int	main(int argc, char **argv)
{
	struct sigaction	client;
	int					pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (kill(pid, 0) == -1 || pid <= 0)
			exit(ft_printf("PID is invalid"));
		ft_memset(&client, 0, sizeof(struct sigaction));
		client.sa_handler = &server_signal;
		if (sigaction(SIGUSR1, &client, NULL) == -1)
			exit(ft_printf("Error sigaction\n"));
		send_message(pid, argv[2]);
		send_message(pid, "\n");
	}
	else
		exit(ft_printf("Error in your command-line arguments\n"));
	return (0);
}
