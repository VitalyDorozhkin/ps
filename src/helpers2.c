/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pparalax <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 10:51:37 by pparalax          #+#    #+#             */
/*   Updated: 2019/10/04 10:51:39 by pparalax         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	read_flags_v(int *argc, char ***argv, int *c)
{
	if (*argc > 1 && (*argv)[1][0] == '-')
	{
		if ((*argv)[1][1] == 'v')
		{
			*c = 200;
			if ((*argv)[1][2])
				*c = ft_atoi(&((*argv)[1][2]));
			(*argc)--;
			(*argv)++;
		}
	}
	if (*argc == 1)
		exit(0);
}

void	read_flags_f(int *argc, char ***argv)
{
	int		fd;
	char	*line;

	if ((*argv)[1][0] == '-' && (*argv)[1][1] == 'f')
	{
		fd = open((*argv)[2], O_RDONLY);
		if (get_next_line(fd, &line) == -1)
			print_message("Error");
		(*argv)[2] = line;
		(*argv)++;
		(*argc)--;
		close(fd);
	}
	if (*argc == 1)
		exit(0);
}

void	ft_lstfree(t_list **alst)
{
	t_list	*tmp;
	t_list	*next;

	tmp = *alst;
	while (tmp && alst)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*alst = NULL;
}
