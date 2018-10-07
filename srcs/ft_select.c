/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeguing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:08:08 by pdeguing          #+#    #+#             */
/*   Updated: 2018/10/06 18:03:20 by pdeguing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		enable_raw_mode(struct termios *origin)
{
	struct termios	raw;

	tcgetattr(STDIN_FILENO, origin);
	raw = *origin;
	raw.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

static void		disable_raw_mode(struct termios *origin)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, origin);
}

static void		main_loop(char **av)
{
	int		i;
	char	c;

	while (1)
	{
		ft_printf(">>> ");
		i = 0;
		while (av[i] != NULL)
		{
			ft_printf("%s%c", av[i], (av[i + 1] != NULL) ? ' ' : '\n');
			i++;
		}
		read(0, &c, 1);
		if (c == 'q')
			return ;
	}
}

int		main(int ac, char **av)
{
	struct termios	origin;

	enable_raw_mode(&origin);
	if (ac < 1)
		return (display_usage());
	main_loop(av + 1);
	disable_raw_mode(&origin);
	return (0);
}
