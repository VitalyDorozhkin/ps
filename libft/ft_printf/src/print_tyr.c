/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tyr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 22:44:20 by pparalax          #+#    #+#             */
/*   Updated: 2019/10/07 22:44:24 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_t(char **arr)
{
	int j;

	j = 0;
	while (arr[j])
	{
		ft_putstrf(arr[j]);
		ft_putcharf('\n');
		j++;
	}
}

void	print_y(char ***arr)
{
	int i;
	int j;

	j = 0;
	while (arr[j])
	{
		i = 0;
		while (arr[j][i])
		{
			ft_putstrf(arr[j][i]);
			ft_putcharf(' ');
			i++;
		}
		ft_putcharf('\n');
		j++;
	}
}
