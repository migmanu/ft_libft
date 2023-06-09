/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:04:00 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/06/09 18:50:57 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	fsid(char c, va_list args)
{
	if (c == 'c')
		write(1, &c, 1);
	if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	if (c == 'p')
		// write pointer
	if (c == 'd')
		// write decimal
	if (c == 'i')
	{
		printf("integer");
		ft_putnbr_fd(va_arg(args, int), 1);
	}
	if (c == 'u')
		// write unsigned decimal
	if (c == 'x')
		// write hexadecimal lowercase
	if (c == 'X')
		// write hexadecimal uppercase
	if (c == '%')
		write(1, "%", 1);
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
	char	*str = "hola %i";
	char	*substr = "mundo";
	char	c = '4';
	int		i = 654654654;

	ft_printf(str, i);
	return (0);
}
