/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:11:36 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/11 15:34:57 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <unistd.h>
# include <stdio.h>
# include <termios.h>
# include <termcap.h>
# include <stdbool.h>
# include <sys/ioctl.h>
# include "../libft/includes/libft.h"

# define BACKSPACE_KEY	8
# define ENTER_KEY		10
# define ESC_KEY		27
# define SPACE_KEY		32

/*
** TYPEDEF
*/

typedef struct s_select	t_select;
typedef struct s_tcaps	t_tcaps;
typedef struct s_dlist	t_dlist;
typedef struct termios	t_termios;
typedef struct winsize	t_winsize;

/*
** GLOBAL STRUCTURE
*/

struct s_select
{
	t_tcaps		*tc;
	t_termios	*original;
	t_dlist		**dlist;
	t_dlist		**cursor;
	int			min_col;
	int			min_row;
};

/*
** TERMINAL CAPABILITIES
*/

extern char		PC;
extern char		*UP;
extern char		*BC;
extern short	ospeed;

struct s_tcaps
{
	char	*clear_down;
	char	*clear_all;
	char	*standout;
	char	*underlined;
	char	*reverse;
	char	*c_save;
	char	*c_restore;
	char	*c_hide;
	char	*c_default;
	char	*reset;
};

/*
** ARGUMENTS LIST 
*/

struct s_dlist
{
	t_dlist			*prev;
	char			*name;
	bool			is_selected;
	t_dlist			*next;
};

t_winsize			get_winsize(void);

void				remove_node(t_dlist **pcursor);
void				get_dlist(t_select *s, char **av, int n);
void				display_dlist(t_select *s, int w_col, int w_row);
void				print_dlist(t_select *s);

void				enable_raw_mode(t_termios *original);
void				disable_raw_mode(t_termios *original);

t_select			*init_select(char **av, int n);

void				select_loop(t_select *s);

int					display_usage(void);

#endif
