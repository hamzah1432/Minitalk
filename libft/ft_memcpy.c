/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:49:16 by halmuhis          #+#    #+#             */
/*   Updated: 2024/09/10 16:49:21 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest_1;
	const char	*src_1;
	size_t		i;

	i = 0;
	dest_1 = dest;
	src_1 = src;
	if (src == dest)
		return (dest);
	while (i < n)
	{
		dest_1[i] = src_1[i];
		i++;
	}
	return (dest);
}
