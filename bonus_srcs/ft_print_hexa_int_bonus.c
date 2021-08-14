/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_int_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raida <raida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 14:16:54 by raida             #+#    #+#             */
/*   Updated: 2021/07/10 14:16:59 by raida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

size_t	ft_numlen_hexa(unsigned int num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		len = 1;
	while (num > 0)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

char	*ft_dtoh_hexa(unsigned int num, size_t len, char xorX)
{
	int		i;
	char	*hex;
	char	*put;

	i = 0;
	if (xorX == 'x')
		hex = "0123456789abcdef";
	if (xorX == 'X')
		hex = "0123456789ABCDEF";
	put = (char *)malloc(sizeof(char *) * (len + 1));
	if (!put)
		return (NULL);
	put[len] = '\0';
	while (0 < len--)
	{
		i = num % 16;
		num = num / 16;
		put[len] = hex[i];
	}
	return (put);
}

void	ft_check_left_hexa_int(t_print *tab, int len, char xorX)
{
	int	width;
	int	prc;

	width = tab->wdt;
	prc = tab->prc;
	if (prc != -1)
		tab->zero = 0;
	if (tab->shrp)
		width += -2;
	if (!tab->zero && !tab->dash)
		while (len < width && prc < width--)
			tab->tlen += write(1, " ", 1);
	if (tab->shrp)
	{
		if (xorX == 'x')
			tab->tlen += write(1, "0x", 2);
		if (xorX == 'X')
			tab->tlen += write(1, "0X", 2);
	}
	while ((tab->zero && !tab->dash && len < width--) \
			|| (0 <= prc && len < prc--))
		tab->tlen += write(1, "0", 1);
}

void	ft_check_right_hexa_int(t_print *tab, int len)
{
	int	width;
	int	prc;

	width = tab->wdt;
	prc = tab->prc;
	if (tab->shrp)
		width += -2;
	if (tab->dash)
		while (len < width && prc < width--)
			tab->tlen += write(1, " ", 1);
}

void	ft_print_hexa_int(t_print *tab, char xorX)
{
	unsigned int	num;
	size_t			len;
	char			*put;
	char			*tmp;

	num = va_arg(tab->args, unsigned int);
	if (num == 0 && tab->prc == 0)
	{
		while ((tab->wdt)--)
			tab->tlen += write(1, " ", 1);
		return ;
	}
	len = ft_numlen_hexa(num);
	put = ft_dtoh_hexa(num, len, xorX);
	ft_check_left_hexa_int(tab, len, xorX);
	tmp = put;
	while (*put)
		tab->tlen += write(1, &(*put++), 1);
	free(tmp);
	ft_check_right_hexa_int(tab, len);
}
