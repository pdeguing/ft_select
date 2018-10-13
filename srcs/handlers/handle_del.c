/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 09:33:05 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/13 09:56:29 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	handle_del(t_select *s)
{
	if ((*s->cursor)->next == *s->cursor)
		exit_select(s);
	if (*s->dlist == *s->cursor)
		*s->dlist = (*s->cursor)->next;
	remove_node(s->cursor);
	s->lst_size--;
}
