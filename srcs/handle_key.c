/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:50:29 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/11 18:46:41 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	handle_key(t_select *s)
{
	int		key;
	int		i;

	key = get_key();
	i = 0;
	while (i < TOTAL_KEYS)
	{
		if (s->key_handlers[i].key == key)
			return (s->key_handlers[i].f(s));
		i++;
	}
}
