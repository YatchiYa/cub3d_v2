/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endwith.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 17:32:01 by ncolomer          #+#    #+#             */
/*   Updated: 2019/11/10 17:49:58 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int
	ft_endwith(char const *str, char const *end)
{
	int	length;
	int	end_length;
	int	i;

	length = ft_strlen(str);
	end_length = ft_strlen(end);
	if (end_length > length)
		return (0);
	while (end_length >= 0)
	{
		if (str[length] != end[end_length])
			return(0);
		end_length--;
		length--;
	}
	return (1);
}
