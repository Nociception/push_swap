/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:13:28 by nstoutze          #+#    #+#             */
/*   Updated: 2023/01/23 20:27:29 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	are_numbers_unique(int *array, int len)
{
	int	i;
	int	j;

	i = -1;
	while (++i < len)
	{
		j = i;
		while (++j < len)
		{
			if (array[i] == array[j])
				return (0);
		}
	}
	return (1);
}

int	*copy_array(int *array, int len)
{
	int	*copy;

	copy = malloc(sizeof(int) * len);
	if (!copy)
		return (NULL);
	while (--len >= 0)
		copy[len] = array[len];
	return (copy);
}

int	*sort_array(int *array, int len)
{
	int	*sorted;
	int	i;
	int	j;
	int	min;
	int	index_min;

	i = -1;
	sorted = copy_array(array, len);
	while (++i < len)
	{
		j = i;
		min = sorted[j];
		index_min = j;
		while (++j < len)
		{
			if (min > sorted[j])
			{
				min = sorted[j];
				index_min = j;
			}
		}
		swap_int(&sorted[i], &sorted[index_min]);
	}
	return (sorted);
}

int	index_nb_in_array(int nb, int *array, int len)
{
	while (--len >= 0)
	{
		if (array[len] == nb)
			return (len);
	}
	return (-1);
}

int	is_nb_in_array(int nb, int *array, int len_array)
{
	int	i;

	i = -1;
	while (++i < len_array)
	{
		if (array[i] == nb)
			return (1);
	}
	return (0);
}
/*
void	show_array(int *array, int len)
{
	int	i;

	i = -1;
	printf("------------------\n");
	while (++i < len)
		printf("%d\n", array[i]);
	printf("------------------\n");
}
*/