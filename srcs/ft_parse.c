/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 20:02:09 by romain            #+#    #+#             */
/*   Updated: 2021/09/22 17:01:53 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
**Make changes so that you scan the argv for non numeric chars with the
**exception of '-'
*/

int	ft_check_string(char *str)
{
	int	i;

	i = 1;
	if (ft_strlen(str) < 1)
		return (0);
	if (!(str[0] == '-' || str[0] == '+' || ft_isdigit(str[0])))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_forbidden(t_cont *cont, char **argv)
{
	int	i;

	i = 1;
	while (i <= cont->stack_max)
	{
		if (!ft_check_string(argv[i]))
			ft_free_exit(cont);
		i++;
	}
	return (0);
}

int	ft_sep_check_forbidden(t_cont *cont, char **argv)
{
	int	i;

	i = 0;
	while (i < cont->stack_max)
	{
		if (!ft_check_string(argv[i]))
			ft_free_exit(cont);
		i++;
	}
	return (0);
}

int	ft_check_duplicate(t_cont *cont)
{
	int	i;
	int	k;

	i = 0;
	while (i < cont->a->top)
	{
		k = i + 1;
		while (k < cont->a->top)
		{
			if (cont->a->stack[i] == cont->a->stack[k])
				ft_free_exit(cont);
			k++;
		}
		i++;
	}
	return (0);
}

int	ft_parse(t_cont *cont, char **argv)
{
	int		i;
	int		k;
	long	hold;

	i = 1;
	k = cont->stack_max - 1;
	ft_check_forbidden(cont, argv);
	while (i <= cont->stack_max)
	{
		hold = ft_atol(argv[i]);
		if (hold > 0x7fffffff || hold < -2147483648)
			ft_free_exit(cont);
		cont->a->stack[k] = (int)hold;
		i++;
		cont->a->top += 1;
		--k;
	}
	ft_check_duplicate(cont);
	return (0);
}
