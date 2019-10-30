/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 22:35:33 by pparalax          #+#    #+#             */
/*   Updated: 2019/10/02 22:35:36 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_cut_di(char *snbr)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strnew((ft_strlen(snbr) + (snbr[0] != '-') > (size_t)
		g_flags->cut ? (int)ft_strlen(snbr) + (snbr[0] != '-') :
		g_flags->cut) + 1);
	if ((snbr)[0] != '-')
	{
		tmp[0] = '+';
		while (i++ < (int)(g_flags->cut - ft_strlen(snbr)))
			ft_strcat(tmp, "0");
		ft_strcat(tmp, snbr);
	}
	else
	{
		tmp[0] = '-';
		while (i++ < (int)(g_flags->cut - ft_strlen(snbr) + 1))
			ft_strcat(tmp, "0");
		ft_strcat(tmp, &snbr[1]);
	}
	free(snbr);
	return ((tmp) ? tmp : snbr);
}

int		print_di(long long int nbr)
{
	char	*snbr;
	int		c;

	snbr = add_cut_di(ft_itoa_base(nbr, 10, 'a'));
	c = g_flags->min_width - ft_strlen(snbr) +
		(!(g_flags->plus || g_flags->space) && nbr >= 0) +
		((!nbr && g_flags->dote && !g_flags->cut));
	if (g_flags->space && !g_flags->plus && nbr >= 0)
		ft_putcharf(' ');
	if (!g_flags->minus && (!g_flags->zero || g_flags->dote))
		ft_putcharsf(' ', c);
	if (g_flags->plus || nbr < 0)
		ft_putcharf(snbr[0]);
	if (!g_flags->minus && g_flags->zero && !g_flags->dote)
		ft_putcharsf('0', c);
	if (!(!nbr && g_flags->dote && !g_flags->cut))
		ft_putstrf(&snbr[1]);
	if (g_flags->minus)
		ft_putcharsf(' ', c);
	free(snbr);
	return (0);
}
