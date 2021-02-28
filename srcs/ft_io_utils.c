/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:20:53 by hcherrie          #+#    #+#             */
/*   Updated: 2021/01/20 19:25:59 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_u_putnbr(unsigned int n)
{
	if (n == 0)
		write(1, "0", 1);
	if (n < 0)
		ft_u_putnbr(-n);
	if (n >= 10)
	{
		ft_u_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else if (n < 10 && n > 0)
		ft_putchar(n + '0');
}

void	ft_putnbr(long n)
{
	if (n == 0)
		write(1, "0", 1);
	if (n < 0)
		ft_putnbr(-n);
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else if (n < 10 && n > 0)
		ft_putchar(n + '0');
}

t_tab	ft_putstr(const char **str, t_tab tab)
{
	int	i;

	i = 0;
	while (**str != '%' && **str && ++i)
		write(1, (*str)++, 1);
	tab.len += i;
	if (**str)
		(*str)++;
	return (tab);
}
