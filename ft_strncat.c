/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:22:03 by kwatanab          #+#    #+#             */
/*   Updated: 2018/11/08 15:22:04 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = ft_strlen(dest);
	if (n > ft_strlen(src))
	{
		while (src[i] != '\0')
		{
			dest[j] = src[i];
			j++;
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			dest[j] = src[i];
			j++;
			i++;
		}
	}
	dest[j] = '\0';
	return (dest);
}
