/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 09:33:05 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/12 09:38:27 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	handle_del(t_select *s)
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
	s->lst_size--;
}
