/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:14:56 by halmuhis          #+#    #+#             */
/*   Updated: 2025/02/16 18:14:58 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_append(char **str, unsigned char ch)
{
	char			*temp;
	unsigned int	size;
	size_t			i;

	i = 0;
	if (!str || !*str)
		size = 0;
	else
		size = strlen(*str);
	temp = malloc(size + 2);
	if (!temp)
		return ;
	while (i < size)
	{
		temp[i] = (*str)[i];
		i++;
	}
	temp[size] = ch;
	temp[size + 1] = '\0';
	free(*str);
	*str = temp;
}
// int main()
// {
//     char* str = malloc(2);
//     if (!str)
//     {
//         // Handle memory allocation failure
//         return 1;
//     }

//     str[0] = 'h';
//     str[1] = '\0';
//     apend(&str, 'a');
//     apend(&str, 'm');

//     printf("%s\n", str);
//     free(str);

//     return 0;
// }
