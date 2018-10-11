/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 02:50:34 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/11 12:01:52 by pdeguing         ###   ########.fr       */
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

void	get_dlist(t_dlist **head, char **av, int n)
{
	t_dlist	*tail;

	*head = NULL;
	while (n > 0)
	{
		push_node(head, av[n]);
		n--;
	}
	tail = *head;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = *head;
	(*head)->prev = tail;
}
