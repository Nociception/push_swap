/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:23:50 by nstoutze          #+#    #+#             */
/*   Updated: 2023/02/26 19:15:59 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "pf_printf.h"

static int	specifier(va_list arg, const char *s, int i)
{
	if (s[i] == 'c')
		return (format_c(arg));
	if (s[i] == 'd' || s[i] == 'i')
		return (format_di(arg));
	if (s[i] == 'u')
		return (format_u(arg));
	if (s[i] == 'p')
		return (format_p(arg));
	if (s[i] == 'x')
		return (format_x(arg));
	if (s[i] == 'X')
		return (format_upx(arg));
	if (s[i] == 's')
		return (format_s(arg));
	if (s[i] == '%')
		return (format_pc());
	return (0);
}

int	pf_printf(const char *s, ...)
{
	va_list	arg;
	int		written;
	int		i;

	va_start(arg, s);
	written = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == '%' && s[i + 1])
			written += specifier(arg, s, ++i);
		else
		{
			pf_putchar(s[i]);
			written++;
		}
	}
	va_end(arg);
	return (written);
}
/*
#include <limits.h>
#include <stdio.h>
int main()
{
	
	int res = pf_printf("coucou %      \nlol\n");
    int res2 = printf  ("coucou %      \nlol\n");
	printf("\n");

	int res3 = pf_printf("%d%d\n", 0, 21);
    int res4 = printf   ("%d%d\n", 0, 21);
	printf("\n");
    
	int res5 = pf_printf("coucou %u ca va ?\n", INT_MAX);
    int res6 = printf   ("coucou %u ca va ?\n", INT_MAX);
	printf("\n");
	
    int res7 = pf_printf("coucou %i ca va ?\n", INT_MAX);
    int res8 = printf   ("coucou %i ca va ?\n", INT_MAX);
	printf("\n");
    
    int i = 0;
    int res9 = pf_printf("coucou %p ca va ?\n", &i);
    int res10 = printf  ("coucou %p ca va ?\n", &i);
	printf("\n");
     
    int res11 = pf_printf("coucou %d %s ca va ?\n", 42, "salut");
    int res12 = printf   ("coucou %d %s ca va ?\n", 42, "salut");
	printf("\n");

    int res13 = pf_printf("coucou %c %c ca va ?\n", 'H', 'G');
    int res14 = printf   ("coucou %c %c ca va ?\n", 'H', 'G');
	printf("\n");
   	  
    int res15 = pf_printf("coucou %d %d ca va ?\n", 42, 21);
    int res16 = printf   ("coucou %d %d ca va ?\n", 42, 21);
	printf("\n");
	
	char *nullstring = NULL;
	int res17 = pf_printf("%s\n", nullstring);
	int res18 = printf   ("%s\n", nullstring);
	printf("\n");
	
	char *nullstring2 = NULL;
	int res19 = pf_printf("%p\n", nullstring2);
	int res20 = printf   ("%p\n", nullstring2);
	printf("\n");

	
	int res21 = pf_printf("pf_printf % ");
	int res22 = printf   ("000printf % ");
	printf("\n");
	
	int res23 = pf_printf("en hexa : %x\n", UINT_MAX);
	int res24 = printf   ("en hexa : %x\n", UINT_MAX);
    printf("\n");

	//if (res != res2)
	//	printf("\nres = %d\nres2 = %d\n", res, res2);
	if (res3 != res4)
        printf("\nres3 = %d\nres4 = %d\n", res3, res4);
	if (res5 != res6)
        printf("\nres5 = %d\nres6 = %d\n", res5, res6);
	if (res7 != res8)
        printf("\nres7 = %d\nres8 = %d\n", res7, res8);
	if (res9 != res10)
        printf("\nres9 = %d\nres10 = %d\n", res9, res10);
	if (res11 != res12)
        printf("\nres11 = %d\nres12 = %d\n", res11, res12);
	if (res13 != res14)
        printf("\nres13 = %d\nres14 = %d\n", res13, res14);
	if (res15 != res16)
        printf("\nres15 = %d\nres16 = %d\n", res15, res16);
	if (res17 != res18)
        printf("\nres17 = %d\nres18 = %d\n", res17, res18);
	if (res19 != res20)
        printf("\nres19 = %d\nres20 = %d\n", res19, res20);
	//if (res21 != res22)
    //    printf("\nres21 = %d\nres22 = %d\n", res21, res22);
	if (res23 != res24)
        printf("\nres23 = %d\nres24 = %d\n", res23, res24);
    return 0;
}
*/
