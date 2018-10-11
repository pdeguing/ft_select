/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:08:08 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/11 15:37:50 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(int ac, char **av)
{
	t_select	*s;

	if (ac < 2)
		return (display_usage());
	s = init_select(av, ac -1);
	enable_raw_mode(s->original);
	ft_putstr_fd(s->tc->c_hide, STDERR_FILENO);
	select_loop(s);
	ft_putstr_fd(s->tc->c_default, STDERR_FILENO);
	disable_raw_mode(s->original);
	print_dlist(s);
	return (0);
}
