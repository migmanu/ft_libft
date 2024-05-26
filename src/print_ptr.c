/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:50:23 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/06/21 20:11:21 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	hex_len(unsigned long n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

static void	write_ptr_hex(uintptr_t n)
{
	if (n > 15)
	{
		write_ptr_hex(n / 16);
		write_ptr_hex(n % 16);
	}
	else
	{
		if (n < 10)
			ft_putchar_fd((n + '0'), 1);
		else
			ft_putchar_fd((n - 10) + 'a', 1);
	}
}

int	print_ptr(unsigned long *ptr)
{
	int					len;
	unsigned long long	add;

	add = (unsigned long long)ptr;
	len = 0;
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	len += write(1, "0x", 2);
	write_ptr_hex(add);
	return (len + hex_len(add));
}
/*
int	main(void)
{
	unsigned long	a;
	int	r = print_ptr(&a);
	printf("\n\n");
	int	r2 = printf("%p", &a);
	printf("\nr:%d\nr2:%d\n", r, r2);
	return (0);
}*/
