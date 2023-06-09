/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:04:00 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/06/08 18:10:56 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

int	ft_printf(const char *input, ...)
{
	int		i;
	char	*str;
	va_list	args;

	if (!input)
		return (NULL);
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
			write(1, str[i], 1);
		}
		i++;
	}

	free(str);
	return (0);
}

int	main(void)
{
	return (0);
}
