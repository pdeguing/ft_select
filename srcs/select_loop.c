/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 11:02:43 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/12 13:08:41 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	select_loop(t_select *s)
{
	t_winsize	w;
	int			i;

	while (1)
	{
		i = 0;
		w = get_winsize();
		ft_putstr_fd(s->tc->c_save, 2);
		ft_putstr_fd(s->tc->clear_down, STDERR_FILENO);
		display_dlist(s, w.ws_col, w.ws_row);
		ft_putstr_fd(s->tc->c_restore, 2);
		handle_key(s);
	}
}






/*
		if (c == 'c')
			ft_putstr_fd(s->tc->clear_all, STDERR_FILENO);
		if (c == ESC_KEY)
		{
			ft_putchar_fd('\r', STDERR_FILENO);
			ft_putstr_fd(s->tc->clear_down, STDERR_FILENO);
			exit(EXIT_SUCCESS) ;
		}
		if (c == 100)
		{
		}
		*/
