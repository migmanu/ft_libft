/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:04:00 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/07/12 17:54:21 by jmigoya-         ###   ########.fr       */
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

static int	fsid(char c, va_list args)
{
	if (c == 'c')
		return (print_char(va_arg(args, int)));
	else if (c == 's')
		return (print_str(va_arg(args, char *)));
	else if (c == 'p')
		return (print_ptr(va_arg(args, void *)));
	else if (c == 'i' || c == 'd')
		return (print_int(va_arg(args, int)));
	else if (c == 'u')
		return (putuint(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (print_hex(va_arg(args, unsigned int), 'x'));
	else if (c == 'X')
		return (print_hex(va_arg(args, unsigned int), 'X'));
	else if (c == '%')
		return (write(1, "%", 1));
	else if (c == '@')
		return (write(1, "%@", 2));
	return (0);
}

int	ft_printf(const char *input, ...)
{
	int		i;
	int		char_count;
	char	*str;
	va_list	args;

	if (!input)
		return (-1);
	va_start(args, input);
	str = ft_strdup(input);
	char_count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && (str[i + 1] != '\0' || str[i - 1] == '%'))
			char_count += fsid(str[++i], args) - 1;
		else if (str[i] != '%')
			write(1, &str[i], 1);
		else if (str[i] == '%' && str[i - 1] != '%' && str[i + 1] == '\0')
			char_count = -2;
		i++;
		char_count++;
	}
	va_end(args);
	free(str);
	return (char_count);
}
/*
int	main(void)
{
	char	*str = "hola %% %c %s %i %u %x %X %p";
	char	*substr = "mundo";
	char	c = '4';
	int		i = 654654654;
	unsigned int	u = 4294967295;
	int x = -11;
	int X = -12;
	char	p;

	//int r = ft_printf(str, c, substr, i, u, x, X, p);
	int r = ft_printf(" %x ", -10);
	printf("\n\n");
	//int r2 = printf(str, c, substr, i, u, x, X, p);
	int r2 = printf(" %x ", -10);
	printf("\n\n");
	printf("r:%d r2:%d", r, r2);
	return (0);
}*/
