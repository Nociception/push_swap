/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:08:09 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/16 18:08:09 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	blanks(char *s, int *i)
{
	while (s[*i] == ' ' || (s[*i] >= 9 && s[*i] <= 13))
		(*i)++;
}

static void	signs(char *s, int *i, long long *neg)
{
	if (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
			*neg *= -1;
		(*i)++;
	}
}

static void	zeros(char *s, int *i)
{
	while (s[*i] == '0')
		(*i)++;
}

static void	nb_from_string(char *s, int *i, long long *nb)
{
	int	len_nb;

	len_nb = 0;
	while (s[*i] >= '0' && s[*i] <= '9' && len_nb <= 10)
	{
		(*nb) = (*nb) * 10 + (s[*i] - 48);
		len_nb++;
		(*i)++;
	}
}

int	ft_atoi_push_swap(char *s)
{
	int			i;
	long long	neg;
	long long	nb;

	neg = 1;
	nb = 0;
	i = 0;
	if (!s[i])
		return (0);
	blanks(s, &i);
	signs(s, &i, &neg);
	zeros(s, &i);
	nb_from_string(s, &i, &nb);
	if (s[i])
		return (0);
	nb *= neg;
	if (nb >= -2147483648 && nb <= 2147483647)
		return (1);
	return (0);
}
