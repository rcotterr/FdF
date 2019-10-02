/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitchrs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 10:46:54 by mmcclure          #+#    #+#             */
/*   Updated: 2018/11/30 15:33:02 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wrdscount(char const *s, char *spaces)
{
	size_t	count;
	size_t	i;

	if ((i = ft_strlen(s)) == 0)
		return (0);
	count = 0;
	if (!(ft_strchrcount(spaces, s[i - 1])))
		count++;
	i = 0;
	while (s[i + 1] != '\0')
	{
		if ((!ft_strchrcount(spaces, s[i])) && ft_strchrcount(spaces, s[i + 1]))
			count++;
		i++;
	}
	return (count);
}

static size_t	ft_slsps(char const *s, char *spaces)
{
	size_t	i;

	i = 0;
	while ((s[i] != '\0') && (!(ft_strchrcount(spaces, s[i]))))
		i++;
	return (i);
}

static void		split_close(char **s)
{
	size_t i;

	i = 0;
	while (s)
	{
		while (s[i])
		{
			ft_strdel(&s[i]);
			i++;
		}
		free(s);
		s = NULL;
	}
}

char			**ft_strsplitchrs(char const *s, char *spaces)
{
	char	**out;
	int		i;
	int		word;

	if (!(out = (char**)malloc(sizeof(char*) * (ft_wrdscount(s, spaces) + 1))))
		return (NULL);
	i = -1;
	word = -1;
	while (s[++i] != '\0')
		if (!ft_strchrcount(spaces, s[i]))
		{
			if ((word == -1) || ft_strchrcount(spaces, s[i - 1]))
			{
				word++;
				if (!(out[word] = ft_strnewndata(&s[i],
								ft_slsps(&s[i], spaces))))
				{
					split_close(out);
					return (NULL);
				}
				i += ft_slsps(&s[i], spaces);
			}
		}
	out[++word] = 0;
	return (out);
}
