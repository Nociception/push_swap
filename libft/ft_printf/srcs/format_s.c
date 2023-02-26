/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:26:18 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/26 19:59:03 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	format_s(va_list arg)
{
	char	*str;

	str = va_arg(arg, char *);
	if (!str)
	{
		pf_putstr("(null)");
		return (6);
	}
	pf_putstr(str);
	return (pf_strlen(str));
}
