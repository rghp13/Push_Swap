/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 21:49:46 by rponsonn          #+#    #+#             */
/*   Updated: 2021/09/24 00:58:44 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_cont	*ft_init_cont(char **separated)
{
	t_cont	*container;
	int		i;

	i = 0;
	container = NULL;
	container = malloc(sizeof(t_cont));
	if (container == NULL)
	{
		while (separated[i])
			free(separated[i++]);
		free(separated);
		ft_exit();
	}
	container->separated = separated;
	container->a = NULL;
	container->b = NULL;
	container->a = malloc(sizeof(t_stack));
	container->b = malloc(sizeof(t_stack));
	if (container->a == NULL || container->b == NULL)
		ft_free_exit(container);
	container->a->stack = NULL;
	container->b->stack = NULL;
	return (container);
}

int	ft_init_values(int argc, t_cont *cont)
{
	cont->stack_max = argc - 1;
	cont->a->stack = malloc(sizeof(int) * (cont->stack_max));
	cont->b->stack = malloc(sizeof(int) * (cont->stack_max));
	if (cont->a->stack == NULL || cont->b->stack == NULL)
		ft_free_exit(cont);
	cont->a->top = 0;
	cont->b->top = 0;
	return (0);
}

t_cont	*ft_init(int argc, char **separated)
{
	t_cont	*container;

	container = ft_init_cont(separated);
	ft_init_values(argc, container);
	return (container);
}

int	ft_pick_sort(t_cont *cont)
{
	if (ft_check_sorted(cont) == 0)
		return (0);
	if (cont->stack_max == 2)
		ft_sa(cont);
	else if (cont->stack_max == 3)
		ft_three_size(cont->a, cont);
	else if (cont->stack_max <= 5)
		ft_five_size(cont);
	else
		ft_one_hun_size(cont);
	return (0);
}

int	main(int argc, char **argv)
{
	t_cont	*cont;
	char	**separated_input;

	separated_input = NULL;
	cont = NULL;
	if (argc < 2)
		exit(0);
	else if (argc == 2)
	{
		cont = ft_sep_handler(separated_input, argv);
	}
	else
	{
		cont = ft_init(argc, separated_input);
		ft_parse(cont, argv);
	}
	if (ft_make_relative(cont->a, cont->stack_max) == -1)
		ft_free_exit(cont);
	ft_pick_sort(cont);
	ft_free(cont);
	return (0);
}
