/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:52:47 by mmcclure          #+#    #+#             */
/*   Updated: 2019/03/10 19:44:07 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static char		*fdf_strjoin(char **s1, char *s2)
{
	char	**tmp;
	char	*out;

	tmp = s1;
	out = ft_strjoin(*s1, s2);
	ft_strdel(tmp);
	return (out);
}

char			*fdf_reader(char *input)
{
	int		fd;
	char	*read;
	char	*line;

	if ((fd = open(input, O_RDONLY)) == -1)
	{
		ft_printf("Couldn't find file - %s.\n", input);
		exit(0);
	}
	read = ft_strnew(1);
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_strlen(line) == 0)
		{
			write(2, "Invalid map: Wrong line length.\n", 32);
			ft_strdel(&line);
			ft_strdel(&read);
			exit(0);
		}
		read = fdf_strjoin(&read, line);
		read = fdf_strjoin(&read, "\n");
		free(line);
	}
	close(fd);
	return (read);
}
