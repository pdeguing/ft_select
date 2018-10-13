/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 12:14:36 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/13 14:00:42 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	handle_winch(int sig)
{
	int		c;

	c = REFRESH_KEY;
	if (sig == SIGWINCH)
	{
		ioctl(0, TIOCSTI, &c);
	}
}

void	handle_cont(int sig)
{
	if (sig == SIGCONT)
	{
		enable_raw_mode();
	}
}
