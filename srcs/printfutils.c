/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:35:55 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/06/12 15:43:01 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	putuint(unsigned int n)
{
	int	i;

	if (n > 9)
	{
		putuint(n / 10);
		putuint(n % 10);
	}
	else
		ft_putchar_fd(n + '0', 1);
}
