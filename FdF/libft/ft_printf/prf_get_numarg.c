/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_get_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 12:13:44 by mmcclure          #+#    #+#             */
/*   Updated: 2019/02/05 12:07:50 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

intmax_t		prf_get_num(char size, va_list args)
{
	intmax_t	out;

	out = va_arg(args, intmax_t);
	if (size == 1)
		out = (signed char)out;
	else if (size == 2)
		out = (short)out;
	else if (size == 4)
		out = (long)out;
	else if (size == 8)
		out = (long long)out;
	else if (size == 9)
		out = (size_t)out;
	else if (size == 10)
		out = (intmax_t)out;
	else if (size == 11)
		out = (int64_t)out;
	else
		out = (int)out;
	return (out);
}

uintmax_t		prf_get_unum(char size, va_list args)
{
	uintmax_t	out;

	out = va_arg(args, intmax_t);
	if (size == 1)
		out = (unsigned char)out;
	else if (size == 2)
		out = (unsigned short int)out;
	else if (size == 4)
		out = (unsigned long int)out;
	else if (size == 8)
		out = (unsigned long long int)out;
	else if (size == 9)
		out = (size_t)out;
	else if (size == 10)
		out = (uintmax_t)out;
	else if (size == 11)
		out = (uint64_t)out;
	else
		out = (unsigned int)out;
	return (out);
}
