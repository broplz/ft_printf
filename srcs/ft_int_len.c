/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:20:45 by hcherrie          #+#    #+#             */
/*   Updated: 2021/01/20 19:24:37 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t		ft_strlen(const char *str)
{
	const char	*s;

	s = str;
	while (*s)
		++s;
	return (s - str);
}

int			ft_x_ulen(unsigned int num)
{
	int		i;

	i = 1;
	while (num > 15)
	{
		num /= 16;
		i++;
	}
	return (i);
}

int			ft_p_ulen(unsigned long num)
{
	int		i;

	i = 1;
	while (num > 15)
	{
		num /= 16;
		i++;
	}
	return (i);
}

int			ft_int_ulen(unsigned long i)
{
	int len;

	len = 1;
	while (i /= 10)
		len++;
	return (len);
}

int			ft_int_len(long i)
{
	int len;

	len = 1;
	if (i < 0)
		len++;
	while (i /= 10)
		len++;
	return (len);
}
