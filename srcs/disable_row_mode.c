/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disable_row_mode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:58:25 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/13 14:10:32 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	disable_raw_mode(void)
{
	t_termios	raw;

	tcgetattr(STDERR_FILENO, &raw);
	raw.c_lflag |= (ECHO | ICANON);
	tcsetattr(STDERR_FILENO, TCSAFLUSH, &raw);
	ft_putstr_fd(tgetstr("ve", NULL), STDERR_FILENO);
}
