/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 11:02:43 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/13 19:21:22 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static bool		check_winsize(t_select *s, int w_col, int w_row)
{
	if (s->max_len + 2 > w_col)
		return (false);
	s->p_col = w_col / (s->max_len + 2);
	if (s->p_col > s->lst_size)
		s->p_col = s->lst_size;
	if ((s->lst_size / s->p_col) > w_row)
		return (false);
	return (true);
}

void			select_loop(t_select *s)
{
	t_winsize	w;
	int			i;

	while (1)
	{
		i = 0;
		ft_putstr_fd(s->tc->clear_down, 2);
		w = get_winsize();
		ft_putstr_fd(s->tc->c_save, 2);
		if (check_winsize(s, w.ws_col, w.ws_row))
			display_dlist(s);
		else
		{
			ft_putstr_fd(s->tc->clear_all, 2);
			ft_putstr_fd("Window is too small.", 2);
		}
		ft_putstr_fd(s->tc->c_restore, 2);
		ft_putstr_fd(s->tc->c_return, 2);
		handle_key(s);
	}
}
