/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 11:02:43 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/09 17:54:18 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	select_loop(char **av, t_termcaps *tc)
{
	int		i;
	char	c;
	int		cursor;

	ft_putstr(tc->cursor_inv);
	cursor = 0;
	while (1)
	{
		i = 0;
		ft_putstr(tc->clear_all);
		while (av[i] != NULL)
		{
			if (cursor == i)
				ft_putstr(tc->standout_on);
			ft_putstr(av[i]);
			ft_putstr(tc->standout_off);
			if (av[i + 1] != NULL)
				ft_putchar(' ');
			i++;
		}
		read(0, &c, 1);
		if (c == 'h')
		{
			ft_putstr(tc->move_left);
			cursor--;
		}
		if (c == 'l')
		{
			ft_putstr(tc->move_right);
			cursor++;
		}
		if (c == 'c')
			ft_putstr(tc->clear_all);
		if (c == 'q')
			return ;
	}
}
