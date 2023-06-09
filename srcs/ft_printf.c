/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:04:00 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/06/09 16:15:48 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
/*
static void	fsid(char c, va_list args, int gf)
{
	if (c == 'c')
		write(1, &c, 1);
	if (c == 's')
		// write string
	if (c == 'p')
		// write pointer
	if (c == 'd')
		// write decimal
	if (c == 'i')
		// write integer base 10
	if (c == 'u')
		// write unsigned decimal
	if (c == 'x')
		// write hexadecimal lowercase
	if (c == 'X')
		// write hexadecimal uppercase
	if (c == '%')
		write(1, "%", 1);
}
*/
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
			// check format specifier
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
	return (0);
}
