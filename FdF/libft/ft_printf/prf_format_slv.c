/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_format_slv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:06:06 by mmcclure          #+#    #+#             */
/*   Updated: 2019/02/10 16:35:36 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		prf_size(char **ch, char old)
{
	if (**ch == 'j' && (*ch += 1))
		return ((old > 10) ? old : 10);
	else if (**ch == 'z' && (*ch += 1))
		return ((old > 9) ? old : 9);
	else if (**ch == 'l' && (*ch += 1))
	{
		if (**ch == 'l' && (*ch += 1))
			return ((old > 8) ? old : 8);
		else
			return ((old > 4) ? old : 4);
	}
	else if (**ch == 'h' && (*ch += 1))
	{
		if (**ch == 'h' && (*ch += 1))
			return ((old > 1) ? old : 1);
		else
			return ((old > 2) ? old : 2);
	}
	else if (**ch == 'L' && (*ch += 1))
		return (11);
	return (0);
}

static char		prf_type(char **format)
{
	char ch;

	ch = **format;
	if (ch == 'd' || ch == 'D' || ch == 'i' || ch == 'u' || ch == 'U' ||
	ch == 'o' || ch == 'O' || ch == 'x' || ch == 'X' ||
	ch == 's' || ch == 'S' || ch == 'c' || ch == 'C' ||
	ch == 'p' || ch == '%' || ch == 'f' || ch == 'F' ||
	ch == 'r' || ch == 'b' || ch == 'B' || ch == 'n' || ch == 'k')
	{
		*format += 1;
		return (ch);
	}
	else
		return (0);
}

static int		prf_flags(t_format *solve, char flag)
{
	if (flag == '0')
		solve->zero = 1;
	else if (flag == '#')
		solve->hash = 1;
	else if (flag == '-')
		solve->minus = 1;
	else if (flag == '+')
		solve->plus = 1;
	else if (flag == ' ')
		solve->space = 1;
	else
		return (0);
	return (1);
}

static int		prf_num(char **format, va_list args)
{
	int out;

	out = 0;
	if (**format == '*' && (*format += 1))
		out = va_arg(args, int);
	else if (ft_isdigit(**format))
	{
		out = ft_atoi(*format);
		while (ft_isdigit(**format))
			*format += 1;
	}
	return (out);
}

t_format		prf_format_slv(char **format, va_list args)
{
	t_format	solve;
	char		tmp;

	solve.minus = 0;
	solve.plus = 0;
	solve.space = 0;
	solve.hash = 0;
	solve.zero = 0;
	solve.width = 0;
	solve.precis = -1;
	solve.size = 0;
	while (**format && !(solve.type = prf_type(format)))
		if (**format == '.' && (*format += 1))
			solve.precis = prf_num(format, args);
		else if (prf_flags(&solve, **format))
			*format += 1;
		else if ((**format == '*') || ft_isdigit(**format))
			solve.width = prf_num(format, args);
		else if ((tmp = prf_size(format, solve.size)))
			solve.size = tmp;
		else
			break ;
	return (solve);
}
