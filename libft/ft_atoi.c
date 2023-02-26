/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:23:15 by nstoutze          #+#    #+#             */
/*   Updated: 2022/11/17 16:01:26 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	neg;
	int	nbr;
	int	i;

	neg = 1;
	nbr = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			neg = -neg;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - 48);
		if (nbr == 214748364 && str[i] == '8' && neg == -1)
			return (-2147483648);
		i++;
	}
	return (nbr * neg);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char *nb = "\t\v\f\r\n \f-06050";
    printf("%d\n", ft_atoi(nb));
    printf("%d\n", atoi(nb));

	char *n = "-123THERE IS A NYANCAT UNDER YOUR BED";
    printf("%d\n", ft_atoi(n));
    printf("%d\n", atoi(n));
    return 0;
}
*/
