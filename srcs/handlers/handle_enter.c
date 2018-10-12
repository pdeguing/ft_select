/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_enter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 17:50:33 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/11 17:52:34 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	handle_enter(t_select *s)
{
	ft_putchar_fd('\r', STDERR_FILENO);
	ft_putstr_fd(s->tc->clear_down, STDERR_FILENO);
	exit(EXIT_SUCCESS);
}
