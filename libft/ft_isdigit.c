/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halmuhis <halmuhis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:33:47 by halmuhis          #+#    #+#             */
/*   Updated: 2024/09/10 16:33:47 by halmuhis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int i)
{
	if (i > 47 && i < 58)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
