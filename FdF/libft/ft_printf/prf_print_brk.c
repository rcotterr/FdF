/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_print_brk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:11:08 by mmcclure          #+#    #+#             */
/*   Updated: 2019/02/10 12:40:44 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				prf_print_b(t_format solved, va_list args)
{
	size_t	nbr;
	int		out;
	int		pr_size;

	if (solved.type == 'B')
		nbr = prf_get_unum(((solved.size > 4) ? solved.size : 4), args);
	else
		nbr = prf_get_unum(solved.size, args);
	pr_size = prf_nbrsize(nbr, 2);
	if (solved.hash && solved.precis <= pr_size && nbr != 0)
		pr_size++;
	pr_size = (solved.precis > pr_size) ? solved.precis : pr_size;
	if (!solved.hash)
		pr_size = (solved.precis == 0 && nbr == 0) ? 0 : pr_size;
	out = 0;
	if ((!solved.minus && solved.width-- > pr_size) &&
			(!solved.zero || solved.precis >= 0))
		out += prf_putnchar(' ', solved.width - pr_size);
	else if (!solved.minus && solved.width-- > pr_size)
		out += prf_putnchar('0', solved.width - pr_size);
	out += prf_putunbr(nbr, 2, pr_size, 0);
	if (solved.minus && solved.width > out)
		out += prf_putnchar(' ', solved.width - pr_size);
	return (out);
}

int				prf_print_r(t_format solved, va_list args)
{
	unsigned char	*c;
	int				out;
	unsigned char	pchar;

	(void)solved;
	c = (unsigned char*)va_arg(args, int*);
	out = 0;
	while (*c)
	{
		pchar = *c;
		if (pchar >= 127 && pchar <= 159)
		{
			out += write(1, "M-", 2);
			pchar -= 128;
		}
		if (pchar != '\n' && pchar != '\t' && pchar >= 0 && pchar <= 31)
		{
			out += write(1, "^", 1);
			pchar += 64;
		}
		out += write(1, &pchar, 1);
		c++;
	}
	return (out);
}

static char g_month[12][4] = {
	"Jan", "Feb", "Mar",
	"Apr", "May", "Jun",
	"Jul", "Aug", "Sep",
	"Oct", "Nov", "Dec"
};

static void		prf_r_dmy(int d, int year)
{
	int m;

	m = 0;
	while (1)
	{
		if (((m == 0 || m == 2 || m == 4 || m == 6 || m == 7
		|| m == 6 || m == 7 || m == 9 || m == 11)) && (d > 31 && (d -= 31)))
			m++;
		else
			break ;
		if (((m == 3 || m == 5 || m == 8 || m == 10)) && (d > 31 && (d -= 31)))
			m++;
		else
			break ;
		if ((m == 1) && ((d >= ((year % 4 == 0) ? 29 : 28))
				&& (d -= ((year % 4 == 0) ? 29 : 28))))
			m++;
		else
			break ;
	}
	(d < 10) ? ft_putnbr(0) : 0;
	ft_putnbr(d);
	ft_putstr(&g_month[m][0]);
	ft_putnbr(year);
}

int				prf_print_k(t_format solved, va_list args)
{
	size_t	sec;
	int		year;
	int		day;

	sec = va_arg(args, size_t);
	year = 1970;
	day = 1;
	solved.width = 1;
	solved.precis = 1;
	while ((sec >= ((year % 4 == 0) ? 31622400 : 31536000)) && year++)
		sec -= (year % 4 == 0) ? 31622400 : 31536000;
	while (sec >= 86400 && day++)
		sec -= 86400;
	while ((sec >= 3600) && solved.width++)
		sec -= 3600;
	while ((sec >= 60) && solved.precis++)
		sec -= 60;
	prf_r_dmy(day, year);
	write(1, "  ", 2);
	(solved.width < 11) ? ft_putnbr(0) : 0;
	ft_putnbr(solved.width - 1);
	write(1, ":", 1);
	(solved.precis < 11) ? ft_putnbr(0) : 0;
	ft_putnbr(solved.precis - 1);
	return (16);
}
