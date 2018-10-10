/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 03:54:55 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/10 12:43:58 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_dlist(t_select *s, int fd, bool only_selected)
{
	t_dlist		*head;
	t_dlist		*current;

	head = *s->dlist;
	current = head;
	while (1)
	{
		if(!only_selected)
		{
			if (current->is_cursor)
				ft_putstr_fd(s->tc->underlined, fd);
			if (current->is_selected)
				ft_putstr_fd(s->tc->reverse, fd);
			ft_putstr_fd(current->name, fd);
			ft_putstr_fd(s->tc->reset, fd);
		}
		else if (current->is_selected)
			ft_putstr_fd(current->name, fd);
		current = current->next;
		if (current == head)
			break ;
		if (!only_selected || current->is_selected)
				ft_putchar_fd(' ', fd);
	}
}
