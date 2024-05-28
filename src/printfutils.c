/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:35:55 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/05/26 21:11:12 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_int(long int i)
{
	ft_putnbr_fd(i, 1);
	return (digit_counter(i));
}

int	print_str(char *str)
{
	if (str == NULL)
		return (write(1, "(null)", 6));
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	digit_counter(long int n)
{
	int	r;

	r = 0;
	if (n < 0)
	{
		r++;
		n = n * -1;
	}
	if (n < 10)
		return (++r);
	while (n > 0)
	{
		r++;
		n = n / 10;
	}
	return (r);
}

int	putuint(unsigned int n)
{
	if (n > 9)
	{
		putuint(n / 10);
		putuint(n % 10);
	}
	else
		ft_putchar_fd(n + '0', 1);
	return (digit_counter(n));
}
/*
int	main(void)
{
	int	n = 1;
	unsigned int	u = 123456789;

	printf("i:%d\nu:%d", digit_counter(n), digit_counter(u));
	return (0);
}*/
