/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 11:02:43 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/10 06:15:22 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	select_loop(t_select *s)
{
	int		i;
	char	c;

	ft_putstr(s->tc->cursor_inv);
	while (1)
	{
		i = 0;
		ft_putchar('\r');
		ft_putstr(s->tc->clear_down);
		print_dlist(s);
		read(0, &c, 1);
		if (c == 'h')
		{
			s->cursor->is_cursor = false;
			s->cursor = s->cursor->prev;
			s->cursor->is_cursor = true;
		}
		if (c == 'l')
		{
			s->cursor->is_cursor = false;
			s->cursor = s->cursor->next;
			s->cursor->is_cursor = true;
		}
		if (c == 'c')
			ft_putstr(s->tc->clear_all);
		if (c == ENTER_KEY)
		{
			ft_putchar('\r');
			ft_putstr(s->tc->clear_down);
			return ;
		}
	}
}
