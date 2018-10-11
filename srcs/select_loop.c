/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 11:02:43 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/11 12:09:38 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	select_loop(t_select *s)
{
	int		i;
	char	c;

	while (1)
	{
		i = 0;
		ft_putchar_fd('\r', STDERR_FILENO);
		ft_putstr_fd(s->tc->clear_down, STDERR_FILENO);
		print_dlist(s, STDERR_FILENO, false);
		read(0, &c, 1);
		if (c == 'h')
		{
			(*s->cursor) = (*s->cursor)->prev;
		}
		if (c == 'l')
		{
			(*s->cursor) = (*s->cursor)->next;
		}
		if (c == 'c')
			ft_putstr_fd(s->tc->clear_all, STDERR_FILENO);
		if (c == ENTER_KEY)
		{
			ft_putchar_fd('\r', STDERR_FILENO);
			ft_putstr_fd(s->tc->clear_down, STDERR_FILENO);
			return ;
		}
		if (c == ESC_KEY)
		{
			ft_putchar_fd('\r', STDERR_FILENO);
			ft_putstr_fd(s->tc->clear_down, STDERR_FILENO);
			exit(EXIT_SUCCESS) ;
		}
		if (c == SPACE_KEY)
			(*s->cursor)->is_selected = !(*s->cursor)->is_selected;
		if (c == 100)
		{
			if ((*s->cursor)->next == *s->cursor)
			{
				ft_putchar_fd('\r', STDERR_FILENO);
				ft_putstr_fd(s->tc->clear_down, STDERR_FILENO);
				return ;
			}
			if (*s->dlist == *s->cursor)
				*s->dlist = (*s->cursor)->next;
			remove_node(s->cursor);
		}
	}
}
