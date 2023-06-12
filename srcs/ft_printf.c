/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:04:00 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/06/12 16:57:01 by jmigoya-         ###   ########.fr       */
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
	ft_putnbr_fd(i, 1);
	return (digit_counter(i));
}

int	print_str(char *str)
{
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
	{
		// write pointer
	}
	else if (c == 'i' || c == 'd')
	{
		return (print_int(va_arg(args, int)));
	}
	else if (c == 'u')
	{
		return (putuint(va_arg(args, unsigned int)));
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
	return (0);
}

int	ft_printf(const char *input, ...)
{
	int		i;
	int		char_count;
	char	*str;
	va_list	args;

	if (!input)
		return (0);
	va_start(args, input);
	str = ft_strdup(input);
	char_count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			char_count += fsid(str[++i], args);
		else
		{
			write(1, &str[i], 1);
			char_count++;
		}
		i++;
	}
	va_end(args);
	free(str);
	return (char_count);
}

int	main(void)
{
	char	*str = "hola %c %s %i";
	char	*substr = "mundo";
	char	c = '4';
	int		i = 654654654;
	unsigned int	u = 6546546543

	int r = ft_printf(str, c, substr, i);
	printf("\n\nresult = %d", r);
	return (0);
}
