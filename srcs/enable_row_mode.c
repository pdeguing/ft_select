/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_row_mode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:57:48 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/13 10:41:54 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	enable_raw_mode(t_select *s)
{
	t_termios	raw;

	tcgetattr(STDERR_FILENO, s->original);
	raw = *s->original;
	raw.c_lflag &= ~(ECHO | ICANON);
	raw.c_cc[VMIN] = 0;
	raw.c_cc[VTIME] = 1;
	tcsetattr(STDERR_FILENO, TCSAFLUSH, &raw);
	ft_putstr_fd(s->tc->c_hide, STDERR_FILENO);
}
