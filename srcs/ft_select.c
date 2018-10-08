/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:08:08 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/08 12:37:38 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(int ac, char **av)
{
	t_termios	original;

	if (ac < 2)
		return (display_usage());
	enable_raw_mode(&original);
	select_loop(av + 1);
	disable_raw_mode(&original);
	return (0);
}
