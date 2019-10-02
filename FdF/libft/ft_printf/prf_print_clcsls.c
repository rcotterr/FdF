/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_print_clcsls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:06:40 by mmcclure          #+#    #+#             */
/*   Updated: 2019/02/10 12:53:00 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		prf_wcsize(wchar_t wc)
{
	int print_size;

	print_size = 0;
	if (wc <= 0x0000007F)
		print_size = 1;
	else if (wc <= 0x000007FF)
		print_size = 2;
	else if (wc <= 0x0000FFFF)
		print_size = 3;
	else if (wc <= 0x0010FFFF)
		print_size = 4;
	return (print_size);
}

static int		prf_print_lc(t_format solved, va_list args)
{
	wchar_t	wc;
	int		out;
	int		print_size;

	wc = (wchar_t)va_arg(args, wint_t);
	if (wc <= 0x0000007F)
		print_size = 1;
	else if (wc <= 0x000007FF)
		print_size = 2;
	else if (wc <= 0x0000FFFF)
		print_size = 3;
	else if (wc <= 0x0010FFFF)
		print_size = 4;
	out = 0;
	if (!solved.minus && solved.width > print_size && !solved.zero)
		out += prf_putnchar(' ', solved.width - print_size);
	if (!solved.minus && solved.width > print_size && solved.zero)
		out += prf_putnchar('0', solved.width - print_size);
	out += ft_putwchar(wc);
	if (solved.minus && solved.width > out)
		out += prf_putnchar(' ', solved.width - print_size);
	return (out);
}

int				prf_print_c(t_format solved, va_list args)
{
	unsigned char	c;
	int				out;
	int				print_size;

	if (solved.type == 'C' || solved.size == 4)
		return (prf_print_lc(solved, args));
	c = (unsigned char)va_arg(args, int);
	print_size = 1;
	out = 0;
	if (!solved.minus && solved.width > print_size && !solved.zero)
		out += prf_putnchar(' ', solved.width - print_size);
	if (!solved.minus && solved.width > print_size && solved.zero)
		out += prf_putnchar('0', solved.width - print_size);
	out += write(1, &c, 1);
	if (solved.minus && solved.width > out)
		out += prf_putnchar(' ', solved.width - print_size);
	return (out);
}

static int		prf_print_ls(t_format solved, va_list args)
{
	wchar_t	*wstr;
	int		out;
	int		print_size;
	int		i;

	wstr = va_arg(args, wchar_t*);
	wstr = (!wstr) ? L"(null)" : wstr;
	i = 0;
	print_size = 0;
	while (!(out = 0) && wstr[i])
		print_size += prf_wcsize(wstr[i++]);
	while (solved.precis >= 0 && --i >= 0 && (print_size > solved.precis))
		print_size -= prf_wcsize(wstr[i]);
	if ((!solved.minus && solved.width > print_size) && !solved.zero)
		out += prf_putnchar(' ', solved.width - print_size);
	else if (!solved.minus && solved.width > print_size)
		out += prf_putnchar('0', solved.width - print_size);
	i = 0;
	while (wstr[i] && (print_size -= prf_wcsize(wstr[i])) >= 0)
		out += ft_putwchar(wstr[i++]);
	if (solved.minus && solved.width > out)
		out += prf_putnchar(' ', solved.width - out);
	return (out);
}

int				prf_print_s(t_format solved, va_list args)
{
	char	*s;
	int		out;
	int		print_size;

	if (solved.type == 'S' || solved.size == 4)
		return (prf_print_ls(solved, args));
	s = va_arg(args, char*);
	s = (!s) ? "(null)" : s;
	print_size = (int)ft_strlen(s);
	if (solved.precis >= 0 && (print_size > solved.precis))
		print_size = solved.precis;
	out = 0;
	if ((!solved.minus && solved.width > print_size) && !solved.zero)
		out += prf_putnchar(' ', solved.width - print_size);
	else if (!solved.minus && solved.width > print_size)
		out += prf_putnchar('0', solved.width - print_size);
	out += write(1, s, print_size);
	if (solved.minus && solved.width > out)
		out += prf_putnchar(' ', solved.width - out);
	return (out);
}
