/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:08:08 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/13 19:47:49 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		init_signals(void)
{
	signal(SIGINT, &handle_int);
	signal(SIGWINCH, &handle_winch);
	signal(SIGTSTP, &handle_tstp);
	signal(SIGCONT, &handle_cont);
}

int				main(int ac, char **av)
{
	t_select	*s;

	init_signals();
	if (ac < 2)
		return (display_usage());
	s = init_select(av, ac - 1);
	enable_raw_mode();
	select_loop(s);
	exit_select(s);
	return (0);
}
