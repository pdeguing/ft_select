/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:11:36 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/10 06:11:30 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <unistd.h>
# include <stdio.h>
# include <termios.h>
# include <termcap.h>
# include <stdbool.h>
# include "../libft/includes/libft.h"

# define ENTER_KEY 10

/*
** TYPEDEF
*/

typedef struct s_select	t_select;
typedef struct s_tcaps	t_tcaps;
typedef struct s_dlist	t_dlist;
typedef struct termios	t_termios;

/*
** GLOBAL STRUCTURE
*/

struct s_select
{
	t_tcaps		*tc;
	t_termios	*original;
	t_dlist		**dlist;
	t_dlist		*cursor;
};

/*
** TERMINAL CAPABILITIES
*/

extern char PC;
extern char * UP;
extern char * BC;
extern short ospeed;

struct s_tcaps
{
	char	*move_right;
	char	*move_left;
	char	*clear_down;
	char	*clear_all;
	char	*standout_on;
	char	*standout_off;
	char	*cursor_inv;
};

/*
** ARGUMENTS LIST 
*/

struct s_dlist
{
	t_dlist			*prev;
	char			*name;
	bool			is_cursor;
	bool			is_selected;
	t_dlist			*next;
};

void				get_dlist(t_dlist **dlist, char **av, int n);
void				print_dlist(t_select *s);

void				enable_raw_mode(t_termios *original);
void				disable_raw_mode(t_termios *original);

t_select			*init_select(char **av, int n);

void				select_loop(t_select *s);

int					display_usage(void);

#endif
