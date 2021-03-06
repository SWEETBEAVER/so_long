/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_auxiliares.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:10:03 by mmakboub          #+#    #+#             */
/*   Updated: 2022/05/19 00:37:50 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_putnbr(int nbr)
{
	long	n;

	n = nbr;
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	lencalculate(long int a)

{
	int	len;

	len = 0;
	if (a < 0)
	{
		a *= -1;
		len = 1;
	}
	while (a > 9)
	{
		a = a / 10;
		len++;
	}
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*p;
	long int	nbr;

	len = lencalculate(n);
	nbr = n;
	if (nbr < 0)
		nbr *= -1;
	p = malloc(sizeof(char) * len + 1);
	if (!p)
		return (NULL);
	p[len] = '\0';
	while (len--)
	{
		p[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (n < 0)
		p[0] = '-';
	return (p);
}