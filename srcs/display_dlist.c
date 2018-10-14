/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_dlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 12:57:38 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/13 19:21:45 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		display_name(t_select *s, t_dlist *current, int fd)
{
	int		len;

	len = ft_strlen(current->name);
	if (current == *s->cursor)
		ft_putstr_fd(s->tc->underlined, fd);
	if (current->is_selected)
		ft_putstr_fd(s->tc->reverse, fd);
	ft_putstr_fd(current->name, fd);
	while (len <= s->max_len)
	{
		ft_putstr_fd(" ", fd);
		len++;
	}
	ft_putstr_fd(s->tc->reset, fd);
}

void			display_dlist(t_select *s)
{
	t_dlist		*head;
	t_dlist		*current;
	int			i;

	head = *s->dlist;
	current = head;
	while (1)
	{
		i = 0;
		while (i < s->p_col)
		{
			display_name(s, current, STDERR_FILENO);
			if (current->next == head)
				return ;
			current = current->next;
			ft_putchar_fd(' ', STDERR_FILENO);
			i++;
		}
		ft_putstr_fd("\n", STDERR_FILENO);
	}
}
