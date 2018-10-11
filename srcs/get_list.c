/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 02:50:34 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/11 15:19:10 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		push_node(t_dlist **head, char *name)
{
	t_dlist	*new;

	new = (t_dlist *)malloc(sizeof(t_dlist));
	if (new == NULL)
		perror("push_node");
	new->prev = NULL;
	new->name = ft_strdup(name);
	new->is_selected = false;
	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;

}

void	get_dlist(t_select *s, char **av, int n)
{
	t_dlist	*tail;
	int		len;

	len = 0;
	s->min_col = 0;
	s->min_row = n;
	*s->dlist = NULL;
	while (n > 0)
	{
		push_node(s->dlist, av[n]);
		len = ft_strlen((*s->dlist)->name);
		if (len > s->min_col)
			s->min_col = len;
		n--;
	}
	tail = *s->dlist;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = *s->dlist;
	(*s->dlist)->prev = tail;
}
