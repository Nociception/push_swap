/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 22:56:24 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/28 22:56:57 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int			checkbase(char *base);
int			format_c(va_list arg);
int			format_di(va_list arg);
int			format_p(va_list arg);
int			format_s(va_list arg);
int			format_u(va_list arg);
int			format_pc(void);
int			format_x(va_list arg);
int			format_upx(va_list arg);
int			ft_intlen(long long n, char c);
void		ft_putnbr_base(long long nbr, char *base);
void		ft_putnbr_ptr(unsigned long long nb, char *base);
int			ft_printf(const char *s, ...);
int			ft_unslololen(unsigned long long n);

#endif
