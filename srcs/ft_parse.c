/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 20:02:09 by romain            #+#    #+#             */
/*   Updated: 2021/09/06 22:21:48 by romain           ###   ########.fr       */
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
	if (!(str[0] == '-' || ft_isdigit(str[0])))
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

int	ft_check_duplicate(t_cont *cont)
{
	int	i;
	int	k;

	i = 0;
	while (i < cont->A->top)
	{
		k = i + 1;
		while (k < cont->A->top)
		{
			if (cont->A->stack[i] == cont->A->stack[k])
				ft_free_exit(cont);
			k++;
		}
		i++;
	}
	return (0);
}

int	ft_parse(t_cont *cont, char **argv)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	ft_check_forbidden(cont, argv);
	while (i <= cont->stack_max)
	{
		cont->A->stack[k] = ft_atoi(argv[i]);
		i++;
		cont->A->top = ++k;
	}
	ft_check_duplicate(cont);
	return (0);
}
