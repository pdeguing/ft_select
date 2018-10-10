/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 14:56:33 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/10 12:16:43 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		init_term(t_tcaps **tc)
{
	t_tcaps	*new;
	char	*tname;
	char	buf[1024];

	new = (t_tcaps *)malloc(sizeof(t_tcaps));
	*tc = new;
	if (new == NULL)
		perror("init_term");
	tname = getenv("TERM");
	if (tname == NULL)
		perror("tname invalid");
	tgetent(buf, tname);
	new->clear_down = tgetstr("cd", NULL);
	new->clear_all = tgetstr("cl", NULL);
	new->standout = tgetstr("so", NULL);
	new->underlined = tgetstr("us", NULL);
	new->reverse = tgetstr("mr", NULL);
	new->cursor_inv = tgetstr("vi", NULL);
	new->cursor_dft = tgetstr("ve", NULL);
	new->reset = tgetstr("me", NULL);
}

t_select	*init_select(char **av, int n)
{
	t_select	*s;

	s = (t_select *)malloc(sizeof(t_select));
	if (s == NULL)
		perror("init_select");
	s->original = (t_termios *)malloc(sizeof(t_termios));
	if (s->original == NULL)
		perror("init_select");
	s->dlist = (t_dlist **)malloc(sizeof(t_dlist *));
	if (s->dlist == NULL)
		perror("init_select");
	init_term(&s->tc);
	get_dlist(s->dlist, av, n);
	s->cursor = *s->dlist;
	return (s);
}
