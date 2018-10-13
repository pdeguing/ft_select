/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_enter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 17:50:33 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/13 09:55:56 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	handle_enter(t_select *s)
{
	ft_putstr_fd(s->tc->clear_down, STDERR_FILENO);
	print_dlist(s);
	exit_select(s);
}
