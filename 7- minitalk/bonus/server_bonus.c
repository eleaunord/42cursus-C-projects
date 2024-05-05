/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:20:18 by eleroty           #+#    #+#             */
/*   Updated: 2024/04/19 15:41:51 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>

void	client_signal(int sig, siginfo_t *info, void *ucontext)
{
	static char	character;
	static int	bit_count;
	int			sig_acknowledgment;

	(void)ucontext;
	if (sig == SIGUSR1)
		character = character | 1;
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &character, 1);
		bit_count = 0;
		character = 0;
	}
	character = character << 1;
	sig_acknowledgment = kill(info->si_pid, SIGUSR1);
	if (sig_acknowledgment == -1)
		exit(ft_printf("Error signal acknowledgment back to client\n"));
}

int	main(void)
{
	struct sigaction	server;
	pid_t				pid;

	pid = getpid();
	ft_memset(&server, 0, sizeof(struct sigaction));
	server.sa_sigaction = &client_signal;
	server.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &server, NULL) == -1)
		exit(ft_printf("Error sigaction\n"));
	if (sigaction(SIGUSR2, &server, NULL) == -1)
		exit(ft_printf("Error sigaction\n"));
	ft_printf("Server PID: %d\n", pid);
	while (1)
		pause();
	return (0);
}
