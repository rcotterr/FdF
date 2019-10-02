/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_putunbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 13:27:08 by mmcclure          #+#    #+#             */
/*   Updated: 2019/02/08 14:32:12 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			prf_nbrsize(size_t nbr, int base)
{
	int	print_size;

	print_size = 1;
	while (nbr >= (size_t)base)
	{
		nbr /= base;
		print_size++;
	}
	return (print_size);
}

int			prf_putunbr(size_t nbr, int base, int precis, char to_up)
{
	int		print_size;
	char	*str;
	char	*b;
	int		out;

	if (precis == 0 && nbr == 0)
		return (0);
	b = (to_up) ? "0123456789ABCDEF" : "0123456789abcdef";
	print_size = prf_nbrsize(nbr, base);
	print_size = (precis > print_size) ? precis : print_size;
	if (!(str = ft_strnew(print_size)))
		return (0);
	while (precis >= 0)
		str[precis--] = '0';
	str[print_size--] = '\0';
	while (nbr >= (size_t)base)
	{
		str[print_size--] = (b[(nbr % base)]);
		nbr /= base;
	}
	str[print_size] = (b[(nbr % base)]);
	out = ft_strlen(str);
	write(1, str, out);
	free(str);
	return (out);
}

int			prf_putnchar(char c, int size)
{
	char	*str;
	int		out;

	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	ft_memset(str, c, size);
	out = write(1, str, size);
	free(str);
	return (out);
}
