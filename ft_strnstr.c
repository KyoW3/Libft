/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:58:53 by kwatanab          #+#    #+#             */
/*   Updated: 2018/11/08 16:58:56 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	char			*str1;
	char			*str2;

	if (!*s2)
		return ((char *)s1);
	while (n-- && *s1)
	{
		if (*s1 == *s2)
		{
			i = n;
			str1 = (char *)s1 + 1;
			str2 = (char *)s2 + 1;
			while (i-- && *str1 && *str2 && *str1 == *str2)
			{
				++str1;
				++str2;
			}
			if (!*str2)
				return ((char *)s1);
		}
		++s1;
	}
	return (NULL);
}
