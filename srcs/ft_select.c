/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:08:08 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/09 16:48:02 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(int ac, char **av)
{
	t_termios	original;
	t_termcaps	tc;

	if (ac < 2)
		return (display_usage());
	init_term(&original, &tc);
	select_loop(av + 1, &tc);
	disable_raw_mode(&original);
	return (0);
}
