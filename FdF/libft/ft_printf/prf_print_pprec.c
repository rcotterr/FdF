/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_print_pprec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:10:28 by mmcclure          #+#    #+#             */
/*   Updated: 2019/02/08 14:12:32 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int					prf_print_per(t_format solved, va_list args)
{
	int		out;
	int		print_size;
	void	*tmp;

	tmp = args;
	print_size = 1;
	out = 0;
	if ((!solved.minus && solved.width > print_size) && !solved.zero)
		out += prf_putnchar(' ', solved.width - print_size);
	else if (!solved.minus && solved.width > print_size)
		out += prf_putnchar('0', solved.width - print_size);
	out += write(1, "%%", 1);
	if (solved.minus && solved.width > out)
		out += prf_putnchar(' ', solved.width - out);
	return (out);
}

int					prf_print_p(t_format solved, va_list args)
{
	int		out;
	size_t	nbr;
	int		print_size;

	nbr = (size_t)va_arg(args, void*);
	print_size = prf_nbrsize(nbr, 16);
	print_size = (solved.precis == 0 && nbr == 0) ? 0 : print_size;
	print_size = (solved.precis > print_size) ? solved.precis : print_size;
	print_size += 2;
	out = 0;
	if (!solved.minus && solved.width > print_size &&
				(!solved.zero || solved.precis >= 0))
		out += prf_putnchar(' ', solved.width - print_size);
	out += write(1, "0x", 2);
	if (!solved.minus && solved.width > print_size &&
				solved.zero && solved.precis < 0)
		out += prf_putnchar('0', solved.width - print_size);
	out += prf_putunbr(nbr, 16, solved.precis, 0);
	if (solved.minus && solved.width > out)
		out += prf_putnchar(' ', solved.width - print_size);
	return (out);
}
