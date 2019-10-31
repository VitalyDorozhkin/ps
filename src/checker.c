/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 10:51:37 by pparalax          #+#    #+#             */
/*   Updated: 2019/10/04 10:51:39 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		visualise(char *comand, t_list *lst_a, t_list *lst_b, int c)
{
	if (c)
	{
		(c < 1000) ? usleep(c * 1000) : usleep(c);
		system("clear");
		print_list(lst_a, lst_b, 0, comand);
	}
	return (0);
}

int		frre(char **str)
{
	free(*str);
	return (1);
}

int		check_comand(char **comand, t_list **lst_a, t_list **lst_b)
{
	if (!(ft_strcmp(*comand, "sa")))
		sa(*lst_a, 0);
	else if (!(ft_strcmp(*comand, "sb")))
		sb(*lst_b, 0);
	else if (!(ft_strcmp(*comand, "ss")))
		ss(*lst_a, *lst_b, 0);
	else if (!(ft_strcmp(*comand, "pa")))
		pa(lst_a, lst_b, 0);
	else if (!(ft_strcmp(*comand, "pb")))
		pb(lst_a, lst_b, 0);
	else if (!(ft_strcmp(*comand, "ra")))
		ra(lst_a, 0);
	else if (!(ft_strcmp(*comand, "rb")))
		rb(lst_b, 0);
	else if (!(ft_strcmp(*comand, "rr")))
		rr(lst_a, lst_b, 0);
	else if (!(ft_strcmp(*comand, "rra")))
		rra(lst_a, 0);
	else if (!(ft_strcmp(*comand, "rrb")))
		rrb(lst_b, 0);
	else if (!(ft_strcmp(*comand, "rrr")))
		rrr(lst_a, lst_b, 0);
	else
		return (!frre(comand));
	return (frre(comand));
}

int		main(int argc, char **argv)
{
	int		c;
	char	*comand;
	t_list	*lst_a;
	t_list	*lst_b;

	lst_b = NULL;
	c = 0;
	read_flags_v(&argc, &argv, &c);
	read_flags_f(&argc, &argv);
	lst_a = set_list(argc, argv);
	is_dub(lst_a);
	while (get_next_line(0, &comand))
		if (!check_comand(&comand, &lst_a, &lst_b) ||
			visualise(comand, lst_a, lst_b, c))
			print_message("Error");
	(lst_b) ? print_message("KO") : (void)0;
	lst_b = lst_a;
	while (lst_b->next)
	{
		if (lst_b->content_size >= lst_b->next->content_size)
			print_message("KO");
		lst_b = lst_b->next;
	}
	ft_lstfree(&lst_a);
	print_message("OK");
}
