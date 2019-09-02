/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:07:11 by kwatanab          #+#    #+#             */
/*   Updated: 2019/04/01 18:33:01 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_free_tab(void **tab, size_t len)
{
    size_t y;

    y = 0;
    while (y < len)
        ft_memdel(tab[y++]);
    ft_memdel(tab);
}
