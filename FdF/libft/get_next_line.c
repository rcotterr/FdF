/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:21:11 by mmcclure          #+#    #+#             */
/*   Updated: 2018/12/11 13:11:46 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strlen_to_n(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

static char		*ft_joinplus(char *s1, char const *s2)
{
	char	*out;

	if (s1 && s2)
		out = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	else
		return (NULL);
	if (!out)
		return (NULL);
	out = ft_strcpy(out, s1);
	free(s1);
	out = ft_strcat(out, s2);
	return (out);
}

static int		set_buf(char **line, char **buf, const int fd)
{
	size_t	tmp;
	char	*str;

	if (ft_strchr(buf[fd], '\n'))
	{
		tmp = strlen_to_n(buf[fd]);
		str = ft_strsub(buf[fd], 0, tmp);
		*line = ft_joinplus(*line, str);
		free(str);
		buf[fd] = ft_memmove(buf[fd], &buf[fd][tmp + 1], ft_strlen(buf[fd]));
		return (1);
	}
	else if (buf[fd][0] != '\0')
	{
		*line = ft_joinplus(*line, buf[fd]);
		ft_strclr(buf[fd]);
		return (2);
	}
	return (0);
}

static int		close_gnl(char **buf, int fd, int ret, char **line)
{
	free(buf[fd]);
	buf[fd] = NULL;
	free(*line);
	*line = "";
	if (ret == 0)
		return (0);
	return (-1);
}

int				get_next_line(const int fd, char **line)
{
	static char		*buf[FD_MAX + 1];
	int				ret;
	int				flag;

	if ((fd < 0) || !line || (fd > FD_MAX))
		return (-1);
	if (!buf[fd] && !(buf[fd] = ft_strnew(BUFF_SIZE)))
		return (-1);
	*line = ft_strnew(0);
	flag = set_buf(line, buf, fd);
	if (flag == 0 || flag == 2)
		while ((ret = read(fd, buf[fd], BUFF_SIZE)))
		{
			if (ret < 0)
				return (close_gnl(buf, fd, -1, line));
			buf[fd][ret] = '\0';
			if (ft_strchr(buf[fd], '\n') && (flag = set_buf(line, buf, fd) > 0))
				break ;
			flag = set_buf(line, buf, fd);
		}
	if (flag == 0)
		return (close_gnl(buf, fd, 0, line));
	return (1);
}
