/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:36:08 by mmcclure          #+#    #+#             */
/*   Updated: 2019/02/10 16:35:59 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_func	g_func[21] = {
	{'d', prf_print_di}, {'D', prf_print_di},
	{'i', prf_print_di},
	{'u', prf_print_u}, {'U', prf_print_u},
	{'o', prf_print_o}, {'O', prf_print_o},
	{'x', prf_print_x}, {'X', prf_print_x},
	{'s', prf_print_s}, {'S', prf_print_s},
	{'c', prf_print_c}, {'C', prf_print_c},
	{'p', prf_print_p},
	{'%', prf_print_per},
	{'f', prf_print_f}, {'F', prf_print_f},
	{'b', prf_print_b}, {'B', prf_print_b},
	{'r', prf_print_r}, {'k', prf_print_k}};

static void		prf_type_n(va_list args, int in)
{
	int		*n;

	n = va_arg(args, int*);
	*n = in;
}

static int		prf_format_print(char **format, t_format solved,
												va_list args, int in)
{
	int		i;
	int		out;

	i = 0;
	out = 0;
	while (g_func[i].type != solved.type && i < 21)
		i++;
	if (solved.type == 'n')
		prf_type_n(args, in);
	else if (i < 21)
		out += g_func[i].f(solved, args);
	else if (**format)
	{
		while (!solved.minus && solved.width-- > 1)
			if (solved.zero)
				out += write(1, "0", 1);
			else
				out += write(1, " ", 1);
		out += write(1, *format, 1);
		*format += 1;
		while (solved.minus && solved.width-- > 1)
			out += write(1, " ", 1);
	}
	return (out);
}

static int		ft_strlen_to(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	return (i);
}

int				ft_printf(const char *restrict format, ...)
{
	va_list		args;
	int			out;
	char		*tmp;
	t_format	solved;

	out = 0;
	tmp = (char*)format;
	va_start(args, format);
	while (*tmp)
		if (*tmp == '%')
		{
			tmp++;
			solved = prf_format_slv(&tmp, args);
			if ((solved.width < 0) && (solved.minus = 1))
				solved.width *= -1;
			out += prf_format_print(&tmp, solved, args, out);
		}
		else
		{
			solved.width = ft_strlen_to(tmp);
			out += write(1, tmp, solved.width);
			tmp += solved.width;
		}
	va_end(args);
	return (out);
}
