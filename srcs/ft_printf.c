/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:04:00 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/06/09 19:11:32 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_char(c)
{
	write(1, &c, 1);
	return (1);
}

int	print_int(int	i)
{
	printf("print_int init i: %i", i);
	ft_putnbr_fd(i, 1);
	return (0);
}

static int	fsid(char c, va_list args)
{
	printf("\nfsid init specifier: %c\n", c);
	int	char_count;

	char_count = 0;
	if (c == 'c')
		print_char(va_arg(args, int));
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
	{
		// write pointer
	}
	else if (c == 'd')
	{
		// write decimal
	}
	else if (c == 'i')
	{
		print_int(va_arg(args, int));
	}
	else if (c == 'u')
	{
		// write unsigned decimal
	}
	else if (c == 'x')
	{
		// write hexadecimal lowercase
	}
	else if (c == 'X')
	{
		// write hexadecimal uppercase
	}
	else if (c == '%')
		write(1, "%", 1);
	return (char_count);
}

int	ft_printf(const char *input, ...)
{
	int		i;
	char	*str;
	va_list	args;

	if (!input)
		return (0);
	va_start(args, input);
	str = ft_strdup(input);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			printf("\n match! specifier: %c\n", str[i]);
			fsid(str[i], args);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
	va_end(args);
	free(str);
	return (0);
}

int	main(void)
{
	char	*str = "hola %c %s %i";
	char	*substr = "mundo";
	char	c = '4';
	int		i = 654654654;

	ft_printf(str, c, substr, i);
	return (0);
}
