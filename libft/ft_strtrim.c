/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:50:17 by halmuhis          #+#    #+#             */
/*   Updated: 2024/09/10 16:50:34 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		prefix_index;
	int		suffix_index;
	char	*str;

	prefix_index = 0;
	suffix_index = ft_strlen(s1) - 1;
	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, s1[prefix_index]) && s1[prefix_index])
		prefix_index++;
	while (ft_strchr(set, s1[suffix_index]) && suffix_index > prefix_index)
		suffix_index--;
	str = malloc(sizeof(char) * (suffix_index - prefix_index + 2));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + prefix_index, suffix_index - prefix_index + 2);
	return (str);
}
