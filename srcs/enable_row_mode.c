/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_row_mode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:57:48 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/10 12:12:54 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	enable_raw_mode(struct termios *origin)
{
	struct termios	raw;

	tcgetattr(STDERR_FILENO, origin);
	raw = *origin;
	raw.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(STDERR_FILENO, TCSAFLUSH, &raw);
}
