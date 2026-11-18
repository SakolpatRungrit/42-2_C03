/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakrungr <sakrungr@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 02:31:33 by sakrungr          #+#    #+#             */
/*   Updated: 2026/11/19 02:03:24 by sakrungr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_veri_base(char *base)
{
	long	i;
	long	s_i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] <= 32 && base[i] >= 127)
			return (0);
		s_i = i + 1;
		while (base[s_i])
		{
			if (base[i] == base[s_i])
				return (0);
			s_i++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

void	ft_convert_base(long nbr, int lenght, char *base)
{
	if (nbr >= lenght)
	{
		ft_convert_base(nbr / lenght, lenght, base);
		ft_convert_base(nbr % lenght, lenght, base);
	}
	else
	{
		ft_putchar(base[nbr]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	base_val;

	base_val = ft_veri_base(base);
	if (base_val == 0)
	{
		return ;
	}
	if (nbr == -2147483648)
	{
		ft_putchar('-');
		ft_convert_base(2147483648, base_val, base);
		return ;
	}
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-');
	}
	if (nbr < base_val)
		ft_putchar(base[nbr]);
	if (nbr >= base_val)
	{
		ft_convert_base(nbr / base_val, base_val, base);
		ft_convert_base(nbr % base_val, base_val, base);
	}
}
