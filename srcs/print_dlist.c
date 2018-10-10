/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 03:54:55 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/10 05:05:02 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_dlist(t_select *s)
{
	t_dlist		*head;
	t_dlist		*current;

	head = *s->dlist;
	current = head;
	while (1)
	{
		if (current->is_cursor)
			ft_putstr(s->tc->standout_on);
		ft_putstr(current->name);
		ft_putstr(s->tc->standout_off);
		current = current->next;
		if (current == head)
			break ;
		ft_putchar(' ');
	}
}
