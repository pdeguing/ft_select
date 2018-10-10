/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:11:36 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/09 17:54:19 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <unistd.h>
# include <stdio.h>
# include <termios.h>
# include <termcap.h>
# include "../libft/includes/libft.h"

extern char PC;
extern char * UP;
extern char * BC;
extern short ospeed;

typedef struct termios	t_termios;

typedef struct s_termcaps	t_termcaps;

struct s_termcaps
{
	char	*move_right;
	char	*move_left;
	char	*clear_all;
	char	*standout_on;
	char	*standout_off;
	char	*cursor_inv;
};

void	init_term(t_termios *original, t_termcaps *tc);
void	enable_raw_mode(t_termios *original);
void	disable_raw_mode(t_termios *original);

void	select_loop(char **av, t_termcaps *tc);

int		display_usage(void);

#endif
