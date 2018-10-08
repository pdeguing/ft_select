/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 11:02:43 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/08 12:29:24 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	select_loop(char **av)
{
	int		i;
	char	c;

	while (1)
	{
		ft_printf("\x1b[2J"); 
		i = 0;
		while (av[i] != NULL)
		{
			ft_printf("%s%c", av[i], ' ');
			i++;
		}
		read(0, &c, 1);
		if (c == 'h')
			ft_printf("\x1b[%d;%dH", 20, 20); 
		if (c == 'q')
			return ;
	}
}
