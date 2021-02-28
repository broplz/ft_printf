/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:21:11 by hcherrie          #+#    #+#             */
/*   Updated: 2021/01/20 19:21:14 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_recursion_p(unsigned long num, t_tab tab)
{
	char	c;

	if (num > 15)
		ft_recursion_p(num / 16, tab);
	c = (num % 16) < 10 ? (num % 16) + '0' : (num % 16) + 'A' + 22;
	write(1, &c, 1);
}

void	ft_recursion_x(unsigned int num, t_tab tab)
{
	int		type;
	char	c;

	type = tab.type == 'x' ? 22 : -10;
	if (num > 15)
		ft_recursion_x(num / 16, tab);
	c = (num % 16) < 10 ? (num % 16) + '0' : (num % 16) + 'A' + type;
	write(1, &c, 1);
}
