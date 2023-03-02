/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:15:01 by nstoutze          #+#    #+#             */
/*   Updated: 2023/03/02 20:10:30 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	simple_atoi(char *s)
{
	int	n;
	int	i;
	int	neg;

	n = 0;
	i = -1;
	neg = 1;
	if (s[0] == '-' || s[0] == '+')
	{
		i++;
		if (s[0] == '-')
			neg = -1;
	}
	while (s[++i])
	{
		n *= 10;
		n += s[i] - 48;
	}
	return (n * neg);
}

void	len_and_shift(int *len, int *shift)
{
	*len *= -1;
	*shift = 0;
}

int	*fill_array_with_valid_data(int len, char *av[])
{
	int	*array;
	int	i;
	int	shift;

	i = -1;
	if (len < 0)
		len_and_shift(&len, &shift);
	else
		shift = 1;
	array = (int *)malloc(sizeof(int) * len);
	if (!array)
		return (NULL);
	while (++i < len)
	{
		if (ft_atoi_push_swap(av[i + shift]))
			array[i] = simple_atoi(av[i + shift]);
		else
		{
			janitor(array);
			return (NULL);
		}
	}
	return (array);
}
