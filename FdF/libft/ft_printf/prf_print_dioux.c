/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_print_dioux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:20:32 by mmcclure          #+#    #+#             */
/*   Updated: 2019/02/08 14:32:54 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		prf_print_digit(long long int nbr, t_format solved)
{
	int out;

	out = 0;
	if (nbr >= 0 && solved.plus)
		out = write(1, "+", 1);
	else if (nbr >= 0 && solved.space)
		out = write(1, " ", 1);
	else if (nbr < 0 && (nbr *= -1))
		out = write(1, "-", 1);
	return (out);
}

int				prf_print_di(t_format solved, va_list args)
{
	long long	nbr;
	int			out;
	int			pr_size;

	out = 0;
	if (solved.type == 'D')
		nbr = prf_get_num(((solved.size > 4) ? solved.size : 4), args);
	else
		nbr = prf_get_num(solved.size, args);
	pr_size = (nbr < 0) ? prf_nbrsize(-nbr, 10) : prf_nbrsize(nbr, 10);
	pr_size = (solved.precis > pr_size) ? solved.precis : pr_size;
	pr_size = (solved.precis == 0 && nbr == 0) ? 0 : pr_size;
	pr_size += (nbr < 0 || (nbr >= 0 && (solved.plus || solved.space))) ? 1 : 0;
	if (!solved.minus && solved.width > pr_size &&
				(!solved.zero || solved.precis >= 0))
		out += prf_putnchar(' ', solved.width - pr_size);
	out += prf_print_digit(nbr, solved);
	nbr = (nbr >= 0) ? nbr : -nbr;
	if (!solved.minus && solved.width > pr_size &&
				solved.zero && solved.precis < 0)
		out += prf_putnchar('0', solved.width - pr_size);
	out += prf_putunbr(nbr, 10, solved.precis, 0);
	if (solved.minus && solved.width > out)
		out += prf_putnchar(' ', solved.width - pr_size);
	return (out);
}

int				prf_print_u(t_format solved, va_list args)
{
	size_t	nbr;
	int		out;
	int		pr_size;

	if (solved.type == 'U')
		nbr = prf_get_unum(((solved.size > 4) ? solved.size : 4), args);
	else
		nbr = prf_get_unum(solved.size, args);
	out = 0;
	pr_size = prf_nbrsize(nbr, 10);
	pr_size = (solved.precis > pr_size) ? solved.precis : pr_size;
	pr_size = (solved.precis == 0 && nbr == 0) ? 0 : pr_size;
	if (!solved.minus && solved.width > pr_size &&
			(!solved.zero || solved.precis >= 0))
		out += prf_putnchar(' ', solved.width - pr_size);
	else if (!solved.minus && solved.width > pr_size)
		out += prf_putnchar('0', solved.width - pr_size);
	out += prf_putunbr(nbr, 10, solved.precis, 0);
	if (solved.minus && solved.width > out)
		out += prf_putnchar(' ', solved.width - pr_size);
	return (out);
}

int				prf_print_o(t_format solved, va_list args)
{
	size_t	nbr;
	int		out;
	int		pr_size;

	if (solved.type == 'O')
		nbr = prf_get_unum(((solved.size > 4) ? solved.size : 4), args);
	else
		nbr = prf_get_unum(solved.size, args);
	pr_size = prf_nbrsize(nbr, 8);
	if (solved.hash && solved.precis <= pr_size && nbr != 0)
		pr_size++;
	pr_size = (solved.precis > pr_size) ? solved.precis : pr_size;
	if (!solved.hash)
		pr_size = (solved.precis == 0 && nbr == 0) ? 0 : pr_size;
	out = 0;
	if ((!solved.minus && solved.width > pr_size) &&
				(!solved.zero || solved.precis >= 0))
		out += prf_putnchar(' ', solved.width - pr_size);
	else if (!solved.minus && solved.width > pr_size)
		out += prf_putnchar('0', solved.width - pr_size);
	out += prf_putunbr(nbr, 8, pr_size, 0);
	if (solved.minus && solved.width > out)
		out += prf_putnchar(' ', solved.width - pr_size);
	return (out);
}

int				prf_print_x(t_format solved, va_list args)
{
	size_t	nbr;
	int		out;
	int		pr_size;

	nbr = prf_get_unum(solved.size, args);
	pr_size = prf_nbrsize(nbr, 16);
	pr_size = (solved.precis > pr_size) ? solved.precis : pr_size;
	pr_size = (solved.hash && nbr != 0) ? (pr_size + 2) : pr_size;
	pr_size = (solved.precis == 0 && nbr == 0) ? 0 : pr_size;
	out = 0;
	if (!solved.minus && solved.width > pr_size &&
				(!solved.zero || solved.precis >= 0))
		out += prf_putnchar(' ', solved.width - pr_size);
	if (solved.hash && nbr != 0)
		out += (solved.type == 'X') ? write(1, "0X", 2) : write(1, "0x", 2);
	if (!solved.minus && solved.width > pr_size &&
				solved.zero && solved.precis < 0)
		out += prf_putnchar('0', solved.width - pr_size);
	if (solved.type == 'X')
		out += prf_putunbr(nbr, 16, solved.precis, 1);
	else
		out += prf_putunbr(nbr, 16, solved.precis, 0);
	if (solved.minus && solved.width > out)
		out += prf_putnchar(' ', solved.width - pr_size);
	return (out);
}
