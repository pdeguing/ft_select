/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 19:03:17 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/13 17:13:36 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	handle_down(t_select *s)
{
	int		i;
	int		padding;

	i = 0;
	padding = 0;
	while (i < s->p_col)
	{
		*s->cursor = (*s->cursor)->next;
		if (*s->cursor == *s->dlist)
		{
			if (padding >= 0)
				i -= s->lst_size % s->p_col;
			if (padding < s->lst_size % s->p_col)
				i += s->p_col;
		}
		else
			padding++;
		i++;
	}
}
