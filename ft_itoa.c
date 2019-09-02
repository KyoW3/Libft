/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:41:06 by kwatanab          #+#    #+#             */
/*   Updated: 2018/11/12 14:41:08 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_digit(int n)
{
	int size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size++);
}

char			*ft_itoa(int n)
{
	unsigned int	nb;
	int				length;
	char			*str;

	nb = n;
	length = ft_digit(nb);
	if (!(str = (char*)malloc(sizeof(*str) * (length + 1))))
		return (NULL);
	str[length] = '\0';
	length--;
	if (n < 0)
		nb = -nb;
	while (length >= 0)
	{
		str[length] = (nb % 10) + '0';
		length--;
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
