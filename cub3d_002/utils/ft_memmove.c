/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:21:51 by ncolomer          #+#    #+#             */
/*   Updated: 2019/11/08 18:22:06 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int ft_isnum(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

int ft_isalphnum(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else if (c >= 'a' && c <= 'z')
        return (1);
    if (c >= 'A' && c <= 'Z')
        return (1);
    else
        return (0);
}

void
	*ft_memmove(void *dst, const void *src, unsigned long len)
{
	int	i;

	if (!dst || !src)
		return (NULL);
	if (dst > src)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			*(char*)(dst + i) = *(char*)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)len)
		{
			*(char*)(dst + i) = *(char*)(src + i);
			i++;
		}
	}
	return (dst);
}
