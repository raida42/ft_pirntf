/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsinged_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raida <raida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:47:22 by raida             #+#    #+#             */
/*   Updated: 2021/07/08 22:33:27 by raida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_check_left_unsigned_int(t_print *tab, int len)
{
	int	width;
	int	prc;

	width = tab->wdt;
	prc = tab->prc;
	if (prc != -1)
		tab->zero = 0;
	if (!tab->zero && !tab->dash)
		while (len < width && prc < width--)
			tab->tlen += write(1, " ", 1);
	while ((tab->zero && !tab->dash && len < width--) \
			|| (0 <= prc && len < prc--))
		tab->tlen += write(1, "0", 1);
}

void	ft_check_right_unsgnied_int(t_print *tab, int len)
{
	int	width;
	int	prc;

	width = tab->wdt;
	prc = tab->prc;
	if (tab->dash)
		while (len < width && prc < width--)
			tab->tlen += write(1, " ", 1);
}

void	ft_print_unsigned_int(t_print *tab)
{
	unsigned int	u;
	char			*put;
	char			*tmp;
	size_t			len;

	u = va_arg(tab->args, unsigned int);
	if (u == 0 && tab->prc == 0)
	{
		while ((tab->wdt)--)
			tab->tlen += write(1, " ", 1);
		return ;
	}
	put = ft_itoa(u);
	len = ft_strlen(put);
	ft_check_left_unsigned_int(tab, len);
	tmp = put;
	while (*put)
		tab->tlen += write(1, &(*put++), 1);
	free(tmp);
	ft_check_right_unsgnied_int(tab, len);
}
