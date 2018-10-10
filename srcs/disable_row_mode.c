/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disable_row_mode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:58:25 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/10 12:14:09 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	disable_raw_mode(struct termios *origin)
{
	tcsetattr(STDERR_FILENO, TCSAFLUSH, origin);
}
