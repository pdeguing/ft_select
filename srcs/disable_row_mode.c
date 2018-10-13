/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disable_row_mode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:58:25 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/13 09:37:54 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	disable_raw_mode(t_select *s)
{
	tcsetattr(STDERR_FILENO, TCSAFLUSH, s->original);
	ft_putstr_fd(s->tc->c_default, STDERR_FILENO);
}
