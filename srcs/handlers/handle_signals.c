/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 12:14:36 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/13 20:01:40 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	handle_int(int sig)
{
	if (sig == SIGINT)
	{
		disable_raw_mode();
		ft_putstr_fd(tgetstr("cl", NULL), 2);
		exit(EXIT_SUCCESS);
	}
}

void	handle_winch(int sig)
{
	int		c;

	c = REFRESH_KEY;
	if (sig == SIGWINCH)
	{
		ft_putstr_fd(tgetstr("cl", NULL), 2);
		ioctl(0, TIOCSTI, &c);
	}
}

void	handle_tstp(int sig)
{
	if (sig == SIGTSTP)
	{
		ft_putstr_fd(tgetstr("cl", NULL), 2);
		disable_raw_mode();
		signal(SIGTSTP, SIG_DFL);
		ioctl(0, TIOCSTI, "\x1A");
	}
}

void	handle_cont(int sig)
{
	int		c;

	c = REFRESH_KEY;
	if (sig == SIGCONT)
	{
		ft_putstr_fd(tgetstr("cl", NULL), 2);
		enable_raw_mode();
		ioctl(0, TIOCSTI, &c);
	}
}
