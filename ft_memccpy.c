/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:02:26 by kwatanab          #+#    #+#             */
/*   Updated: 2018/11/09 14:02:27 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, void const *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	while (i < n)
	{
		str1[i] = str2[i];
		if (str2[i] == (unsigned char)c)
			return ((void *)&str1[i + 1]);
		i++;
	}
	return (NULL);
}
