/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:02:27 by kwatanab          #+#    #+#             */
/*   Updated: 2018/11/09 16:02:28 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		result;

	i = 0;
	result = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] > ((unsigned char *)s2)[i])
		{
			result = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
			return (result);
		}
		if (((unsigned char *)s1)[i] < ((unsigned char *)s2)[i])
		{
			result = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
			return (result);
		}
		i++;
	}
	return (result);
}
