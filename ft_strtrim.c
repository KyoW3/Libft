/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:14:46 by kwatanab          #+#    #+#             */
/*   Updated: 2018/11/12 12:14:48 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_first(char *trim)
{
	int		i;
	char	*res;

	i = 0;
	while (trim[i] == ' ' || trim[i] == '\n' || trim[i] == '\t')
		i++;
	res = &trim[i];
	return (res);
}

static size_t	ft_size(char *trim)
{
	size_t		size;

	size = ft_strlen(trim);
	if (size == 0)
		return (size);
	while (trim[size] == ' ' || trim[size] == '\t' ||
	trim[size] == '\n' || trim[size] == '\0')
		size--;
	return (size + 1);
}

char			*ft_strtrim(char const *s)
{
	char		*trim;
	char		*res;
	size_t		size;

	if (!s)
		return (NULL);
	trim = (char *)s;
	size = 0;
	trim = ft_first(trim);
	size = ft_size(trim);
	if (!(res = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	res = ft_strncpy(res, trim, size);
	res[size] = '\0';
	return (res);
}
