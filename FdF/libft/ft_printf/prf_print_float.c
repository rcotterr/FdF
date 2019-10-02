/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_print_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:09:40 by mmcclure          #+#    #+#             */
/*   Updated: 2019/02/08 13:32:07 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <math.h>

static int		prf_print_digit(long double nbr, t_format solved)
{
	int out;

	out = 0;
	if (nbr == INFINITY)
	{
		if (solved.plus)
			out = write(1, "+", 1);
		else if (solved.space)
			out = write(1, " ", 1);
		else
			out = 0;
	}
	else if (nbr == -INFINITY)
		out = write(1, "-", 1);
	else if (nbr != nbr)
		out = 0;
	else if (nbr >= 0 && solved.plus)
		out = write(1, "+", 1);
	else if (nbr >= 0 && solved.space)
		out = write(1, " ", 1);
	else if (nbr < 0)
		out = write(1, "-", 1);
	return (out);
}

static int		prf_putfloat(long double nbr, int precis, char hash)
{
	long double dec;
	int			out;

	if (precis < 0)
		precis = 6;
	dec = nbr - (size_t)nbr;
	if (precis == 0)
	{
		out = (dec > 0.5) ? prf_putunbr((size_t)nbr + 1, 10, -1, 0) :
					prf_putunbr((size_t)nbr, 10, -1, 0);
		out += (hash) ? write(1, ".", 1) : 0;
		return (out);
	}
	out = prf_putunbr((size_t)nbr, 10, -1, 0);
	out += write(1, ".", 1);
	while (precis--)
	{
		dec *= 10;
		if ((size_t)dec == 0 && precis)
			out += prf_putunbr(0, 10, -1, 0);
	}
	nbr = dec - (size_t)dec;
	out += (nbr > 0.5) ? prf_putunbr((size_t)dec + 1, 10, -1, 0)
					: prf_putunbr((size_t)dec, 10, -1, 0);
	return (out);
}

static int		prf_naninf(long double nbr, t_format *solved)
{
	if (nbr == INFINITY)
	{
		solved->zero = 0;
		if (solved->space || solved->plus)
			return (4);
		else
			return (3);
	}
	else if (nbr == -INFINITY)
	{
		solved->zero = 0;
		return (4);
	}
	else if (nbr != nbr)
	{
		solved->zero = 0;
		return (3);
	}
	return (0);
}

static int		prf_pr_naninf(long double nbr, char type)
{
	if (nbr == INFINITY)
	{
		if (type == 'F')
			return (write(1, "INF", 3));
		else
			return (write(1, "inf", 3));
	}
	else if (nbr != nbr)
	{
		if (type == 'F')
			return (write(1, "NAN", 3));
		else
			return (write(1, "nan", 3));
	}
	return (0);
}

int				prf_print_f(t_format solved, va_list arg)
{
	long double	nbr;
	int			out;
	int			pr_size;

	out = 0;
	nbr = (solved.size == 11) ? va_arg(arg, long double) : va_arg(arg, double);
	pr_size = (nbr < 0 || (nbr >= 0 && (solved.plus || solved.space))) ? 1 : 0;
	pr_size += (nbr < 0) ? prf_nbrsize(-nbr, 10) : prf_nbrsize(nbr, 10);
	pr_size += (solved.hash && !solved.precis) ? 1 : 0;
	if (solved.precis != 0)
		pr_size += (solved.precis > 0) ? (solved.precis + 1) : 7;
	pr_size = (prf_naninf(nbr, &solved)) ? prf_naninf(nbr, &solved) : pr_size;
	if (!solved.minus && solved.width > pr_size && (!solved.zero))
		out += prf_putnchar(' ', solved.width - pr_size);
	out += prf_print_digit(nbr, solved);
	nbr = (nbr >= 0) ? nbr : -nbr;
	if (!solved.minus && solved.width > pr_size && solved.zero)
		out += prf_putnchar('0', solved.width - pr_size);
	out += (prf_naninf(nbr, &solved)) ? prf_pr_naninf(nbr, solved.type) :
			prf_putfloat(nbr, solved.precis, solved.hash);
	if (solved.minus && solved.width > out)
		out += prf_putnchar(' ', solved.width - pr_size);
	return (out);
}
