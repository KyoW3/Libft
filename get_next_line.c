/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:53:48 by mikim             #+#    #+#             */
/*   Updated: 2019/04/24 17:32:35 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_elseif(char **str, char **line, int fd, int ret)
{
	if (ret == BUFF_SIZE)
		return (get_next_line(fd, line));
	if (!(*line = ft_strdup(str[fd])))
		return (-1);
	ft_strdel(&str[fd]);
	return (1);
}

int		ft_stock_line(char **str, char **line, int fd, int ret)
{
	char	*tmp;
	int		i;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	if (str[fd][i] == '\n')
	{
		if (!(*line = ft_strsub(str[fd], 0, i)))
			return (-1);
		if (!(tmp = ft_strdup(str[fd] + i + 1)))
			return (-1);
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][i] == '\0')
		ft_elseif(str, line, fd, ret);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[4864];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (str[fd] == NULL)
			if (!(str[fd] = ft_strnew(1)))
				return (-1);
		if (!(tmp = ft_strjoin(str[fd], buff)))
			return (-1);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	return (ft_stock_line(str, line, fd, ret));
}
