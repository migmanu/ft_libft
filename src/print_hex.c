/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:56:01 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/07/10 16:54:08 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	hex_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

static void	write_hex(unsigned int n, const char fs)
{
	if (n > 15)
	{
		write_hex(n / 16, fs);
		write_hex(n % 16, fs);
	}
	else
	{
		if (n < 10)
			ft_putchar_fd((n + '0'), 1);
		else
		{
			n = n - 10;
			if (fs == 'x')
				ft_putchar_fd(n + 'a', 1);
			if (fs == 'X')
				ft_putchar_fd(n + 'A', 1);
		}
	}
}

int	print_hex(unsigned int n, char fs)
{
	if (n == 0)
		return (write(1, "0", 1));
	write_hex(n, fs);
	return (hex_len(n));
}
/*
int	main(void)
{
	unsigned int	a = 98798765;
	int r = print_hex(a, 'x');
	printf("\n\n");
	int r2 = printf("%x", a);
	printf("\n\n");
	printf("r: %d r2:%d", r, r2);
}*/
