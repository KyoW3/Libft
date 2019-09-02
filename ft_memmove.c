/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:20:25 by kwatanab          #+#    #+#             */
/*   Updated: 2018/11/09 15:20:26 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)dest;
	b = (unsigned char *)src;
	if (a > b)
		while (n != 0)
		{
			a[n - 1] = b[n - 1];
			n--;
		}
	else
		while (i < n)
		{
			a[i] = b[i];
			i++;
		}
	return (dest);
}
