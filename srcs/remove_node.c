/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 09:45:48 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/11 12:09:37 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	remove_node(t_dlist **cursor)
{
	t_dlist	*prev;
	t_dlist	*next;

	next = (*cursor)->next;
	prev = (*cursor)->prev;
	prev->next = next;
	next->prev = prev;
	ft_strdel(&(*cursor)->name);
	free(*cursor);
	*cursor = next;
}
