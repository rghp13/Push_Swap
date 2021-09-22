/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:39:31 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/22 15:42:06 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
**if sorted return 0 else 1
*/

int	ft_check_sorted(t_cont *cont)
{
	int	i;

	i = 0;
	while (i < cont->a->top - 1)
	{
		if (cont->a->stack[i] < cont->a->stack[i + 1])
			return (1);
		i++;
	}
	return (0);
}

t_cont	*ft_sep_handler(char **separated_input, char **argv)
{
	t_cont	*cont;
	int		i;

	i = 0;
	separated_input = ft_split(argv[1], ' ');
	if (separated_input == NULL)
		ft_exit();
	while (separated_input[i])
		i++;
	cont = ft_init(i + 1, separated_input);
	ft_sep_parse(cont, separated_input);
	return (cont);
}
