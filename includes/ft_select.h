/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:11:36 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/11 19:06:24 by pdeguing         ###   ########.fr       */
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
# define UP_KEY			107
# define DOWN_KEY		106
# define LEFT_KEY		104
# define RIGHT_KEY		108
# define TOTAL_KEYS		6

/*
** TYPEDEF
*/

typedef struct s_select		t_select;
typedef struct s_tcaps		t_tcaps;
typedef struct s_dlist		t_dlist;
typedef struct termios		t_termios;
typedef struct winsize		t_winsize;
typedef struct s_dispatch	t_dispatch;

/*
** GLOBAL STRUCTURE
*/

struct s_select
{
	t_tcaps		*tc;
	t_termios	*original;
	t_dlist		**dlist;
	int			lst_size;
	int			max_len;
	int			p_col;
	t_dlist		**cursor;
	t_dispatch	*key_handlers;
};

/*
** KEY HANDLERS
*/

struct s_dispatch
{
	int			key;
	void		(*f)(t_select *);
};

void			handle_enter(t_select *s);
void			handle_space(t_select *s);
void			handle_up(t_select *s);
void			handle_down(t_select *s);
void			handle_left(t_select *s);
void			handle_right(t_select *s);

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

int					get_key(void);
void				handle_key(t_select *s);

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
