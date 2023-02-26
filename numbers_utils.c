/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:25:53 by nstoutze          #+#    #+#             */
/*   Updated: 2023/01/29 15:25:53 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	abs_val(int n)
{
	if (n >= 0)
		return (n);
	return (-n);
}

void	swap_int(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

int	ft_max(int x, int y)
{
	if (x >= y)
		return (x);
	return (y);
}

int	mean_two_positive_numbers(int x, int y)
{
	return ((x + y) / 2);
}

int	ft_sqrt(int nb)
{
	int	sr;

	sr = 0;
	if (nb < 0)
		return (0);
	while (sr < 46341)
	{
		if (sr * sr >= nb)
			return (sr);
		sr++;
	}
	return (0);
}
/*
int	len_int(int nb)
{
	int	len;

	len = 0;
	if (!nb)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb)
	{
		len++;
		nb /= 10;
	}
	return (len);
}
*/