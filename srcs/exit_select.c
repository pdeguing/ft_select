/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 09:47:26 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/13 10:48:50 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	exit_select(t_select *s)
{
	int		i;

	ft_putstr_fd(s->tc->clear_down, STDERR_FILENO);
	disable_raw_mode(s);
	i = 0;
	while (i < s->lst_size)
	{
		remove_node(s->cursor);
		i++;
	}
	free(s->dlist);
	free(s->cursor);
	free(s->original);
	free(s->tc);
	free(s);
	exit(EXIT_SUCCESS);
}
