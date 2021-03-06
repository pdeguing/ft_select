/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 03:54:55 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/11 13:09:19 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_dlist(t_select *s)
{
	t_dlist	*head;
	t_dlist	*current;
	bool	put_space;

	head = *s->dlist;
	current = head;
	put_space = false;
	while (1)
	{
		if (current->is_selected)
		{
			if (put_space)
				ft_putchar(' ');
			else
				put_space = true;
			ft_putstr(current->name);
		}
		if (current->next == head)
			break ;
		current = current->next;
	}
}
