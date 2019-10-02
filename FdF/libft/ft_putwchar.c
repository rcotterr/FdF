/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 13:03:18 by mmcclure          #+#    #+#             */
/*   Updated: 2019/02/04 12:34:26 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

wint_t	ft_putwchar(wchar_t wc)
{
	int		out;
	int		size;
	char	print;

	if (wc <= 0x0000007F && (size = 1))
		return (write(1, &wc, 1));
	else if (wc <= 0x000007FF && (size = 2))
		print = (wc >> 6) + 0xC0;
	else if (wc <= 0x0000FFFF && (size = 3))
		print = (wc >> 12) + 0xE0;
	else if (wc <= 0x0010FFFF && (size = 4))
		print = (wc >> 18) + 0xF0;
	out = write(1, &print, 1);
	while (--size > 0)
	{
		print = ((wc >> (6 * (size - 1))) & 0x3F) + 0x80;
		out += write(1, &print, 1);
	}
	return (out);
}
