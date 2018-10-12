/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:43:39 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/12 09:52:41 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		get_special_key(void)
{
	int		c;

	read(0, &c, 1);
	if (c != '[')
		return (ESC_KEY);
	read(0, &c, 1);
	if (c == 'A')
		return (UP_KEY);
	if (c == 'B')
		return (DOWN_KEY);
	if (c == 'C')
		return (RIGHT_KEY);
	if (c == 'D')
		return (LEFT_KEY);
	if (c == '3')
	{
		read(0, &c, 1);
		if (c == '~')
			return (DEL_KEY);
	}
	return (ESC_KEY);
}

int		get_key(void)
{
	int		c;

	read(0, &c, 1);
	if (c == ESC_KEY)
		return (get_special_key());
	else
		return (c);
}
