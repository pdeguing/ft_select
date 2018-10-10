/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 14:56:33 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/09 17:54:20 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	init_term(t_termios *original, t_termcaps *tc)
{
	char	*tname;
	char	buf[1024];

	tname = getenv("TERM");
	if (tname == NULL)
		perror("tname invalid");
	tgetent(buf, tname);
	tc->move_right = tgetstr("nd", NULL);
	tc->move_left = tgetstr("le", NULL);
	tc->clear_all = tgetstr("cl", NULL);
	tc->standout_on = tgetstr("so", NULL);
	tc->standout_off = tgetstr("se", NULL);
	tc->cursor_inv = tgetstr("vi", NULL);
	enable_raw_mode(original);
}
