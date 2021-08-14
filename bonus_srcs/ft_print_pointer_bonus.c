/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raida <raida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:13:40 by raida             #+#    #+#             */
/*   Updated: 2021/07/08 22:31:35 by raida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_bonus.h"

size_t	ft_numlen_pointer(unsigned long num)
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

char	*ft_dtoh_pointer(unsigned long num, size_t len)
{
	int		i;
	char	*hex;
	char	*put;

	i = 0;
	hex = "0123456789abcdef";
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

void	ft_check_left_pointer(t_print *tab, int len)
{
	int	width;
	int	prc;

	width = (tab->wdt) - 2;
	prc = tab->prc;
	if (prc != -1)
		tab->zero = 0;
	if (!tab->zero && !tab->dash)
		while (len < width && prc < width--)
			tab->tlen += write(1, " ", 1);
	tab->tlen += write(1, "0x", 2);
	while ((tab->zero && !tab->dash && 0 <= width && len < width--) \
			|| (0 <= prc && len < prc--))
		tab->tlen += write(1, "0", 1);
}

void	ft_check_right_pointer(t_print *tab, int len)
{
	int	width;
	int	prc;

	width = (tab->wdt) - 2;
	prc = tab->prc;
	if (tab->dash)
		while (len < width && prc < width--)
			tab->tlen += write(1, " ", 1);
}

void	ft_print_pointer(t_print *tab)
{
	unsigned long	p;
	char			*put;
	char			*tmp;
	size_t			len;

	p = (unsigned long)va_arg(tab->args, void *);
	if (p == 0 && tab->prc == 0)
	{
		while (!tab->dash && 2 < (tab->wdt)--)
			tab->tlen += write(1, " ", 1);
		tab->tlen += write(1, "0x", 2);
		while (tab->dash && 2 < (tab->wdt)--)
			tab->tlen += write(1, " ", 1);
		return ;
	}
	len = ft_numlen_pointer(p);
	put = ft_dtoh_pointer(p, len);
	ft_check_left_pointer(tab, len);
	tmp = put;
	while (*put)
		tab->tlen += write(1, &(*put++), 1);
	ft_check_right_pointer(tab, len);
	free(tmp);
}
