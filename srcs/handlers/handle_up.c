/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 18:47:01 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/13 17:13:38 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	handle_up(t_select *s)
{
	int		i;
	int		padding;

	i = 0;
	padding = 0;
	while (i < s->p_col)
	{
		if (*s->cursor == *s->dlist)
		{
			i -= s->lst_size % s->p_col;
			if (padding < s->lst_size % s->p_col)
				i += s->p_col;
		}
		else
			padding++;
		*s->cursor = (*s->cursor)->prev;
		i++;
	}
}
