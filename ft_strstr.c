/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:28:00 by kwatanab          #+#    #+#             */
/*   Updated: 2018/11/08 15:28:01 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = 0;
	if (to_find[i] == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			res = (char *)&str[i];
			while (str[i + j] == to_find[j])
			{
				if (to_find[j + 1] == '\0')
					return (res);
				j++;
			}
			res = 0;
		}
		i++;
	}
	return (0);
}
