/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:48:44 by mmcclure          #+#    #+#             */
/*   Updated: 2019/02/10 12:34:13 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

typedef struct		s_format
{
	char			minus;
	char			plus;
	char			space;
	char			hash;
	char			zero;
	int				width;
	int				precis;
	char			size;
	char			type;
}					t_format;

typedef struct		s_func
{
	char			type;
	int				(*f)(t_format, va_list);
}					t_func;

int					ft_printf(const char *restrict format, ...);
t_format			prf_format_slv(char **flag, va_list args);
intmax_t			prf_get_num(char size, va_list args);
uintmax_t			prf_get_unum(char size, va_list args);
int					prf_nbrsize(size_t nbr, int base);
int					prf_putunbr(size_t nbr, int base, int precis, char to_up);
int					prf_putnchar(char c, int size);
int					prf_print_di(t_format solved, va_list args);
int					prf_print_u(t_format solved, va_list args);
int					prf_print_o(t_format solved, va_list args);
int					prf_print_x(t_format solved, va_list args);
int					prf_print_c(t_format solved, va_list args);
int					prf_print_s(t_format solved, va_list args);
int					prf_print_p(t_format solved, va_list args);
int					prf_print_per(t_format solved, va_list args);
int					prf_print_f(t_format solved, va_list args);
int					prf_print_b(t_format solved, va_list args);
int					prf_print_r(t_format solved, va_list args);
int					prf_print_k(t_format solved, va_list args);
#endif
