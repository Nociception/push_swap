/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:14:14 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/28 17:02:30 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_intlen(long long n, char c)
{
	int	l;

	l = 1;
	if (c == 'd' || c == 'i')
	{
		while (n / 10)
		{
			n /= 10;
			l++;
		}
		return (l);
	}
	if (c == 'x' || c == 'X')
	{
		while (n / 16)
		{
			n /= 16;
			l++;
		}
		return (l);
	}
	return (0);
}

int	ft_unslololen(unsigned long long n)
{
	int	l;

	l = 1;
	while (n / 16)
	{
		n /= 16;
		l++;
	}
	return (l);
}
/*
#include <stdio.h>
int main()
{
	printf("%d\n", pf_intlen(0, 'd'));
	return 0;
}
*/
